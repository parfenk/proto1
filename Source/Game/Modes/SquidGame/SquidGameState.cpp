#include "SquidGameState.h"
#include "SquidPlayerState.h"
#include "NetFunctionLibrary.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/GameMode.h"
#include "Kismet/KismetMathLibrary.h"

ASquidGameState::ASquidGameState()
{
	NetUpdateFrequency = 1.f;
}

void ASquidGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASquidGameState, bAllowMovement);
	DOREPLIFETIME(ASquidGameState, GameStartedAt);
	DOREPLIFETIME(ASquidGameState, GameEndAt);
}

void ASquidGameState::OnRep_MatchState()
{
	Super::OnRep_MatchState();

	if (MatchState == MatchState::Aborted ||
		MatchState == MatchState::LeavingMap ||
		MatchState == MatchState::WaitingPostMatch)
	{
		GameEnded.Broadcast();
	}
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

int32 ASquidGameState::GetNumPlayersCrossedFinishLine() const
{
	int32 Num = 0;

	for (auto PlayerState : GetPlayerArray<ASquidPlayerState>())
	{
		if (PlayerState->IsFinishLineCrossed())
		{
			Num++;
		}
	}

	return Num;
}
