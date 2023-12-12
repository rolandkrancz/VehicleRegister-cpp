#pragma once

#include <string>

class VehicleEntity {
private:
    std::string registration_number;
    std::string model;
    std::string vehicle_type;
    std::string owner_name;
    std::string owner_address;

public:
    VehicleEntity();
    VehicleEntity(std::string reg_number, std::string mdl, std::string type, std::string name, std::string address);
    std::string GetRegistrationNumber() const;
    std::string GetModel() const;
    std::string GetVehicleType() const;
    std::string GetOwnerName() const;
    std::string GetOwnerAddress() const;
};