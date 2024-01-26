#include "pch.h"
#include "VehiclePersistency.h"

#define TEST_DB_FILE_NAME "test-database.txt"

TEST(VehiclePersistencyTest, SaveAndLoadFromFile)
{
    VehicleEntity testEntity = {"TEST001", "testModel", "testType", "testName", "testAddress"};

    VehiclePersistency persistency(TEST_DB_FILE_NAME);

    persistency.Save(testEntity);

    VehicleEntity written = persistency.Load("TEST001");

    EXPECT_EQ(testEntity.registrationNumber, written.registrationNumber);
    EXPECT_EQ(testEntity.model, written.model);
    EXPECT_EQ(testEntity.vehicleType, written.vehicleType);
    EXPECT_EQ(testEntity.firstName, written.firstName);
    EXPECT_EQ(testEntity.address, written.address);

    std::remove(TEST_DB_FILE_NAME);
}