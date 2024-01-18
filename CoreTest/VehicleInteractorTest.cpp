#include "pch.h"
#include "VehicleInteractor.h"
#include "Converter.h"
#include <gmock/gmock.h>

class MockStorage : public IStorage {
    public:
    MOCK_METHOD1(Save, void(VehicleEntity));
    MOCK_METHOD1(Load, VehicleEntity(std::string));
};

class MockPresenter : public IPresenterApi {
    public:
    MOCK_METHOD1(DisplayVehicleInfo, void(const json));
};

static const json S_testInput = {
        {"registration_number", "TEST001"},
        {"model", "SampleModel"},
        {"vehicle_type", "SampleType"},
        {"owner_name", "Béla"},
        {"owner_address", "Budapest"},
};

static const VehicleEntity S_testEntity = Converter::JsonToVehicleEntity(S_testInput);
static std::string S_testRegistrationNumber = Converter::GetRegistrationNumber(S_testInput);


TEST(VehicleInteractorTest, RegisterVehicleIsCalled_ConvertToVehicleEntityAndStore)
{
    MockStorage storage;
    MockPresenter presenter;
    VehicleInteractor interactor(&storage, &presenter);

  //  EXPECT_CALL(storage, Save(S_testEntity));

    interactor.RegisterVehicle(S_testInput);
}

TEST(VehicleInteractorTest, GetVehicleInfoIsCalled_ReturnVehicle)
{
    MockStorage storage;
    MockPresenter presenter;
    VehicleInteractor interactor(&storage, &presenter);

    EXPECT_CALL(storage, Load(S_testRegistrationNumber)).WillOnce(::testing::Return(S_testEntity));
    EXPECT_CALL(presenter, DisplayVehicleInfo(S_testInput));

    interactor.GetVehicleInfo(S_testInput);
}
