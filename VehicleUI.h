#ifndef VEHICLE_UI_H
#define VEHICLE_UI_H

#include <iostream>
#include "VehicleBL.h"

class VehicleUI {
private:
    VehicleBL* BL;

public:
    VehicleUI(VehicleBL* vehicleBL);
    void DisplayMainMenu();

private:
    void _AddRecord();
    void _GetVehicleInfo();
};

#endif // VEHICLE_UI_H
