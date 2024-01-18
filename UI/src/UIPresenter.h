#pragma once

#include "IPresenterApi.h"
#include "IView.h"

class UIPresenter : public IPresenterApi {
private:
    IView* view;
public:
    UIPresenter(IView* view);
    void DisplayVehicleInfo(const json vehicle);
};