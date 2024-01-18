#pragma once

#include <string>

class IView {
public:
	virtual void DisplayMenu(void) = 0;
	virtual std::string GetInput(std::string text) = 0;
	virtual void DisplayVehicleInfo(const std::string reg_number,
								    const std::string model,
								    const std::string type,
								    const std::string name,
								    const std::string address) = 0;
};