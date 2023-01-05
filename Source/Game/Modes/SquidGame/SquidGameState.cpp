#include "SquidGameState.h"
#include "SquidPlayerState.h"
#include "NetFunctionLibrary.h"
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
	DOREPLIFETIME(ASquidGameState, GameStartedAt);
	DOREPLIFETIME(ASquidGameState, GameEndAt);
}

void ASquidGameState::SetGameDuration(float DelayBeforeStart, float Duration)
{
	GameStartedAt = Net::TimeFromNow(DelayBeforeStart);
	GameEndAt = GameStartedAt + Duration;
}

void ASquidGameState::SetMovementIsAllowed(bool bNewAllowMovement)
{
	bAllowMovement = bNewAllowMovement;
	OnRep_bAllowMovement();
}

void ASquidGameState::OnRep_bAllowMovement()
{
	MovementPermitChanged.Broadcast(bAllowMovement);
}
