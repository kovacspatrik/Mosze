#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "Product.hpp"
#include "string.h"
#include <algorithm>
#include "JSON.hpp"
#include <iostream>
class Computer : public Product
{
private:
    const int ramSize;
    const int storage;
    std::string type = "PC";

public:

    Computer(std::string name, int price, std::string manufacturer, int quantity, int ramSize, int storage);
    void print();
    int getRamsize();
    int getStorage();
    static Computer ParseComputer(const std::string &fileName);
    void generateTxt(std::string fileName);
    void generateJson();
    std::string getType() const;
};

#endif