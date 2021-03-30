#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include "Product.hpp"
#include "JSON.hpp"

class Console : public Product
{
private:
    const int storage;
    std::string type = "Jatekkonzol";

public:
    Console(std::string name, int price, std::string manufacturer, int quantity, int storage);
    void print();
    static Console ParseConsole(const std::string &fileName);
    void generateTxt(std::string fileName);
};

#endif