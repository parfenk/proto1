#pragma once

#include "GameFramework/GameMode.h"
#include "SquidGameMode.generated.h"

UCLASS()
class GAME_API ASquidGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ASquidGameMode();

	//~ Begin AGameModeBase Interface.
	virtual void InitGameState() override;
	virtual void HandleMatchHasStarted() override;
	//~ End AGameModeBase Interface

	//~ Begin AGameMode Interface.
	virtual bool ReadyToStartMatch_Implementation() override;
	virtual bool ReadyToEndMatch_Implementation() override;
	//~ End AGameMode Interface

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void MatchHasStarted();

private:
	UPROPERTY(Category=GameMode, EditDefaultsOnly)
	int32 MinPlayerCount { 1 };
	UPROPERTY(Category=GameMode, EditDefaultsOnly, BlueprintReadOnly, Meta=(AllowPrivateAccess))
	float StartDelayAfterAllPlayersConnected { 5.f };
	UPROPERTY(Category=GameMode, EditDefaultsOnly, BlueprintReadOnly, Meta=(AllowPrivateAccess))
	float GameDuration { 60.f };

	UPROPERTY()
	TObjectPtr<class ASquidGameState> SquidGameState;
};
