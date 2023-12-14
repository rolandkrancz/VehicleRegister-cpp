#pragma once

#include <iostream>
#include "IVehicleManager.h"
#include "View.h"

class VehicleUI {
private:
    IVehicleManager* vehicleManager;
    View* view;

public:
    VehicleUI(IVehicleManager* vehicleManager, View* view);
    void DisplayMainMenu();

private:
    void AddRecord();
    void GetVehicleInfo();
    static json SerializeDataForBL(const std::string reg_number,
                                   const std::string model,
                                   const std::string type,
                                   const std::string name,
                                   const std::string address);
    static json CreateVehicleInfoRequest(const std::string registrationNumber);
    static bool IsRegistrationNumberValid(const std::string registrationNumber);
    static bool IsResponseValidForGivenRequest(const json request, const json response);
};