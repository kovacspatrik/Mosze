#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "Product.hpp"
#include "JSON.hpp"

class Computer : public Product
{
private:
    const int ramSize;
    const int storage;
    std::string type = "PC";

public:

    Computer(std::string name, int price, std::string manufacturer, int quantity, int ramSize, int storage);
    void print();
    static Computer ParseComputer(const std::string &fileName);
    void generateTxt(std::string fileName);
};

#endif