#ifndef IVEHICLE_MANAGER_H
#define IVEHICLE_MANAGER_H

#include "VehicleEntity.h"
#include "ext/json.hpp"
#include <string>

using json = nlohmann::json;

class IVehicleManager {
public:
    
    virtual void RegisterVehicle(const json vehicle) = 0;
    virtual json GetVehicleInfo(const json request) = 0; // TODO async
};

#endif // IVEHICLE_MANAGER_H
