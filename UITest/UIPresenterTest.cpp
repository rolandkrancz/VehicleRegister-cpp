#include "pch.h"
#include "gmock/gmock.h"

#include "UIPresenter.h"

class MockView : public ConsoleView {
    MOCK_METHOD0(DisplayMenu, void(void));
    MOCK_METHOD1(GetInput, std::string(std::string));
    MOCK_METHOD5(DisplayVehicleInfo, void(std::string, std::string, std::string, std::string, std::string));
};

TEST(UIPresenterTest, RegisterVehicleIsCalled_CreateRequestAndCallApi) {

    MockView view;
    UIPresenter presenter(&view);

    json input;
    input["registration_number"] = "1";
    input["model"] = "2";
    input["vehicle_type"] = "3";
    input["owner_name"] = "4";
    input["owner_address"] = "5";

  //  EXPECT_CALL(view, DisplayVehicleInfo("1","2","3","4","5"));

    presenter.DisplayVehicleInfo(input);
}
