#include "UIController.h"

UIController::UIController(IVehicleManager* vehicleApi)
{
    UIController::vehicleApi = vehicleApi;
}

void UIController::RegisterVehicle(const std::string registrationNumber,
                                   const std::string model,
                                   const std::string type,
                                   const std::string name,
                                   const std::string address)
{
    const json request = CreateRegisterVehicleRequest(registrationNumber, model, type, name, address);

    vehicleApi->RegisterVehicle(request);
}

void UIController::GetVehicleInfo(const std::string registrationNumber)
{
    const json request = CreateGetVehicleInfoRequest(registrationNumber);

    vehicleApi->GetVehicleInfo(request);
}

json UIController::CreateRegisterVehicleRequest(const std::string registrationNumber,
                                                const std::string model,
                                                const std::string type,
                                                const std::string name,
                                                const std::string address)
{
    json j;
    j["registration_number"] = registrationNumber;
    j["model"] = model;
    j["vehicle_type"] = type;
    j["owner_name"] = name;
    j["owner_address"] = address;

    return j;
}

json UIController::CreateGetVehicleInfoRequest(const std::string registrationNumber)
{
    json request;
    request["registration_number"] = registrationNumber;

    return request;
}