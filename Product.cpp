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

void Product::print() const
{
    std::cout << name << ": " << price << " ft"
              << " (Gyartja: " << manufacturer << ")\n";
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
