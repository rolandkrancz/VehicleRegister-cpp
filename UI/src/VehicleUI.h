#ifndef VEHICLE_UI_H
#define VEHICLE_UI_H

#include <iostream>
#include "IVehicleManager.h"

class VehicleUI {
private:
    IVehicleManager* vehicleManager;

public:
    VehicleUI(IVehicleManager* vehicleManager);
    void DisplayMainMenu();

private:
    void _AddRecord();
    void _GetVehicleInfo();
};

#endif // VEHICLE_UI_H
