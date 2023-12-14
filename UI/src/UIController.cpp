#include "UIController.h"

UIController::UIController(IVehicleManager* vehicleApi) : vehicleApi(vehicleApi) {}

void UIController::RegisterVehicle(const std::string reg_number,
                                   const std::string model,
                                   const std::string type,
                                   const std::string name,
                                   const std::string address)
{
    const json request = SerializeDataForBL(reg_number, model, type, name, address);
    vehicleApi->RegisterVehicle(request);
}

json UIController::GetVehicleInfo(const std::string registrationNumber)
{
    const json request = CreateVehicleInfoRequest(registrationNumber);
    const json response = vehicleApi->GetVehicleInfo(request);
    
    return response;
}

json UIController::SerializeDataForBL(const std::string reg_number,
                                      const std::string model,
                                      const std::string type,
                                      const std::string name,
                                      const std::string address)
{
    json j;
    j["registration_number"] = reg_number;
    j["model"] = model;
    j["vehicle_type"] = type;
    j["owner_name"] = name;
    j["owner_address"] = address;

    return j;
}

json UIController::CreateVehicleInfoRequest(const std::string registrationNumber)
{
    json request;
    request["registration_number"] = registrationNumber;
    return request;
}