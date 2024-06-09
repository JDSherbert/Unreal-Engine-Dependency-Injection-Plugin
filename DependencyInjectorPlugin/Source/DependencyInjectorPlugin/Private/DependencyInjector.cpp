// ©2024 JDSherbert. All Rights Reserved.

#include "DependencyInjector.h"

/* ------------------------------------------------------------ */

UDependencyInjector* UDependencyInjector::Instance = nullptr;

/* ------------------------------------------------------------ */

void UDependencyInjector::RegisterObject(UObject* InjectionObject)
{
    if (!Instance)
    {
        // Create the singleton instance if it doesn't exist
        Instance = NewObject<UDependencyInjector>();
    }

    const UClass* ObjectClass = InjectionObject->GetClass();
    Instance->RegisteredObjects.FindOrAdd(ObjectClass).Add(InjectionObject);
}

/* ------------------------------------------------------------ */

void UDependencyInjector::UnregisterObject(UObject* InjectionObject)
{
    if (!Instance)
    {
        // The instance doesn't exist, so nothing to unregister
        return;
    }

    const UClass* ObjectClass = InjectionObject->GetClass();
    if (TArray<UObject*>* Objects = Instance->RegisteredObjects.Find(ObjectClass))
    {
        Objects->Remove(InjectionObject);
    }
}

/* ------------------------------------------------------------ */

template<class T>
T* UDependencyInjector::GetRegisteredObject()
{
    if (!Instance)
    {
        // The instance doesn't exist, so no objects are registered
        return nullptr;
    }

    const UClass* ObjectClass = T::StaticClass();
    if (TArray<UObject*>* Objects = Instance->RegisteredObjects.Find(ObjectClass))
    {
        if (Objects->Num() > 0)
        {
            return Cast<T>((*ObjectArray)[0]); // Return the first registered object of the specified class
        }
    }

    return nullptr;
}

/* ------------------------------------------------------------ */
