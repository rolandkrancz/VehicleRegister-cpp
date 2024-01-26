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
    expectedRequest["registrationNumber"] = "1";
    expectedRequest["model"] = "2";
    expectedRequest["vehicleType"] = "3";
    expectedRequest["firstName"] = "4";
    expectedRequest["address"] = "5";

    EXPECT_CALL(api, RegisterVehicle(expectedRequest));

    controller.RegisterVehicle("1","2","3","4","5");
}

TEST(UIControllerTest, GetVehicleInfoIsCalled_CreateRequestAndCallApi) {

    MockVehicleApi api;
    UIController controller(&api);

    json expectedRequest;
    expectedRequest["registrationNumber"] = "ABC-123";

    EXPECT_CALL(api, GetVehicleInfo(expectedRequest));

    controller.GetVehicleInfo("ABC-123");
}