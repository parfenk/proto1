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

	//~ Begin AGameState Interface.
	virtual void OnRep_MatchState() override;
	//~ End AGameState Interface

	template<typename Type>
	TArray<Type*> GetPlayerArray() const
	{
		TArray<Type*> Array;

		for (auto PlayerState : PlayerArray)
		{
			Array.Add(Cast<Type>(PlayerState));
		}

		return Array;
	}

	UFUNCTION(Category=GameState, BlueprintCallable, BlueprintAuthorityOnly)
	void SetMovementIsAllowed(bool bNewAllowMovement);
	UFUNCTION(Category=GameState, BlueprintCallable)
	bool IsMovementAllowed() const { return bAllowMovement; }
	
	UFUNCTION(Category=GameState, BlueprintCallable)
	float GetGameStartedAt() const { return GameStartedAt; }
	UFUNCTION(Category=GameState, BlueprintCallable)
	float GetGameEndAt() const { return GameEndAt; }

	UFUNCTION(Category=GameState, BlueprintCallable, BlueprintAuthorityOnly)
	void SetGameDuration(float DelayBeforeStart, float Duration);

	UFUNCTION(Category=GameState, BlueprintCallable)
	int32 GetNumPlayersCrossedFinishLine() const;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMovementPermitChanged, bool, bAllowMovement);
	UPROPERTY(BlueprintAssignable)
	FMovementPermitChanged MovementPermitChanged;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameEnded);
	UPROPERTY(BlueprintAssignable)
	FGameEnded GameEnded;

protected:
	UFUNCTION()
	void OnRep_bAllowMovement();

private:
	UPROPERTY(ReplicatedUsing=OnRep_bAllowMovement)
	bool bAllowMovement { true };
	UPROPERTY(Replicated)
	float GameStartedAt;
	UPROPERTY(Replicated)
	float GameEndAt;
};
