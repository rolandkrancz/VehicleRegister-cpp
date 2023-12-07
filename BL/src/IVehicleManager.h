#ifndef IVEHICLE_MANAGER_H
#define IVEHICLE_MANAGER_H

#include "VehicleEntity.h"

class IVehicleManager {
public:
    virtual ~IVehicleManager() = default;

    virtual void RegisterVehicle(const VehicleEntity vehicle) = 0;
    virtual VehicleEntity GetVehicleInfo(const std::string registrationNumber) = 0;
};

#endif // IVEHICLE_MANAGER_H
