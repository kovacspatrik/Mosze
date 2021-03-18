#ifndef PHONE_HPP
#define PHONE_HPP

#include "Product.hpp"

class Phone : public Product
{
private:
    int ramSize;
    std::string opSystem;
    std::string type = "Mobiltelefon";

public:
    Phone(std::string name, int price, std::string manufacturer, int ramSize, std::string opSystem);
    int getRamSize() const;
    void print();
};

#endif