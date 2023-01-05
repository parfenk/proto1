#pragma once

#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UCLASS(Abstract)
class GAME_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	//~ Begin APawn Interface.
	virtual FRotator GetViewRotation() const override;
	//~ End APawn Interface
};
