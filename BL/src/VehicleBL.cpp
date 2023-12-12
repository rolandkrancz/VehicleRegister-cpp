#include "VehicleBL.h"

VehicleBL::VehicleBL(IStorage* storage) : storage(storage) {}

void VehicleBL::RegisterVehicle(const json vehicle) {

	// TODO: def prog.

	const VehicleEntity vehicleEntity = JsonToVehicleEntity(vehicle);

    storage->Save(vehicleEntity);
}

json VehicleBL::GetVehicleInfo(const std::string registrationNumber) {
	
	// TODO: def prog.
	
	VehicleEntity vehicleEntity = storage->Load(registrationNumber);

	return VehicleEntityToJson(vehicleEntity); // -> async, presenter
}

// Extract to helper/convert class
VehicleEntity VehicleBL::JsonToVehicleEntity(const json vehicle)
{
	return VehicleEntity(
		vehicle["registration_number"].get<std::string>(),
		vehicle["model"].get<std::string>(),
		vehicle["vehicle_type"].get<std::string>(),
		vehicle["owner_name"].get<std::string>(),
		vehicle["owner_address"].get<std::string>()
	);
}

json VehicleBL::VehicleEntityToJson(const VehicleEntity vehicle)
{
	json j;
	j["registration_number"] = vehicle.GetRegistrationNumber();
	j["model"] = vehicle.GetModel();
	j["vehicle_type"] = vehicle.GetVehicleType();
	j["owner_name"] = vehicle.GetOwnerName();
	j["owner_address"] = vehicle.GetOwnerAddress();

	return j;
}
