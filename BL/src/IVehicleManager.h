#ifndef IVEHICLE_MANAGER_H
#define IVEHICLE_MANAGER_H

#include "VehicleEntity.h"
#include "ext/json.hpp"

using json = nlohmann::json;

class IVehicleManager {
public:
    virtual ~IVehicleManager() = default;

    virtual void RegisterVehicle(const json vehicle) = 0;
    virtual json GetVehicleInfo(const std::string registrationNumber) = 0;
};

#endif // IVEHICLE_MANAGER_H
