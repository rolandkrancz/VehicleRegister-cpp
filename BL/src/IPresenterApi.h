#pragma once

#include "ext/json.hpp"

using json = nlohmann::json;

class IPresenterApi {
public:

    virtual void DisplayVehicleInfo(const json vehicle) = 0;
};