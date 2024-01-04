#include "VehiclePersistency.h"
#include <fstream>
#include <sstream>
#include <vector>

#define DB_DIRECTORY "../Persistence/"

VehiclePersistency::VehiclePersistency(const std::string fileName) : fileName(fileName) {}

void VehiclePersistency::Save(const VehicleEntity vehicle) {
    std::ofstream file(DB_DIRECTORY + this->fileName, std::ios::app);
    if (file.is_open()) {
        file << vehicle.GetRegistrationNumber() << ","
             << vehicle.GetModel() << ","
             << vehicle.GetVehicleType() << ","
             << vehicle.GetOwnerName() << ","
             << vehicle.GetOwnerAddress() << "\n";
        file.close();
    }
}

VehicleEntity VehiclePersistency::Load(const std::string registrationNumber) {

    std::ifstream file(DB_DIRECTORY + this->fileName);
    VehicleEntity vehicle;

    if (file.is_open()) {

        std::string line;

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string regNum, model, type, name, address;

            if (std::getline(iss, regNum, ',') &&
                std::getline(iss, model, ',') &&
                std::getline(iss, type, ',') &&
                std::getline(iss, name, ',') &&
                std::getline(iss, address)) {

                if (regNum == registrationNumber)
                {
                    vehicle = VehicleEntity(regNum, model, type, name, address);
                    break;
                }
            }
        }

        file.close();
    }

    return vehicle;

}
