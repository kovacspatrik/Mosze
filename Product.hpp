#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

class Product
{
public:
    Product(std::string name, int price, std::string manufacturer, int quantity);
    Product();
    std::string getName() const;
    int getPrice() const;
    std::string getManufacturer() const;
    virtual void print() = 0;
    virtual void generateTxt(std::string fileName) = 0;
    virtual void generateJson() = 0;
    void changePrice(int newPrice);
    int getQuantity() const;
    void changeQuantity(int newQuantity);
    virtual ~Product() = default;

private:
    std::string name;
    int price;
    std::string manufacturer;
    int quantity;
};

#endif