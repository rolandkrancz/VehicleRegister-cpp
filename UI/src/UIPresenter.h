#pragma once

#include "IPresenterApi.h"
#include "View.h"

class UIPresenter : public IPresenterApi {
private:
    View* view;
public:
    UIPresenter(View* view);
    void DisplayVehicleInfo(const json vehicle);
    void DisplayError(const json error);
};