#include "Converter.h"

VehicleEntity Converter::JsonToVehicleEntity(const json input)
{
    VehicleEntity output = {};

    output.registrationNumber = input["registrationNumber"].get<std::string>();
    output.model = input["model"].get<std::string>();
    output.vehicleType = input["vehicleType"].get<std::string>();
    output.firstName = input["firstName"].get<std::string>();
    output.address = input["address"].get<std::string>();
    
    return output;
}

json Converter::VehicleEntityToJson(VehicleEntity input)
{
    json output = {};

    output["registrationNumber"] = input.registrationNumber;
    output["model"] = input.model;
    output["vehicleType"] = input.vehicleType;
    output["firstName"] = input.firstName;
    output["address"] = input.address;

    return output;
}

std::string Converter::GetRegistrationNumber(const json input)
{
    return input["registrationNumber"].get<std::string>();
}
