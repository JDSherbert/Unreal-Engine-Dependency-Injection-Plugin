// ©2024 JDSherbert. All rights reserved.

#pragma once

#include <Runtime/Core/Public/CoreMinimal.h>

#include <Runtime/Core/Public/Modules/ModuleManager.h>

/* ------------------------------------------------------------ */

class FDependencyInjectorPluginModule : public IModuleInterface
{

public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
};

/* ------------------------------------------------------------ */
