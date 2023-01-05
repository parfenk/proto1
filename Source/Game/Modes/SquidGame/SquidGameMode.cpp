#include "SquidGameMode.h"
#include "SquidGameState.h"
#include "SquidPlayerState.h"

ASquidGameMode::ASquidGameMode()
{
	PrimaryActorTick.TickInterval = 1 / 10.f;

	GameStateClass = ASquidGameState::StaticClass();
	PlayerStateClass = ASquidPlayerState::StaticClass();
}

void ASquidGameMode::InitGameState()
{
	Super::InitGameState();

	SquidGameState = Cast<ASquidGameState>(GameState);
}

bool ASquidGameMode::ReadyToStartMatch_Implementation()
{
	return GameState->PlayerArray.Num() >= MinPlayerCount;
}

bool ASquidGameMode::ReadyToEndMatch_Implementation()
{
	for (auto PlayerState : SquidGameState->GetPlayerArray<ASquidPlayerState>())
	{
		if (!PlayerState->IsDead() && !PlayerState->IsFinishLineCrossed())
		{
			return false;
		}
	}

	return true;
}

void ASquidGameMode::HandleMatchHasStarted()
{
	MatchHasStarted();
}
