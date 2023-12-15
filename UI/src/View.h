#pragma once

#include <string>
#include "ext/json.hpp"

using json = nlohmann::json;

class View {
public:
	static void DisplayMenu(void);
	static std::string GetInput(std::string text);
	static void DisplayVehicleInfo(const std::string reg_number,
								   const std::string model,
								   const std::string type,
								   const std::string name,
								   const std::string address);
	static void DisplayError(const std::string errorMessage);
};