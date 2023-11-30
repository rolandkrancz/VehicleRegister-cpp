#include <iostream>
#include "VehicleUI.h"
#include "VehicleBL.h"
#include "VehiclePersistency.h"

int main() {
    VehiclePersistency* persistency = new VehiclePersistency();
    VehicleBL* vehicleBL = new VehicleBL(persistency);
    VehicleUI vehicleUI(vehicleBL);
    vehicleUI.DisplayMainMenu();

    delete vehicleBL;
    return 0;
}