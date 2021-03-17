#include "Warehouse.hpp"

Warehouse::Warehouse(std::string name) : name(name) {}

std::string Warehouse::getName() const { return name; }

void Warehouse::print() const
{
    std::cout << "RAKTAR NEVE: " << name << "\n";
    std::cout << "-------------------\n";
    for (Product *k : storage)
    {
        k->print();
    }
    std::cout << "\n";
}

void Warehouse::addToStorage(Product *p)
{
    storage.push_back(p);
}