#include <iostream>
#include "VehicleUI.h"
#include "VehicleInteractor.h"
#include "VehiclePersistency.h"
#include "View.h"
#include "UIController.h"
#include "UIPresenter.h"

#define DB_FILE_NAME "database.txt"

int main() {
    View* view = new View();
    UIPresenter* presenter = new UIPresenter(view);
    VehiclePersistency* persistency = new VehiclePersistency(DB_FILE_NAME);
    VehicleInteractor* interactor = new VehicleInteractor(persistency, presenter);
    UIController* controller = new UIController(interactor);
    VehicleUI ui(controller, view);
    ui.DisplayMainMenu();

    delete controller;
    delete interactor;
    delete persistency;
    delete presenter;

    return 0;
}