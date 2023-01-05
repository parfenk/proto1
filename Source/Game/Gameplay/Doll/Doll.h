#pragma once

#include "GameFramework/Actor.h"
#include "Doll.generated.h"

UCLASS(Abstract)
class GAME_API ADoll : public ADoll
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

private:
	UPROPERTY(Replicated)
	float RotationSpeed { 60.f };
	UPROPERTY(Replicated)
	bool bWatching { false };
};
