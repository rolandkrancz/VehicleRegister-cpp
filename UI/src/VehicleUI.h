#pragma once

#include <iostream>
#include "UIController.h"
#include "View.h"

class VehicleUI {
private:
    UIController* controller;
    View* view;

public:
    VehicleUI(UIController* controller, View* view);
    void DisplayMainMenu();

private:
    void AddRecord();
    void GetVehicleInfo();
};