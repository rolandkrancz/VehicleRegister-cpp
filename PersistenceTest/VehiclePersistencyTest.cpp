#include "pch.h"
#include "VehiclePersistency.h"

#define TEST_DB_FILE_NAME "test-database.txt"

TEST(VehiclePersistencyTest, SaveAndLoadFromFile)
{
    VehicleEntity testEntity = {"TEST001", "testModel", "testType", "testName", "testAddress"};

    VehiclePersistency persistency(TEST_DB_FILE_NAME);

    persistency.Save(testEntity);

    VehicleEntity written = persistency.Load("TEST001");

    EXPECT_EQ(testEntity.registration_number, written.registration_number);
    EXPECT_EQ(testEntity.model, written.model);
    EXPECT_EQ(testEntity.vehicle_type, written.vehicle_type);
    EXPECT_EQ(testEntity.owner_name, written.owner_name);
    EXPECT_EQ(testEntity.owner_address, written.owner_address);

    std::remove(TEST_DB_FILE_NAME);
}