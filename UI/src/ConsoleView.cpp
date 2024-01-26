#include "ConsoleView.h"

void ConsoleView::DisplayMenu(void)
{
    std::cout << "\n1. Add Vehicle Record" << std::endl;
    std::cout << "2. Get Vehicle Info" << std::endl;
    std::cout << "3. Exit\n" << std::endl;
}

std::string ConsoleView::GetInput(const std::string prompt)
{
    std::string input;

    std::cout << prompt;
    std::getline(std::cin, input);

    return input;
}

void ConsoleView::DisplayVehicleInfo(const VehicleViewModel vehicle)
{
    std::cout << "Registration Number: " << vehicle.registrationNumber << std::endl;
    std::cout << "Model: " << vehicle.model << std::endl;
    std::cout << "Type: " << vehicle.vehicleType << std::endl;
    std::cout << "Owner's Name: " << vehicle.firstName << std::endl;
    std::cout << "Owner's Address: " << vehicle.address << std::endl;
}
