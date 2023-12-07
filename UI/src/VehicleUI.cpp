#include "VehicleUI.h"

VehicleUI::VehicleUI(IVehicleManager* vehicleManager) : vehicleManager(vehicleManager) {}

void VehicleUI::DisplayMainMenu() {
    while (true) {
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

    VehicleEntity VehicleEntity(reg_number, model, type, name, address);
    vehicleManager->RegisterVehicle(VehicleEntity);
}

void VehicleUI::GetVehicleInfo() {
    std::string registrationNumber;
    std::cout << "Enter registration number: ";
    std::getline(std::cin, registrationNumber);

    VehicleEntity VehicleEntity = vehicleManager->GetVehicleInfo(registrationNumber);

    if (!VehicleEntity.GetRegistrationNumber().empty()) {
        std::cout << "Registration Number: " << VehicleEntity.GetRegistrationNumber() << std::endl;
        std::cout << "Model: " << VehicleEntity.GetModel() << std::endl;
        std::cout << "Type: " << VehicleEntity.GetVehicleType() << std::endl;
        std::cout << "Owner's Name: " << VehicleEntity.GetOwnerName() << std::endl;
        std::cout << "Owner's Address: " << VehicleEntity.GetOwnerAddress() << std::endl;
    } else {
        std::cout << "Vehicle not found." << std::endl;
    }
}
