#include <iostream>
#include "VehicleUI.h"
#include "VehicleBL.h"
#include "VehiclePersistency.h"

int main() {
    VehiclePersistency* persistency = new VehiclePersistency();
    VehicleBL* vehicleManager = new VehicleBL(persistency);
    VehicleUI vehicleUI(vehicleManager);
    vehicleUI.DisplayMainMenu();

    delete vehicleManager;
    delete persistency;

    return 0;
}