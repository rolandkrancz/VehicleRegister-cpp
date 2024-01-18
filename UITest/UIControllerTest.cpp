#include "pch.h"
#include "gmock/gmock.h"

#include "UIController.h"

class MockVehicleApi : public IVehicleManager {
public:
    MOCK_METHOD1(RegisterVehicle, void(json));
    MOCK_METHOD1(GetVehicleInfo, void(json));
};

TEST(UIControllerTest, RegisterVehicleIsCalled_CreateRequestAndCallApi) {

    MockVehicleApi api;
    UIController controller(&api);

    json expectedRequest;
    expectedRequest["registration_number"] = "1";
    expectedRequest["model"] = "2";
    expectedRequest["vehicle_type"] = "3";
    expectedRequest["owner_name"] = "4";
    expectedRequest["owner_address"] = "5";

    EXPECT_CALL(api, RegisterVehicle(expectedRequest));

    controller.RegisterVehicle("1","2","3","4","5");
}

TEST(UIControllerTest, GetVehicleInfoIsCalled_CreateRequestAndCallApi) {

    MockVehicleApi api;
    UIController controller(&api);

    json expectedRequest;
    expectedRequest["registration_number"] = "ABC-123";

    EXPECT_CALL(api, GetVehicleInfo(expectedRequest));

    controller.GetVehicleInfo("ABC-123");
}