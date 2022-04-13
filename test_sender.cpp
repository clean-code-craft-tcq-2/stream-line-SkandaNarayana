#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "Sender.h"

TEST_CASE("test reading from a file for Temperature"){
    std::unordered_map<std::string , std::vector<int>> output = {};
    std::string filePath = "temperatureRangeOfValues.txt";
    Sender senderObj;
    output = senderObj.readFromFile(filePath, "TEMPERATURE");
    assert(output["TEMPERATURE"].size() == 50);
    assert(output["TEMPERATURE"].front() == 1);
    assert(output["TEMPERATURE"].back() == 30);
}

TEST_CASE("test reading from a file for SOC"){
    std::unordered_map<std::string , std::vector<int>> output = {};
    std::string filePath = "SoCValuesFromSensor.txt";
    Sender senderObj;
    output = senderObj.readFromFile(filePath, "SOC");
    assert(output["SOC"].size() == 50);
    assert(output["SOC"].front() == 10);
    assert(output["SOC"].back() == 66);

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


