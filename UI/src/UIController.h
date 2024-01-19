#pragma once

#include "IVehicleManager.h"

class UIController {
private:
    IVehicleManager* vehicleApi;

public:
    UIController(IVehicleManager* vehicleApi);
    void RegisterVehicle(const std::string registrationNumber,
                         const std::string model,
                         const std::string type,
                         const std::string name,
                         const std::string address);
    void GetVehicleInfo(const std::string registrationNumber);

private:
    static json CreateRegisterVehicleRequest(const std::string registrationNumber,
                                             const std::string model,
                                             const std::string type,
                                             const std::string name,
                                             const std::string address);
    static json CreateGetVehicleInfoRequest(const std::string registrationNumber);
};