#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "Sender.h"

TEST_CASE("test reading from a file"){
    std::unordered_map<std::string , std::vector<int>> expected = {
            {"TEMPERATURE", {1, 4}}
    };
    std::string filePath = "/home/nsk8kor/CLionProjects/stream-line-SkandaNarayana/temperatureRangeOfValues.txt";
    Sender senderObj;
    assert(senderObj.readFromFile(filePath, "TEMPERATURE") == expected);
    senderObj.writeToConsole();
}

TEST_CASE("test reading from a file for SOC"){
    std::unordered_map<std::string , std::vector<int>> expected = {
            {"SOC", {10, 20}}
    };
    std::string filePath = "/home/nsk8kor/CLionProjects/stream-line-SkandaNarayana/SoCValuesFromSensor.txt";
    Sender senderObj;
    assert(senderObj.readFromFile(filePath, "SOC") == expected);

}

TEST_CASE("write to console"){
    std::string expected = "SOC,10 20 \nTEMPERATURE,1 4 \n";
    std::string filePath = "/home/nsk8kor/CLionProjects/stream-line-SkandaNarayana/temperatureRangeOfValues.txt";
    std::string filePath2 = "/home/nsk8kor/CLionProjects/stream-line-SkandaNarayana/SoCValuesFromSensor.txt";
    Sender senderObj;
    senderObj.readFromFile(filePath,"TEMPERATURE");
    senderObj.readFromFile(filePath2,"SOC");
    assert(senderObj.writeToConsole() == expected);
}

