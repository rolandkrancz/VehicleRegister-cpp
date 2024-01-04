#include "pch.h"
#include "VehiclePersistency.h"

#define TEST_DB_FILE_NAME "test-database.txt"
static VehicleEntity S_testEntity = VehicleEntity("TEST001", "testModel", "testType", "testName", "testAddress");

TEST(VehiclePersistencyTest, SaveAndLoadFromFile)
{
    VehiclePersistency persistency(TEST_DB_FILE_NAME);

    persistency.Save(S_testEntity);

    VehicleEntity written = persistency.Load("TEST001");

    ASSERT_EQ(written.GetModel(), S_testEntity.GetModel());

    std::remove(TEST_DB_FILE_NAME);
}