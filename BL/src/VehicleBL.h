#pragma once

#include "VehicleEntity.h"
#include "IStorage.h"
#include "IVehicleManager.h"

class VehicleBL : public IVehicleManager {      // Interactor
private:
    IStorage* storage;

public:
    VehicleBL(IStorage* storage);
    void RegisterVehicle(const json vehicle);
    json GetVehicleInfo(const json request);

private:    // extract to helper / converter class
    static VehicleEntity JsonToVehicleEntity(const json vehicle);
    static json VehicleEntityToJson(const VehicleEntity vehicle);
};