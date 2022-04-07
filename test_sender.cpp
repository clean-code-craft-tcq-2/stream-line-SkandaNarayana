#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "Sender.h"

TEST_CASE("test reading from a file for Temperature"){
    std::unordered_map<std::string , std::vector<int>> expected = {
            {"TEMPERATURE", {1, 4}}
    };
    std::string filePath = "temperatureRangeOfValues.txt";
    Sender senderObj;
    assert(senderObj.readFromFile(filePath, "TEMPERATURE") == expected);
    senderObj.writeToConsole();
}

TEST_CASE("test reading from a file for SOC"){
    std::unordered_map<std::string , std::vector<int>> expected = {
            {"SOC", {10, 20}}
    };
    std::string filePath = "SoCValuesFromSensor.txt";
    Sender senderObj;
    assert(senderObj.readFromFile(filePath, "SOC") == expected);
    senderObj.writeToConsole();
}

TEST_CASE("write to console"){
    std::string expected = "SOC,10 20 \nTEMPERATURE,1 4 \n";
    std::string temperatureValueFilePath = "temperatureRangeOfValues.txt";
    std::string socValueFilePath = "SoCValuesFromSensor.txt";
    Sender senderObj;
    senderObj.readFromFile(temperatureValueFilePath, "TEMPERATURE");
    senderObj.readFromFile(socValueFilePath, "SOC");
    assert(senderObj.writeToConsole().find("SOC,10 20") == 0);
}


