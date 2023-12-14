#include <iostream>
#include "VehicleUI.h"
#include "VehicleInteractor.h"
#include "VehiclePersistency.h"
#include "View.h"
#include "UIController.h"

int main() {
    VehiclePersistency* persistency = new VehiclePersistency();
    VehicleInteractor* interactor = new VehicleInteractor(persistency);
    
    View* view = new View();
    UIController* controller = new UIController(interactor);
    VehicleUI vehicleUI(controller, view);
    vehicleUI.DisplayMainMenu();

    delete controller;
    delete interactor;
    delete persistency;

    return 0;
}