#include "Converter.h"

VehicleEntity Converter::JsonToVehicleEntity(const json input)
{
    return VehicleEntity(
        input["registration_number"].get<std::string>(),
        input["model"].get<std::string>(),
        input["vehicle_type"].get<std::string>(),
        input["owner_name"].get<std::string>(),
        input["owner_address"].get<std::string>()
    );
}

json Converter::VehicleEntityToJson(const VehicleEntity input)
{
    json output;
    output["registration_number"] = input.GetRegistrationNumber();
    output["model"] = input.GetModel();
    output["vehicle_type"] = input.GetVehicleType();
    output["owner_name"] = input.GetOwnerName();
    output["owner_address"] = input.GetOwnerAddress();

    return output;
}

std::string Converter::GetRegistrationNumber(const json input)
{
    return input["registration_number"].get<std::string>();
}
