#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <iostream>
#include <string>

class Product
{
public:
    Product(std::string name, int price, std::string manufacturer);
    std::string getName() const;
    int getPrice() const;
    std::string getManufacturer() const;
    virtual void print() = 0;
    void changePrice(int newPrice);

private:
    std::string name;
    int price;
    std::string manufacturer;
};

#endif