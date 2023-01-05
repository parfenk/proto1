#pragma once

#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"

UCLASS()
class GAME_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:
	APlayerControllerBase();

	//~ Begin APlayerController Interface.
	virtual void AcknowledgePossession(APawn* NewPawn) override;
	//~ End APlayerController Interface

protected:
	UFUNCTION(Category=PlayerController, BlueprintImplementableEvent, Meta=(DisplayName="Acknowledge Possession"))
	void ReceiveAcknowledgePossession(APawn* NewPawn);
};
