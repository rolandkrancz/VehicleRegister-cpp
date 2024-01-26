#include "ConsoleView.h"

void ConsoleView::DisplayMenu(void)
{
    std::cout << "\n1. Add Vehicle Record" << std::endl;
    std::cout << "2. Get Vehicle Info" << std::endl;
    std::cout << "3. Exit\n" << std::endl;
}

std::string ConsoleView::GetInput(const std::string text)
{
    std::string input;

    std::cout << text;
    std::getline(std::cin, input);

    return input;
}

void ConsoleView::DisplayVehicleInfo(const VehicleViewModel vehicle)
{
    std::cout << "Registration Number: " << vehicle.registration_number << std::endl;
    std::cout << "Model: " << vehicle.model << std::endl;
    std::cout << "Type: " << vehicle.vehicle_type << std::endl;
    std::cout << "Owner's Name: " << vehicle.owner_name << std::endl;
    std::cout << "Owner's Address: " << vehicle.owner_address << std::endl;
}
