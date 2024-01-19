#include "UIPresenter.h"

UIPresenter::UIPresenter(IView* view) : view(view) {}

void UIPresenter::DisplayVehicleInfo(const json vehicle)
{
    // TODO: Def. prog

    // convert to View model!
    std::string registrationNumber = vehicle["registration_number"].get<std::string>();
    std::string model = vehicle["model"].get<std::string>();
    std::string type = vehicle["vehicle_type"].get<std::string>();
    std::string name = vehicle["owner_name"].get<std::string>();
    std::string address = vehicle["owner_address"].get<std::string>();

    view->DisplayVehicleInfo(registrationNumber, model, type, name, address); // param: view model
}
