#include "UIPresenter.h"

UIPresenter::UIPresenter(View* view) : view(view) {}

void UIPresenter::DisplayVehicleInfo(const json vehicle)
{
    std::string reg_number = vehicle["registration_number"].get<std::string>();
    std::string model = vehicle["model"].get<std::string>();
    std::string type = vehicle["vehicle_type"].get<std::string>();
    std::string name = vehicle["owner_name"].get<std::string>();
    std::string address = vehicle["owner_address"].get<std::string>();

    view->DisplayVehicleInfo(reg_number, model, type, name, address);
}

void UIPresenter::DisplayError(const json error)
{
    view->DisplayError(error);
}
