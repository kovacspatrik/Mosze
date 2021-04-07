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
    void makeFile();
    void addToStorage(Product *p);
    void removeFromStorage(int index);
    std::vector<Product*> getStorage();
    static Warehouse ParseWarehouse(const std::string &fileName);
    int selectByType(int type) const;
    void modifyIteminStorage(int index);
    void createNewItem(int idx);
    void writeJSON(std::string filename, std::string readSablon);
};

#endif