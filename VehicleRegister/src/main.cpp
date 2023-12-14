#include <iostream>
#include "VehicleUI.h"
#include "VehicleBL.h"
#include "VehiclePersistency.h"
#include "View.h"

int main() {
    VehiclePersistency* persistency = new VehiclePersistency();
    VehicleBL* vehicleManager = new VehicleBL(persistency);
    View* view = new View();
    VehicleUI vehicleUI(vehicleManager, view);
    vehicleUI.DisplayMainMenu();

    delete vehicleManager;
    delete persistency;

    return 0;
}