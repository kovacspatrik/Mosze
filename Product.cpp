#include "Product.hpp"

Product::Product(std::string name, int quantity) : name(name), quantity(quantity) {}

std::string Product::getName() const
{
    return name;
}

int Product::getQuantity() const
{
    return quantity;
}

void Product::print() const
{
    std::cout << name << ": " << quantity << " db\n";
}

void Product::addQuantity(int num)
{
    quantity += num;
}

void Product::reduceQuantity(int num)
{
    // quantity -= num;
    int tmp = quantity - num;
    quantity = (tmp < 0) ? 0 : tmp;
}