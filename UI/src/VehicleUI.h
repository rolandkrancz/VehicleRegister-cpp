#pragma once

#include <iostream>
#include "UIController.h"
#include "IView.h"

class VehicleUI {
private:
    UIController* controller;
    IView* view;

public:
    VehicleUI(UIController* controller, IView* view);
    void DisplayMainMenu();

private:
    void AddRecord();
    void GetVehicleInfo();
};