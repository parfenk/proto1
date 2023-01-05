#pragma once

#include "Modules/ModuleManager.h"

class FUtilsModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
