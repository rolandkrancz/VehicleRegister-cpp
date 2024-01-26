#pragma once

#include "IPresenterApi.h"
#include "ConsoleView.h"

class UIPresenter : public IPresenterApi {
private:
    ConsoleView* view;
public:
    UIPresenter(ConsoleView* view);
    void DisplayVehicleInfo(const json vehicle);
};