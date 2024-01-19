#pragma once

#include <string>


// felesleges
class IView {
public:
	virtual void DisplayMenu(void) = 0;
	virtual std::string GetInput(std::string text) = 0;
	virtual void DisplayVehicleInfo(const std::string registrationNumber,
								    const std::string model,
								    const std::string type,
								    const std::string name,
								    const std::string address) = 0;
};