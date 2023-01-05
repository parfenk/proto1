#include "CharacterBase.h"

FRotator ACharacterBase::GetViewRotation() const
{
	if (auto PlayerController = GetWorld() -> GetFirstPlayerController())
	{
		return PlayerController->GetControlRotation();
	}
	else
	{
		return Super::GetViewRotation();
	}
}
