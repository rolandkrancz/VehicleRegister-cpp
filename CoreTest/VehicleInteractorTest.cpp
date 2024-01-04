#include "pch.h"
#include "../BL/src/VehicleInteractor.h"
#include <gmock/gmock.h>

class MockStorage : public IStorage {
    public:
    MOCK_METHOD1(Save,void(VehicleEntity));
    MOCK_METHOD1(Load, VehicleEntity(std::string));
};

TEST(VehicleInteractorTest, test1)
{
    MockStorage storage;
    VehicleInteractor* interactor = new VehicleInteractor(&storage, NULL);

    json testInput = {
    {"registration_number", "TEST001"},
    {"model", "SampleModel"},
    {"vehicle_type", "SampleType"},
    {"owner_name", "Béla"},
    {"owner_address", "Budapest"},
    };

    VehicleEntity asd("TEST001", "SampleModel", "SampleType", "Béla", "Budapest");

    EXPECT_CALL(storage, Save(asd));

    interactor->RegisterVehicle(testInput);


}
