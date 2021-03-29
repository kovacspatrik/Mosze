#ifndef WAREHOUSE_HPP
#define WAREHOUSE_HPP

#include <iostream>
#include <vector>
#include "Product.hpp"
#include "JSON.hpp"

class Warehouse
{
private:
    std::string name;
    std::vector<Product *> storage;

public:
    Warehouse(std::string name);
    std::string getName() const;
    void print() const;
    void addToStorage(Product *p);
    std::vector<Product*> getStorage();
    static Warehouse ParseWarehouse(const std::string &fileName);
};

#endif