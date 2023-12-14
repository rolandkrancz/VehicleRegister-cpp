#include <iostream>
#include "VehicleUI.h"
#include "VehicleBL.h"
#include "VehiclePersistency.h"
#include "View.h"
#include "UIController.h"

int main() {
    VehiclePersistency* persistency = new VehiclePersistency();
    VehicleBL* vehicleManager = new VehicleBL(persistency);
    
    View* view = new View();
    UIController* controller = new UIController(vehicleManager);
    VehicleUI vehicleUI(controller, view);
    vehicleUI.DisplayMainMenu();

    delete vehicleManager;
    delete persistency;

    return 0;
}