#include "HealthComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Net/UnrealNetwork.h" 	

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bStartWithTickEnabled = false;
	SetIsReplicatedByDefault(true);
}

void UHealthComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UHealthComponent, bDead);
}

void UHealthComponent::Die()
{
	if (bDead)
	{
		return;
	}

	if (auto MovementComponent = GetOwner()->FindComponentByClass<UCharacterMovementComponent>())
	{
		MovementComponent->SetMovementMode(EMovementMode::MOVE_None);
	}

	bDead = true;
	OnRep_bDead();
}

void UHealthComponent::OnRep_bDead()
{
	if (bDead)
	{
		Died.Broadcast(GetOwner());
	}
}
