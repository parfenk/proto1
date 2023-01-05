#include "Doll.h"
#include "Net/UnrealNetwork.h" 	

ADoll::ADoll()
{
	NetUpdateFrequency = 1.f;
	bReplicates = true;
}

void ADoll::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADoll, RotationSpeed);
	DOREPLIFETIME(ADoll, bWatching);
}

void ADoll::OnRep_bWatching()
{
	WatchingStateChanged.Broadcast(bWatching);
}

void ADoll::SetRotationSpeed(float NewRotationSpeed)
{
	RotationSpeed = NewRotationSpeed;
}

void ADoll::SetIsWatching(bool bNewWatching)
{
	if (bWatching == bNewWatching)
	{
		return;
	}

	bWatching = bNewWatching;
	OnRep_bWatching();
}
