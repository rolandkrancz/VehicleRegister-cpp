#include "ConsoleView.h"
#include <iostream>

void ConsoleView::DisplayMenu(void)
{
    std::cout << "\n1. Add Vehicle Record" << std::endl;
    std::cout << "2. Get Vehicle Info" << std::endl;
    std::cout << "3. Exit\n" << std::endl;
}

std::string ConsoleView::GetInput(std::string text)
{
    std::string input;

    std::cout << text;
    std::getline(std::cin, input);

    return input;
}

void ConsoleView::DisplayVehicleInfo(const std::string registrationNumber,
                                     const std::string model,
                                     const std::string type,
                                     const std::string name,
                                     const std::string address)
{
    std::cout << "Registration Number: " << registrationNumber << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Owner's Name: " << name << std::endl;
    std::cout << "Owner's Address: " << address << std::endl;
}
