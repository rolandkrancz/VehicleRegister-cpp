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
    void RegisterVehicle(const json vehicle);
    void GetVehicleInfo(const json request);

private:    // extract to helper / converter class
    static VehicleEntity JsonToVehicleEntity(const json vehicle);
    static json VehicleEntityToJson(const VehicleEntity vehicle);
};