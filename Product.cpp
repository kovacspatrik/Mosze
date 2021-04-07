#include "Product.hpp"

Product::Product(std::string name, int price, std::string manufacturer, int quantity) : name(name), price(price), manufacturer(manufacturer), quantity(quantity) {}

Product::Product() : name(""), price(0), manufacturer(""), quantity(0) {}

std::string Product::getName() const
{
    return name;
}

int Product::getPrice() const
{
    return price;
}

void Product::setPrice(int p){
    this->price = p;
}
void Product::setQuantity(int q){
    this->quantity = q;
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

int Product::getQuantity() const { return quantity; }

void Product::changeQuantity(int newQuantity)
{
    int tmp = quantity + newQuantity;
    if (tmp > 0)
    {
        quantity = tmp;
    }
    else
    {
        quantity = 0;
    }
}


void Product::printName() const{
    std::cout << getName() << std::endl;
}