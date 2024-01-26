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
    input["registration_number"] = "1";
    input["model"] = "2";
    input["vehicle_type"] = "3";
    input["owner_name"] = "4";
    input["owner_address"] = "5";

    EXPECT_CALL(mockView, DisplayVehicleInfo(::testing::_)).Times(1);
    
    presenter.DisplayVehicleInfo(input);
}
