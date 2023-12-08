#ifndef BUSINESS_LOGIC_H
#define BUSINESS_LOGIC_H

#include "VehicleEntity.h"
#include "IStorage.h"
#include "IVehicleManager.h"

class VehicleBL : public IVehicleManager {      // Interactor
private:
    IStorage* storage;

public:
    VehicleBL(IStorage* storage);
    void RegisterVehicle(const json vehicle);
    json GetVehicleInfo(const std::string registrationNumber);

private:
    static VehicleEntity JsonToVehicleEntity(const json vehicle);
    static json VehicleEntityToJson(const VehicleEntity vehicle);
};

#endif // BUSINESS_LOGIC_H
