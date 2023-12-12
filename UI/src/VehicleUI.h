#pragma once

#include <iostream>
#include "IVehicleManager.h"

class VehicleUI {
private:
    IVehicleManager* vehicleManager;

public:
    VehicleUI(IVehicleManager* vehicleManager);
    void DisplayMainMenu();

private:
    void AddRecord();
    void GetVehicleInfo();
    static json SerializeDataForBL(const std::string reg_number,
                                   const std::string model,
                                   const std::string type,
                                   const std::string name,
                                   const std::string address);
};