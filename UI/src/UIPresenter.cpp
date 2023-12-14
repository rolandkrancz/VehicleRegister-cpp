#include "UIPresenter.h"

UIPresenter::UIPresenter(View* view) : view(view) {}

void UIPresenter::DisplayVehicle(const json vehicle)
{
    view->DisplayVehicle(vehicle);
}
