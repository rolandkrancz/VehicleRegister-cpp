#pragma once

#include "ext/json.hpp"

using json = nlohmann::json;

class IPresenterApi {
public:

    virtual void DisplayVehicle(const json vehicle) = 0;
};