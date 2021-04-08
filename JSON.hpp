/**
 * \class JSON
 * 
 * \brief Computer JSON
 * 
 * This is the description of JSON.h
 * 
 * \version 1.0
 * 
 * \author R4ktarV4adasz0k team
 * 
 * \date 2021/04/08 9:05
 * 
 * Created on: 2021/04/08 9:05
*/

#pragma once

#include <string>
#include <map>
#include <fstream>

class JSON
{
public:
    static std::map<std::string, std::string> Parse(const char *fileName); ///< A map that
    static std::map<std::string, std::string> Parse(std::ifstream &fileStream);
    static std::map<std::string, std::string> Parse(std::string fileContent);
};