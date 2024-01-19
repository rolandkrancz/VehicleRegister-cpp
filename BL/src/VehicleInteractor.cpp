#include "VehicleInteractor.h"
#include "Converter.h"

VehicleInteractor::VehicleInteractor(IStorage* storage, IPresenterApi* presenter) : storage(storage), presenter(presenter) {} // kibontott constr.

void VehicleInteractor::RegisterVehicle(const json request)
{
    // TODO: def prog.
    const VehicleEntity vehicleEntity = Converter::JsonToVehicleEntity(request);

    storage->Save(vehicleEntity);

    // response about registration result -> presenter
}

void VehicleInteractor::GetVehicleInfo(const json request)
{
    // TODO: def prog.
    const std::string registrationNumber = Converter::GetRegistrationNumber(request);
    const VehicleEntity vehicle = storage->Load(registrationNumber);
    const json vehicleJson = Converter::VehicleEntityToJson(vehicle);

    presenter->DisplayVehicleInfo(vehicleJson);
}