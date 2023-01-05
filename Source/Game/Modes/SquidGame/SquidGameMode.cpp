#include "SquidGameMode.h"
#include "SquidGameState.h"
#include "SquidPlayerState.h"

AClassicGameMode::AClassicGameMode()
{
	PrimaryActorTick.TickInterval = 1 / 10.f;

	GameStateClass = ASquidGameState::StaticClass();
	PlayerStateClass = ASquidPlayerState::StaticClass();
}

void AClassicGameMode::InitGameState()
{
	Super::InitGameState();

	SquidGameState = Cast<ASquidGameState>(GameState);
}
