
#include "View.h"
#include <iostream>

void View::DisplayMenu(void)
{
    std::cout << "\n1. Add Vehicle Record" << std::endl;
    std::cout << "2. Get Vehicle Info" << std::endl;
    std::cout << "3. Exit\n" << std::endl;
}

std::string View::GetInput(std::string text)
{
    std::string input;

    std::cout << text;
    std::getline(std::cin, input);

    return input;
}

void View::DisplayVehicleInfo(const std::string reg_number,
                              const std::string model,
                              const std::string type,
                              const std::string name,
                              const std::string address)
{
    std::cout << "Registration Number: " << reg_number << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Owner's Name: " << name << std::endl;
    std::cout << "Owner's Address: " << address << std::endl;
}

void View::DisplayError(const std::string errorMessage)
{
    std::cout << "ERROR: " << errorMessage << std::endl;
}
