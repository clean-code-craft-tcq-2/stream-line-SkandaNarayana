//
// Created by nsk8kor on 03/04/22.
//

#include "Sender.h"

std::unordered_map<std::string , std::vector<int>> Sender::readFromFile(const std::string filePath, std::string parameter){
    try{
        std::string value = "";
        sensorStreamValue = {};
        std::fstream fileObj;
        fileObj.open(filePath);
        while(!fileObj.eof()){
            std::getline(fileObj, value);
            sensorStreamValue.push_back(std::stoi(value));
        }
    }
    catch (...){
//        std::cout << "There was an error: " << e.what() << std::endl;
        std::cout << "There was an error: " << std::endl;
    }
    paramValueMap[parameter] = sensorStreamValue;
    return paramValueMap;
}


std::string Sender::writeToConsole() {
    std::string output = {};
    for(const auto& elem : paramValueMap)
    {
//        std::cout << elem.first << "," ;
        output += elem.first + ",";
        for(const auto& value : elem.second){
            output += std::to_string(value) + " ";
        }
        output += "\n";
    }
    std::cout << output;
    return output;
}