#include "UtilsFunctionLibrary.h"

UWorld* UUtilsFunctionLibrary::GetCurrentPlayWorld()
{
	if (GEngine)
	{
		return GEngine->GetCurrentPlayWorld();
	}

	return nullptr;
}
