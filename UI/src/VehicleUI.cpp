#include "VehicleUI.h"

VehicleUI::VehicleUI(UIController* controller, View* view) :
    controller(controller), view(view) {}

void VehicleUI::DisplayMainMenu() {
    while (true) {

        view->DisplayMenu();
        const std::string selection = view->GetInput("");

        if (selection == "1") AddRecord();
        else if (selection == "2") GetVehicleInfo();
        else if (selection == "3") break;
    }
}

void VehicleUI::AddRecord() {
    std::string reg_number, model, type, name, address;

    reg_number = view->GetInput("Enter registration number: ");
    model = view->GetInput("Enter model : ");
    type = view->GetInput("Enter type: ");
    name = view->GetInput("Enter owner's name: ");
    address = view->GetInput("Enter owner's address: ");

    controller->RegisterVehicle(reg_number, model, type, name, address);
}   

void VehicleUI::GetVehicleInfo() {

    const std::string registrationNumber = view->GetInput("Enter registration number: ");
    const json response = controller->GetVehicleInfo(registrationNumber);
    view->DisplayVehicle(response);
}
