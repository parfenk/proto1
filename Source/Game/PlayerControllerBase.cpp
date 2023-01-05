#include "PlayerControllerBase.h"

APlayerControllerBase::APlayerControllerBase()
{
	NetUpdateFrequency = .1f;
}

void APlayerControllerBase::AcknowledgePossession(APawn* NewPawn)
{
	Super::AcknowledgePossession(NewPawn);
	ReceiveAcknowledgePossession(NewPawn);
}
