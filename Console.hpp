#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include "Product.hpp"

class Console : public Product
{
private:
    const int storage;
    std::string type = "Jatekkonzol";

public:
    Console(std::string name, int price, std::string manufacturer, int storage);
    void print();
};

#endif