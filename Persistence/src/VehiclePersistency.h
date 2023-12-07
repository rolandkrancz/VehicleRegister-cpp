#ifndef VEHICLE_PERSISTENCY_H
#define VEHICLE_PERSISTENCY_H

#include "IStorage.h"
#include "VehicleEntity.h"

class VehiclePersistency : public IStorage {
public:
    void Save(VehicleEntity vehicle) override;
    VehicleEntity Load(std::string registrationNumber) override;
};

#endif // VEHICLE_PERSISTENCY_H
