
#include "View.h"
#include <iostream>

std::string View::GetInput(std::string text)
{
	std::string input;

	std::cout << text;
	std::getline(std::cin, input);

	return input;
}

void View::DisplayVehicle(json vehicle)
{
	std::cout << "Registration Number: " << vehicle["registration_number"].get<std::string>() << std::endl;
	std::cout << "Model: " << vehicle["model"].get<std::string>() << std::endl;
	std::cout << "Type: " << vehicle["vehicle_type"].get<std::string>() << std::endl;
	std::cout << "Owner's Name: " << vehicle["owner_name"].get<std::string>() << std::endl;
	std::cout << "Owner's Address: " << vehicle["owner_address"].get<std::string>() << std::endl;
}