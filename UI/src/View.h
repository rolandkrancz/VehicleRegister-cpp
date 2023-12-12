#pragma once
#ifndef VIEW_H
#define VIEW_H

#include <string>
#include "ext/json.hpp"

using json = nlohmann::json;

class View {
public:
	static std::string GetInput(std::string text);
	static void DisplayVehicle(json vehicle);
};


#endif // VIEW_H
