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

    json request;
    request["registration_number"] = View::GetInput("Enter registration number: ");

    const json response = vehicleManager->GetVehicleInfo(request);
    // def prog? -> minimal + error kijelzes

    View::DisplayVehicle(response);
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