#include "Converter.h"

VehicleEntity Converter::JsonToVehicleEntity(const json input)
{
    VehicleEntity output = {};

    output.registration_number = input["registration_number"].get<std::string>();
    output.model = input["model"].get<std::string>();
    output.vehicle_type = input["vehicle_type"].get<std::string>();
    output.owner_name = input["owner_name"].get<std::string>();
    output.owner_address = input["owner_address"].get<std::string>();
    
    return output;
}

json Converter::VehicleEntityToJson(VehicleEntity input)
{
    json output = {};

    output["registration_number"] = input.registration_number;
    output["model"] = input.model;
    output["vehicle_type"] = input.vehicle_type;
    output["owner_name"] = input.owner_name;
    output["owner_address"] = input.owner_address;

    return output;
}

std::string Converter::GetRegistrationNumber(const json input)
{
    return input["registration_number"].get<std::string>();
}
