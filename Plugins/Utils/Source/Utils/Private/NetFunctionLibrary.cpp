#include "NetFunctionLibrary.h"
#include "UtilsFunctionLibrary.h"
#include "GameFramework/GameStateBase.h"

float UNetFunctionLibrary::TimeNow()
{
	if (auto World = Utils::GetCurrentPlayWorld())
	{
		if (auto GameState = World->GetGameState())
		{
			return GameState->GetServerWorldTimeSeconds();
		}
	}

	return 0.f;
}

float UNetFunctionLibrary::TimeFromNow(float Seconds)
{
	return TimeNow() + Seconds;
}
