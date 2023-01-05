#pragma once

#include "GameFramework/GameState.h"
#include "SquidGameState.generated.h"

UCLASS()
class GAME_API ASquidGameState : public AGameState
{
	GENERATED_BODY()

public:
	ASquidGameState();

	//~ Begin UObject Interface.
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	//~ End UObject Interface

	UFUNCTION(Category=GameState, BlueprintCallable)
	bool IsMovementAllowed() const { return bAllowMovement; }

private:
	UPROPERTY(Replicated)
	bool bAllowMovement { true };
};
