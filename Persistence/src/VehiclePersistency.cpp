#include "VehiclePersistency.h"
#include <fstream>
#include <sstream>
#include <vector>

#define PATH_TO_DB_FILE "../Persistence/database.txt"

void VehiclePersistency::Save(VehicleEntity vehicle) {
    std::ofstream file(PATH_TO_DB_FILE, std::ios::app);
    if (file.is_open()) {
        file << vehicle.GetRegistrationNumber() << ", "
             << vehicle.GetModel() << ", "
             << vehicle.GetVehicleType() << ", "
             << vehicle.GetOwnerName() << ", "
             << vehicle.GetOwnerAddress() << "\n";
        file.close();
    }
}

VehicleEntity VehiclePersistency::Load(std::string registrationNumber) {

    std::ifstream file(PATH_TO_DB_FILE);
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
