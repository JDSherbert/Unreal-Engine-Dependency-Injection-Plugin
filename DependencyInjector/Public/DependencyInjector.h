// ©2024 JDSherbert. All Rights Reserved.

#pragma once

#include <Runtime/Core/Public/CoreMinimal.h>

#include <Runtime/Core/UObject/NoExportTypes.h>

#include "DependencyInjector.generated.h"

/* ------------------------------ Class Definition ------------------------------- */

/**
* Dependency Injection Class. Performs behaviors related to DI.
* Register the objects/services and then populate clients with those service/object instances.
* @since 09/01/2024
* @author JDSherbert
*/
UCLASS()
class SHERBERT_API UDependencyInjector : public UObject
{
    GENERATED_BODY()

private:

    // Private constructor due to singleton shenanigans (instantiated automatically when the Register function gets called/used)
    UDependencyInjector();

public:

    /** 
    * Get Injector Singleton instance.
	* @return UDependencyInjector* : Returns the singleton instance of this class, if it exists.
	* @since 09/01/2024
	* @author JDSherbert
    */
    UFUNCTION(BlueprintCallable, Category = "Sherbert|Dependency Injector")
    FORCEINLINE static UDependencyInjector* GetInjectorInstance() { return Instance; }
    
    /** 
    * Register an object with the Dependency Injector.
    * @param InjectionObject : The object to add to the Injector.
	* @since 09/01/2024
	* @author JDSherbert
    */
    template<class T>
    UFUNCTION(BlueprintCallable, Category = "Sherbert|Dependency Injector")
    static void RegisterObject(T* InjectionObject);

    /** 
    * Unregister an object with the Dependency Injector.
    * @param InjectionObject : The object to remove from the Injector.
	* @since 09/01/2024
	* @author JDSherbert
    */
    template<class T>
    UFUNCTION(BlueprintCallable, Category = "Sherbert|Dependency Injector")
    static void UnregisterObject(T* InjectionObject);

    /** 
    * Get an object of a specific class that is registered with the Dependency Injector.
    * @return T* : Returns a copy of a registered object based on type.
	* @since 09/01/2024
	* @author JDSherbert
    */
    template<class T>
    UFUNCTION(BlueprintCallable, Category = "Sherbert|Dependency Injector")
    static T* GetRegisteredObject();

private:

    /** Map to store registered objects. */
    UPROPERTY(Category = "Sherbert|Dependency Injector")
    TMap<const UClass*, TArray<UObject*>> RegisteredObjects;

    // Singleton instance
    static UDependencyInjector* Instance;
};

/* ------------------------------------------------------------------------------- */
