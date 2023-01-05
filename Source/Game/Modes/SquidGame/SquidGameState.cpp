#include "SquidGameState.h"
#include "SquidPlayerState.h"
#include "Net/UnrealNetwork.h" 	
#include "Kismet/KismetMathLibrary.h"

ASquidGameState::ASquidGameState()
{
	NetUpdateFrequency = .1f;
}

void ASquidGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASquidGameState, bAllowMovement);
}
