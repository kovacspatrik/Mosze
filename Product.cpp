#include "Product.hpp"

Product::Product(std::string name, int price, std::string manufacturer) : name(name), price(price), manufacturer(manufacturer) {}

std::string Product::getName() const
{
    return name;
}

int Product::getPrice() const
{
    return price;
}

std::string Product::getManufacturer() const
{
    return manufacturer;
}

void Product::changePrice(int newPrice)
{
    if (newPrice > 0)
    {
        price = newPrice;
    }
}
