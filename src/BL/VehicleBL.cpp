#include "VehicleBL.h"

VehicleBL::VehicleBL(IStorage* storage) : storage(storage) {}

void VehicleBL::RegisterVehicle(VehicleEntity VehicleEntity) {
    storage->Save(VehicleEntity);
}

VehicleEntity VehicleBL::GetVehicleInfo(std::string registrationNumber) {
    return storage->Load(registrationNumber);
}
