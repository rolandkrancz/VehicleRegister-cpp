#include "VehicleUI.h"

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

    // extract ->View - GetInput
    std::cout << "Enter registration number: ";
    std::getline(std::cin, reg_number);
    std::cout << "Enter model: ";
    std::getline(std::cin, model);
    std::cout << "Enter type: ";
    std::getline(std::cin, type);
    std::cout << "Enter owner's name: ";
    std::getline(std::cin, name);
    std::cout << "Enter owner's address: ";
    std::getline(std::cin, address);

    const json vehicle = SerializeDataForBL(reg_number, model, type, name, address);
    vehicleManager->RegisterVehicle(vehicle);
}

void VehicleUI::GetVehicleInfo() {
    std::string registrationNumber;
    std::cout << "Enter registration number: ";
    std::getline(std::cin, registrationNumber);

    const json vehicle = vehicleManager->GetVehicleInfo(registrationNumber);

    // def prog?

    // TODO: Extract to View
    std::cout << "Registration Number: " << vehicle["registration_number"].get<std::string>() << std::endl;
    std::cout << "Model: " << vehicle["model"].get<std::string>() << std::endl;
    std::cout << "Type: " << vehicle["vehicle_type"].get<std::string>() << std::endl;
    std::cout << "Owner's Name: " << vehicle["owner_name"].get<std::string>() << std::endl;
    std::cout << "Owner's Address: " << vehicle["owner_address"].get<std::string>() << std::endl;
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