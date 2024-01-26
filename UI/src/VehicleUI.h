#pragma once

#include <iostream>
#include "UIController.h"
#include "ConsoleView.h"

class VehicleUI {
private:
    UIController* controller;
    ConsoleView* view;

public:
    VehicleUI(UIController* controller, ConsoleView* view);
    void DisplayMainMenu();

private:
    void AddRecord();
    void GetVehicleInfo();
};