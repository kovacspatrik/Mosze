#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "Product.hpp"

class Computer : public Product
{
private:
    const int ramSize;
    const int storage;
    std::string type = "PC";

public:
    Computer(std::string name, int price, std::string manufacturer, int quantity, int ramSize, int storage);
    void print();
};

#endif