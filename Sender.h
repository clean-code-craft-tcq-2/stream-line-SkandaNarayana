//
// Created by nsk8kor on 03/04/22.
//

#ifndef STREAM_LINE_SKANDANARAYANA_SENDER_H
#define STREAM_LINE_SKANDANARAYANA_SENDER_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>


enum class Param{
    TEMPERATURE,
    SOC
};

class Sender {
public:
    Sender(){
        sensorStreamValue = {};
        paramValueMap = {};
    }
    std::unordered_map<std::string , std::vector<int>> readFromFile(std::string, std::string);
    std::string writeToConsole();

private:
    std::vector<int> sensorStreamValue;
    std::unordered_map<std::string , std::vector<int>> paramValueMap;
};


#endif //STREAM_LINE_SKANDANARAYANA_SENDER_H
