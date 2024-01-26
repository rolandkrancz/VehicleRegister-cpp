#pragma once

#include <iostream>
#include <string>
#include "VehicleViewModel.h"

class ConsoleView {
public:
	void DisplayMenu(void);
	std::string GetInput(const std::string text);
	void DisplayVehicleInfo(const VehicleViewModel vehicle);
};