#pragma once

#include "IStorage.h"
#include "VehicleEntity.h"

class VehiclePersistency : public IStorage {
public:
    void Save(VehicleEntity vehicle) override;
    VehicleEntity Load(std::string registrationNumber) override;
};