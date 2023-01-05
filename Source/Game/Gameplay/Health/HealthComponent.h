#pragma once

#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

UCLASS(Meta=(BlueprintSpawnableComponent))
class GAME_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UHealthComponent();

	//~ Begin UObject Interface.
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	//~ End UObject Interface

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDied, AActor*, DiedActor);
	UPROPERTY(BlueprintAssignable)
	FDied Died;

	UFUNCTION(Category=Health, BlueprintCallable, BlueprintAuthorityOnly)
	void Die();
	UFUNCTION(Category=Health, BlueprintCallable)
	bool IsDead() const { return bDead; }

protected:
	UFUNCTION()
	void OnRep_bDead();

private:
	UPROPERTY(ReplicatedUsing=OnRep_bDead)
	bool bDead { false };
};
