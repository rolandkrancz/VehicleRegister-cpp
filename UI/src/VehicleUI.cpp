#include "VehicleUI.h"
#include "View.h"

VehicleUI::VehicleUI(IVehicleManager* vehicleManager) : vehicleManager(vehicleManager) {}

void VehicleUI::DisplayMainMenu() {
    while (true) {

        View::DisplayMenu();
        const std::string selection = View::GetInput("");

        if (selection == "1") AddRecord();
        else if (selection == "2") GetVehicleInfo();
        else if (selection == "3") break;
    }
}

void VehicleUI::AddRecord() {
    std::string reg_number, model, type, name, address;

    reg_number = View::GetInput("Enter registration number: ");
    model = View::GetInput("Enter model : ");
    type = View::GetInput("Enter type: ");
    name = View::GetInput("Enter owner's name: ");
    address = View::GetInput("Enter owner's address: ");
    const json vehicle = SerializeDataForBL(reg_number, model, type, name, address);

    vehicleManager->RegisterVehicle(vehicle);
}   

void VehicleUI::GetVehicleInfo() {

    std::string registrationNumber = View::GetInput("Enter registration number: ");
    std::string error = IsRegistrationNumberValid(registrationNumber) ? "" : "Invalid registration number.";

    if (error == "")
    {
        const json request = CreateVehicleInfoRequest(registrationNumber);
        const json response = vehicleManager->GetVehicleInfo(request);

        if (IsResponseValidForGivenRequest(request, response))
        {
            View::DisplayVehicle(response);
        }
        else
        {
            error = "Response is corrupted.";
        }
    }

    if (error != "")
    {
        View::DisplayError(error);
    }
}

json VehicleUI::SerializeDataForBL(const std::string reg_number,
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

json VehicleUI::CreateVehicleInfoRequest(const std::string registrationNumber)
{
    json request;
    request["registration_number"] = registrationNumber;

    return request;
}

bool VehicleUI::IsRegistrationNumberValid(const std::string registrationNumber)
{
    return (registrationNumber != "");
}

bool VehicleUI::IsResponseValidForGivenRequest(const json request, const json response)
{
    return (response["registration_number"].get<std::string>() == request["registration_number"].get<std::string>());
}
