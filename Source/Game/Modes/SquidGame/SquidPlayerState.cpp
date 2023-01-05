#include "SquidPlayerState.h"
#include "SquidGameState.h"
#include "NetFunctionLibrary.h"
#include "Gameplay/Health/HealthComponent.h"
#include "Net/UnrealNetwork.h"

ASquidPlayerState::ASquidPlayerState()
{
	NetUpdateFrequency = .1f;
}

void ASquidPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASquidPlayerState, Place);
	DOREPLIFETIME(ASquidPlayerState, DiedAt);
}

void ASquidPlayerState::BeginPlay()
{
	Super::BeginPlay();

	BindPawnDied();
	OnPawnSet.AddDynamic(this, &ASquidPlayerState::PawnSet);
}

void ASquidPlayerState::PawnSet(APlayerState* Player, APawn* NewPawn, APawn* OldPawn)
{
	BindPawnDied();
}

void ASquidPlayerState::BindPawnDied()
{
	if (HasAuthority() && GetPawn())
	{
		if (auto HealthComponent = GetPawn()->FindComponentByClass<UHealthComponent>())
		{
			HealthComponent->Died.AddDynamic(this, &ASquidPlayerState::PawnDied);
		}
	}
}

bool ASquidPlayerState::IsDead() const
{
	if (auto Pawn = GetPawn())
	{
		if (auto HealthComponent = Pawn->FindComponentByClass<UHealthComponent>())
		{
			return HealthComponent->IsDead();
		}
	}

	return true;
}

void ASquidPlayerState::PawnDied(AActor* DiedOwner)
{
	DiedAt = Net::TimeNow();
	ForceNetUpdate();
}

void ASquidPlayerState::RememberTransform()
{
	if (auto Pawn = GetPawn())
	{
		LastAllowedToMoveTransform = Pawn->GetActorTransform();
	}
}

void ASquidPlayerState::SetPlace(int32 NewPlace)
{
	if (IsFinishLineCrossed())
	{
		return;
	}

	Place = NewPlace;
	OnRep_Place();
}

void ASquidPlayerState::OnRep_Place()
{
	if (IsFinishLineCrossed())
	{
		FinishLineCrossed.Broadcast(Place);
	}
}

float ASquidPlayerState::GetLifetime() const
{
	if (auto GameState = GetWorld()->GetGameState<ASquidGameState>())
	{
		return FMath::Max(DiedAt - GameState->GetGameStartedAt(), 0.f);
	}

	return 0.f;
}
