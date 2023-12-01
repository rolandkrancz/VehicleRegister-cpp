#include <iostream>
#include "./UI/VehicleUI.h"
#include "./BL/VehicleBL.h"
#include "./Persistence/VehiclePersistency.h"

int main() {
    VehiclePersistency* persistency = new VehiclePersistency();
    VehicleBL* vehicleManager = new VehicleBL(persistency);
    VehicleUI vehicleUI(vehicleManager);
    vehicleUI.DisplayMainMenu();

    delete vehicleManager;
    return 0;
}