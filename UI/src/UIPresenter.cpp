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

    output.registration_number = input["registration_number"].get<std::string>();
    output.model = input["model"].get<std::string>();
    output.vehicle_type = input["vehicle_type"].get<std::string>();
    output.owner_name = input["owner_name"].get<std::string>();
    output.owner_address = input["owner_address"].get<std::string>();

    return output;
}

