#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <iostream>
#include <string>

class Product
{
public:
    Product(std::string name, int quantity);
    std::string getName() const;
    int getQuantity() const;
    void print() const;
    void addQuantity(int num);
    void reduceQuantity(int num);

private:
    std::string name;
    int quantity;
};

#endif