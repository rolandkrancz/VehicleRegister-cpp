#pragma once

#include "ext/json.hpp"
#include "VehicleEntity.h"

using json = nlohmann::json;

class Converter {
public:
    static VehicleEntity JsonToVehicleEntity(const json input);
    static json VehicleEntityToJson(const VehicleEntity input);
};