#include "UIPresenter.h"

UIPresenter::UIPresenter(ConsoleView* view)
{
    UIPresenter::view = view;
}

void UIPresenter::DisplayVehicleInfo(const json vehicle)
{
    // TODO: Def. prog

    const VehicleViewModel vehicleView = ConvertToVehicleViewModel(vehicle);

    view->DisplayVehicleInfo(vehicleView);
}

VehicleViewModel UIPresenter::ConvertToVehicleViewModel(const json input)
{
    VehicleViewModel output = {};

    output.registrationNumber = input["registrationNumber"].get<std::string>();
    output.model = input["model"].get<std::string>();
    output.vehicleType = input["vehicleType"].get<std::string>();
    output.firstName = input["firstName"].get<std::string>();
    output.address = input["address"].get<std::string>();

    return output;
}

