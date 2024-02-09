#pragma once

#if defined(DLL_EXPORT)
#define DLL __declspec(dllexport)
#elif defined(DLL_IMPORT)
#define DLL __declspec(dllimport)
#else
#define DLL
#endif

#include "VehicleEntity.h"
#include "IStorage.h"
#include "IVehicleManager.h"
#include "IPresenterApi.h"

class DLL VehicleInteractor : public IVehicleManager {
private:
    IStorage* storage;
    IPresenterApi* presenter;

public:
    VehicleInteractor(IStorage* storage, IPresenterApi* presenter);
    void RegisterVehicle(const json request);
    void GetVehicleInfo(const json request);
};