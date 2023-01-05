#include "Doll.h"
#include "Net/UnrealNetwork.h" 	

ADoll::ADoll()
{
	NetUpdateFrequency = 1.f;
	// bReplicates = true;
}

void ADoll::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADoll, RotationSpeed);
	DOREPLIFETIME(ADoll, bWatching);
}

void ADoll::SetRotationSpeed(float NewRotationSpeed)
{
	RotationSpeed = NewRotationSpeed;
}

void ADoll::SetIsWatching(bool bNewWatching)
{
	bWatching = bNewWatching;
}
