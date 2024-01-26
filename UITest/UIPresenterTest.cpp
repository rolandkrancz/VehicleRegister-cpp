#include "pch.h"
#include "gmock/gmock.h"

#include "UIPresenter.h"

class MockConsoleView : public ConsoleView {
public:
    MOCK_METHOD1(DisplayVehicleInfo, void(const VehicleViewModel));
};

TEST(UIPresenterTest, RegisterVehicleIsCalled_CreateRequestAndCallApi) {

    MockConsoleView mockView;
    UIPresenter presenter(&mockView);

    json input;
    input["registrationNumber"] = "1";
    input["model"] = "2";
    input["vehicleType"] = "3";
    input["firstName"] = "4";
    input["address"] = "5";

    EXPECT_CALL(mockView, DisplayVehicleInfo(::testing::_)).Times(1);
    
    presenter.DisplayVehicleInfo(input);
}
