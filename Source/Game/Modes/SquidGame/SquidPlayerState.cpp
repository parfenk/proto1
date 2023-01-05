#include "SquidPlayerState.h"
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
