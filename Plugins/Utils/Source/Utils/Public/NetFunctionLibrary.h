#pragma once

#include "NetTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NetFunctionLibrary.generated.h"

UCLASS()
class UTILS_API UNetFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(Category=Net, BlueprintPure, Meta=(CompactNodeTitle="Time Now"))
	static float TimeNow();
	UFUNCTION(Category=Net, BlueprintPure, Meta=(DisplayName="Time from Now"))
	static float TimeFromNow(float Seconds);
};

typedef UNetFunctionLibrary Net;
