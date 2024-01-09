// ©2024 JDSherbert. All Rights Reserved.

using UnrealBuildTool; 

public class DependencyInjectorModule : ModuleRules
{ 
    public DependencyInjectorModule(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivateDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine"});
    } 
}

// Don't forget to add this module to your:
// - MyProject.uproject module dependency list (In the project Root)
// AND
// - MyProject.Build.cs file module dependency list (Should be in Source/MyProject/MyProject.Build.cs)
