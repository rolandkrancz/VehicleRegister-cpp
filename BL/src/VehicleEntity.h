#pragma once

#include <string>

typedef struct VehicleEntity {
    std::string registration_number;
    std::string model;
    std::string vehicle_type;
    std::string owner_name;
    std::string owner_address;
} VehicleEntity;