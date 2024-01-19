#pragma once

#include "VehicleEntity.h"
#include "IStorage.h"
#include "IVehicleManager.h"
#include "IPresenterApi.h"

class VehicleInteractor : public IVehicleManager {
private:
    IStorage* storage;
    IPresenterApi* presenter;

public:
    VehicleInteractor(IStorage* storage, IPresenterApi* presenter);
    void RegisterVehicle(const json request);
    void GetVehicleInfo(const json request);
};