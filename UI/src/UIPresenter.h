#pragma once

#include "IPresenterApi.h"
#include "View.h"

class UIPresenter : public IPresenterApi {
private:
    View* view;
public:
    UIPresenter(View* view);
    void DisplayVehicle(const json vehicle);
};