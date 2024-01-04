#pragma once

#include "IStorage.h"
#include "VehicleEntity.h"

class VehiclePersistency : public IStorage {
private:
    std::string fileName;

public:
    VehiclePersistency(const std::string fileName);
    void Save(const VehicleEntity vehicle) override;
    VehicleEntity Load(const std::string registrationNumber) override;
};