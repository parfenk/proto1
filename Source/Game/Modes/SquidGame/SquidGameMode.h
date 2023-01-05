#pragma once

#include "GameFramework/GameMode.h"
#include "SquidGameMode.generated.h"

UCLASS()
class GAME_API AClassicGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AClassicGameMode();

	//~ Begin AGameModeBase Interface.
	virtual void InitGameState() override;
	//~ End AGameModeBase Interface

private:
	UPROPERTY()
	TObjectPtr<class ASquidGameState> SquidGameState;
};
