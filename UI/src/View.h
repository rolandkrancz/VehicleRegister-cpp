#pragma once

#include <string>
#include "ext/json.hpp"

using json = nlohmann::json;

class View {
public:
	static void DisplayMenu(void);
	static std::string GetInput(std::string text);
	static void DisplayVehicle(json vehicle);
};