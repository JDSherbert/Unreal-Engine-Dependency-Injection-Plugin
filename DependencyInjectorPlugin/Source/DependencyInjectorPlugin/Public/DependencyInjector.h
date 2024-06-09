// ©2024 JDSherbert. All Rights Reserved.

#pragma once

#include <Runtime/Core/Public/CoreMinimal.h>

#include <Runtime/Core/UObject/NoExportTypes.h>

#include "DependencyInjector.generated.h"

/* ------------------------------------------------------------ */

/**
* Dependency Injection Class. Performs behaviors related to DI.
* Register the objects/services and then populate clients with those service/object instances.
* 
* @since Unreal Engine 5.2
* @author JDSherbert
*/
UCLASS()
class DEPENDENCYINJECTORPLUGIN_API UDependencyInjector : public UObject
{
    GENERATED_BODY()

private:

    // Private constructor due to singleton shenanigans (instantiated automatically when the Register function gets called/used)
    UDependencyInjector();

public:

    /** 
    * Get Injector Singleton instance.
    * 
	* @return UDependencyInjector* : Returns the singleton instance of this class, if it exists.
    * 
	* @since Unreal Engine 5.2
	* @author JDSherbert
    */
    UFUNCTION(BlueprintCallable, Category = "Dependency Injector")
    FORCEINLINE static UDependencyInjector* GetInjectorInstance() { return Instance; }
    
    /** 
    * Register an object with the Dependency Injector.
    * 
    * @param InjectionObject : The object to add to the Injector.
    * 
	* @since Unreal Engine 5.2
	* @author JDSherbert
    */
    template<class T>
    UFUNCTION(BlueprintCallable, Category = "Dependency Injector")
    static void RegisterObject(T* InjectionObject);

    /** 
    * Unregister an object with the Dependency Injector.
    * 
    * @param InjectionObject : The object to remove from the Injector.
    * 
	* @since Unreal Engine 5.2
	* @author JDSherbert
    */
    template<class T>
    UFUNCTION(BlueprintCallable, Category = "Dependency Injector")
    static void UnregisterObject(T* InjectionObject);

    /** 
    * Get an object of a specific class that is registered with the Dependency Injector.
    * 
    * @return T* : Returns a copy of a registered object based on type.
    * 
	* @since Unreal Engine 5.2
	* @author JDSherbert
    */
    template<class T>
    UFUNCTION(BlueprintCallable, Category = "Dependency Injector")
    static T* GetRegisteredObject();

private:

    /** Map to store registered objects. */
    UPROPERTY(Category = "Dependency Injector")
    TMap<const UClass*, TArray<UObject*>> RegisteredObjects;

    // Singleton instance
    static UDependencyInjector* Instance;
};

/* ------------------------------------------------------------ */
