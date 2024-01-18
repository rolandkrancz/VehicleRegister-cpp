#include "VehicleInteractor.h"
#include "Converter.h"

VehicleInteractor::VehicleInteractor(IStorage* storage, IPresenterApi* presenter) : storage(storage), presenter(presenter) {}

void VehicleInteractor::RegisterVehicle(const json vehicle)
{
    // TODO: def prog.
    const VehicleEntity vehicleEntity = Converter::JsonToVehicleEntity(vehicle);

    storage->Save(vehicleEntity);
}

void VehicleInteractor::GetVehicleInfo(const json request)
{
    // TODO: def prog.
    const std::string registrationNumber = Converter::GetRegistrationNumber(request);
    const VehicleEntity vehicleEntity = storage->Load(registrationNumber);
    const json vehicle = Converter::VehicleEntityToJson(vehicleEntity);

    presenter->DisplayVehicleInfo(vehicle);
}