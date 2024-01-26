#include "pch.h"
#include "../BL/src/Converter.h"

TEST(ConverterTest, ValidInput_GetRegistrationNumber_ReturnRegistrationNumber)
{
    json testInput = {
        {"registrationNumber", "TEST001"},
    };

    EXPECT_EQ("TEST001", Converter::GetRegistrationNumber(testInput));
}

TEST(ConverterTest, InvalidInput_GetRegistrationNumber_Throw)
{
    json testInput = {
        {"whatever", "TEST001"},
    };

    EXPECT_ANY_THROW(Converter::GetRegistrationNumber(testInput));
}

TEST(ConverterTest, ValidInput_JsonToVehicleEntity_ReturnVehicleEntity)
{
    json testInput = {
        {"registrationNumber", "TEST001"},
        {"model", "SampleModel"},
        {"vehicleType", "SampleType"},
        {"firstName", "Béla"},
        {"address", "Budapest"},
    };

    const VehicleEntity result = Converter::JsonToVehicleEntity(testInput);

    EXPECT_EQ("TEST001", result.registrationNumber);
    EXPECT_EQ("SampleModel", result.model);
    EXPECT_EQ("SampleType", result.vehicleType);
    EXPECT_EQ("Béla", result.firstName);
    EXPECT_EQ("Budapest", result.address);
}

TEST(ConverterTest, InvalidInput_JsonToVehicleEntity_Throw)
{
    json testInput = {
        {"whatever", "TEST001"},
    };

    EXPECT_ANY_THROW(Converter::JsonToVehicleEntity(testInput));
}

TEST(ConverterTest, ValidInput_VehicleEntityToJson_ReturnJson)
{
    VehicleEntity testInput{};
    testInput.registrationNumber = "TEST001";
    testInput.model= "SampleModel";
    testInput.vehicleType = "SampleType";
    testInput.firstName= "Béla";
    testInput.address = "Budapest";

    const json result = Converter::VehicleEntityToJson(testInput);

    EXPECT_EQ("TEST001", result["registrationNumber"]);
    EXPECT_EQ("SampleModel", result["model"]);
    EXPECT_EQ("SampleType", result["vehicleType"]);
    EXPECT_EQ("Béla", result["firstName"]);
    EXPECT_EQ("Budapest", result["address"]);
}

TEST(ConverterTest, InvalidInput_VehicleEntityToJson_ReturnEmptyJson)
{
    VehicleEntity testInput{"", "", "", "", ""};
   
    const json result = Converter::VehicleEntityToJson(testInput);

    EXPECT_EQ("", result["registrationNumber"]);
    EXPECT_EQ("", result["model"]);
    EXPECT_EQ("", result["vehicleType"]);
    EXPECT_EQ("", result["firstName"]);
    EXPECT_EQ("", result["address"]);
}