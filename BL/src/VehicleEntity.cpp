#include "VehicleEntity.h"

VehicleEntity::VehicleEntity()
    : registration_number(""), model(""), vehicle_type(""), owner_name(""), owner_address(""){}

VehicleEntity::VehicleEntity(std::string reg_number, std::string mdl, std::string type, std::string name, std::string address)
    :   registration_number(reg_number), 
        model(mdl),
        vehicle_type(type),
        owner_name(name),
        owner_address(address) {}

std::string VehicleEntity::GetRegistrationNumber() const {
    return registration_number; 
}

std::string VehicleEntity::GetModel() const {
    return model;
}

std::string VehicleEntity::GetVehicleType() const {
    return vehicle_type;
}

std::string VehicleEntity::GetOwnerName() const {
    return owner_name;
}

std::string VehicleEntity::GetOwnerAddress() const {
    return owner_address;
}
