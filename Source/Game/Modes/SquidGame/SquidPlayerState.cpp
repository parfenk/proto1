#include "SquidPlayerState.h"
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
