#include <iostream>
#include "./UI/VehicleUI.h"
#include "./BL/VehicleBL.h"
#include "./Persistence/VehiclePersistency.h"

int main() {
    VehiclePersistency* persistency = new VehiclePersistency();
    VehicleBL* vehicleBL = new VehicleBL(persistency);
    VehicleUI vehicleUI(vehicleBL);
    vehicleUI.DisplayMainMenu();

    delete vehicleBL;
    return 0;
}