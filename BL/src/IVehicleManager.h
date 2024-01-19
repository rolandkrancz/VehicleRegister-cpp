#pragma once

#include "VehicleEntity.h"
#include "ext/json.hpp"
#include <string>

using json = nlohmann::json;

class IVehicleManager {
public:
    
    virtual void RegisterVehicle(const json vehicle) = 0;
    virtual void GetVehicleInfo(const json request) = 0;
};