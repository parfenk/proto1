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
	UFUNCTION(Category=PlayerState, BlueprintCallable, BlueprintAuthorityOnly)
	void SetPlace(int32 NewPlace);
	UFUNCTION(Category=PlayerState, BlueprintCallable)
	bool IsFinishLineCrossed() const { return Place != INDEX_NONE; }
	UFUNCTION(Category=PlayerState, BlueprintCallable)
	bool IsDead() const;

	UFUNCTION(Category=PlayerState, BlueprintCallable, BlueprintAuthorityOnly)
	void RememberTransform();
	UFUNCTION(Category=PlayerState, BlueprintCallable, BlueprintAuthorityOnly)
	const FTransform& GetLastAllowedToMoveTransform() const { return LastAllowedToMoveTransform; }

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFinishLineCrossed, int32, Place);
	UPROPERTY(BlueprintAssignable)
	FFinishLineCrossed FinishLineCrossed;

protected:
	UFUNCTION()
	void OnRep_Place();

private:
	UPROPERTY(ReplicatedUsing=OnRep_Place)
	int32 Place { INDEX_NONE };

	FTransform LastAllowedToMoveTransform;
};
