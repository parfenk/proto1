#pragma once

#include "GameFramework/PlayerState.h"
#include "SquidPlayerState.generated.h"

UCLASS()
class GAME_API ASquidPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ASquidPlayerState();

	//~ Begin UObject Interface.
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	//~ End UObject Interface

	UFUNCTION(Category=PlayerState, BlueprintCallable)
	int32 GetPlace() const { return Place; }

private:
	UPROPERTY(Replicated)
	int32 Place { 0 };
};
