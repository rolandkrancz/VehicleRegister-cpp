#include "pch.h"
#include "gmock/gmock.h"

#include "UIPresenter.h"

class MockConsoleView : public ConsoleView {
public:
    MOCK_METHOD5(DisplayVehicleInfo, void(const std::string, const std::string, const std::string, const std::string, const std::string));
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

    EXPECT_CALL(mockView, DisplayVehicleInfo(::testing::_, ::testing::_, ::testing::_, ::testing::_, ::testing::_)).Times(1);
    
    presenter.DisplayVehicleInfo(input);
}
