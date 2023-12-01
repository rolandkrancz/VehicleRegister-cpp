#ifndef BUSINESS_LOGIC_H
#define BUSINESS_LOGIC_H

#include "VehicleEntity.h"
#include "IStorage.h"
#include "IVehicleManager.h"

class VehicleBL : public IVehicleManager {
private:
    IStorage* storage;

public:
    VehicleBL(IStorage* storage);
    void RegisterVehicle(VehicleEntity VehicleEntity);
    VehicleEntity GetVehicleInfo(std::string registrationNumber);
};

#endif // BUSINESS_LOGIC_H
