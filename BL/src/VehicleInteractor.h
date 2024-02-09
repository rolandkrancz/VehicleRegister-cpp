#pragma once

#ifdef DLL_EXPORT
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif

#include "VehicleEntity.h"
#include "IStorage.h"
#include "IVehicleManager.h"
#include "IPresenterApi.h"

class DLL_EXPORT VehicleInteractor : public IVehicleManager {
private:
    IStorage* storage;
    IPresenterApi* presenter;

public:
    VehicleInteractor(IStorage* storage, IPresenterApi* presenter);
    void RegisterVehicle(const json request);
    void GetVehicleInfo(const json request);
};