#pragma once

#include "IView.h"
#include "ext/json.hpp"

using json = nlohmann::json;

class ConsoleView : public IView {
public:
	void DisplayMenu(void) override;
	std::string GetInput(std::string text) override;
	void DisplayVehicleInfo(const std::string reg_number,
							const std::string model,
							const std::string type,
							const std::string name,
							const std::string address) override;
};