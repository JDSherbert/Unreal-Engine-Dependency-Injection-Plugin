using UnrealBuildTool; 

public class DependencyInjectorModule : ModuleRules
{ 
    public DependencyInjectorModule(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivateDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine"});
    } 
}
