#include "VehicleInteractor.h"

VehicleInteractor::VehicleInteractor(IStorage* storage, IPresenterApi* presenter) : storage(storage), presenter(presenter) {}

void VehicleInteractor::RegisterVehicle(const json vehicle) {

	// TODO: def prog.
	const VehicleEntity vehicleEntity = JsonToVehicleEntity(vehicle);

	storage->Save(vehicleEntity);
}

void VehicleInteractor::GetVehicleInfo(const json request) {

	// TODO: def prog.
	const std::string registrationNumber = request["registration_number"].get<std::string>();
    VehicleEntity vehicleEntity = storage->Load(registrationNumber);
	const json vehicle = VehicleEntityToJson(vehicleEntity);

	presenter->DisplayVehicle(vehicle);
}

// Extract to helper/convert class
VehicleEntity VehicleInteractor::JsonToVehicleEntity(const json vehicle)
{
    return VehicleEntity(
		vehicle["registration_number"].get<std::string>(),
		vehicle["model"].get<std::string>(),
		vehicle["vehicle_type"].get<std::string>(),
		vehicle["owner_name"].get<std::string>(),
		vehicle["owner_address"].get<std::string>()
	);
}

json VehicleInteractor::VehicleEntityToJson(const VehicleEntity vehicle)
{
	json j;
	j["registration_number"] = vehicle.GetRegistrationNumber();
	j["model"] = vehicle.GetModel();
	j["vehicle_type"] = vehicle.GetVehicleType();
	j["owner_name"] = vehicle.GetOwnerName();
	j["owner_address"] = vehicle.GetOwnerAddress();

	return j;
}
