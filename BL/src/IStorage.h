#ifndef ISTORAGE_H
#define ISTORAGE_H

#include "VehicleEntity.h"

class IStorage {
public:
    virtual ~IStorage() = default;

    virtual void Save(VehicleEntity VehicleEntity) = 0;
    virtual VehicleEntity Load(std::string registrationNumber) = 0;
};

#endif // ISTORAGE_H
