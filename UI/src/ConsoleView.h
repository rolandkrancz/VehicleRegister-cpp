#pragma once

#include <iostream>
#include <string>

class ConsoleView {
public:
	void DisplayMenu(void);
	std::string GetInput(std::string text);
	void DisplayVehicleInfo(const std::string registrationNumber,
							const std::string model,
							const std::string type,
							const std::string name,
							const std::string address);
};