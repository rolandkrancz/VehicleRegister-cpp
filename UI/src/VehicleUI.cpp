#include "VehicleUI.h"
#include "View.h"

VehicleUI::VehicleUI(IVehicleManager* vehicleManager) : vehicleManager(vehicleManager) {}

void VehicleUI::DisplayMainMenu() {
    while (true) {

        // TODO: Extract to View
        std::cout << "\n1. Add Vehicle Record" << std::endl;
        std::cout << "2. Get Vehicle Info" << std::endl;
        std::cout << "3. Exit\n" << std::endl;
        std::string selection;
        std::getline(std::cin, selection);

        if (selection == "1") {
            AddRecord();
        } else if (selection == "2") {
            GetVehicleInfo();
        } else if (selection == "3") {
            break;
        }
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
    const json vehicle = vehicleManager->GetVehicleInfo(registrationNumber);
    // def prog? -> minimal + error kijelzes

    View::DisplayVehicle(vehicle);
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