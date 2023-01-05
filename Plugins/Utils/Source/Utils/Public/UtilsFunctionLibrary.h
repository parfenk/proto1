#pragma once

#include "NetTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UtilsFunctionLibrary.generated.h"

UCLASS()
class UTILS_API UUtilsFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static UWorld* GetCurrentPlayWorld();
};

typedef UUtilsFunctionLibrary Utils;
