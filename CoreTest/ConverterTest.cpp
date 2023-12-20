#include "pch.h"
#include "../BL/src/Converter.h"

TEST(ConverterTest, ValidInput_GetRegistrationNumber_ReturnRegistrationNumber)
{
    json testInput = {
        {"registration_number", "TEST001"},
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
        {"registration_number", "TEST001"},
        {"model", "SampleModel"},
        {"vehicle_type", "SampleType"},
        {"owner_name", "Béla"},
        {"owner_address", "Budapest"},

    };

    const VehicleEntity result = Converter::JsonToVehicleEntity(testInput);

    EXPECT_EQ("TEST001", result.GetRegistrationNumber());
    EXPECT_EQ("SampleModel", result.GetModel());
    EXPECT_EQ("SampleType", result.GetVehicleType());
    EXPECT_EQ("Béla", result.GetOwnerName());
    EXPECT_EQ("Budapest", result.GetOwnerAddress());
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
    VehicleEntity testInput("TEST001", "SampleModel", "SampleType", "Béla", "Budapest");

    const json result = Converter::VehicleEntityToJson(testInput);

    EXPECT_EQ("TEST001", result["registration_number"]);
    EXPECT_EQ("SampleModel", result["model"]);
    EXPECT_EQ("SampleType", result["vehicle_type"]);
    EXPECT_EQ("Béla", result["owner_name"]);
    EXPECT_EQ("Budapest", result["owner_address"]);
}

TEST(ConverterTest, InvalidInput_VehicleEntityToJson_ReturnEmptyJson)
{
    VehicleEntity testInput("", "", "", "", "");
   
    const json result = Converter::VehicleEntityToJson(testInput);

    EXPECT_EQ("", result["registration_number"]);
    EXPECT_EQ("", result["model"]);
    EXPECT_EQ("", result["vehicle_type"]);
    EXPECT_EQ("", result["owner_name"]);
    EXPECT_EQ("", result["owner_address"]);
}