#pragma once

#include "GameFramework/Actor.h"
#include "Doll.generated.h"

UCLASS(Abstract)
class GAME_API ADoll : public AActor
{
	GENERATED_BODY()

public:
	ADoll();

	//~ Begin UObject Interface.
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	//~ End UObject Interface

	UFUNCTION(Category=Doll, BlueprintCallable, BlueprintAuthorityOnly)
	void SetRotationSpeed(float NewRotationSpeed);
	UFUNCTION(Category=Doll, BlueprintCallable, BlueprintAuthorityOnly)
	void SetIsWatching(bool bNewWatching);
	UFUNCTION(Category=Doll, BlueprintCallable)
	bool IsWatching() const { return bWatching; }
	
	UFUNCTION(Category=Doll, BlueprintCallable)
	float GetRotationSpeed() const { return RotationSpeed; }

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWatchingStateChanged, bool, bNewWatching);
	UPROPERTY(BlueprintAssignable)
	FWatchingStateChanged WatchingStateChanged;

protected:
	UFUNCTION()
	void OnRep_bWatching();

private:
	UPROPERTY(Replicated)
	float RotationSpeed { 60.f };
	UPROPERTY(ReplicatedUsing=OnRep_bWatching)
	bool bWatching { false };
};
