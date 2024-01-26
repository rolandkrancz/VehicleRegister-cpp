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
    j["registrationNumber"] = registrationNumber;
    j["model"] = model;
    j["vehicleType"] = type;
    j["firstName"] = name;
    j["address"] = address;

    return j;
}

json UIController::CreateGetVehicleInfoRequest(const std::string registrationNumber)
{
    json request;
    request["registrationNumber"] = registrationNumber;

    return request;
}