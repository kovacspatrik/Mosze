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

Warehouse Warehouse::ParseWarehouse(const std::string &fileName){
    std::string StrFile = "warehouses/"+fileName;
    std::ifstream inputFile(StrFile);
    if (inputFile.is_open())
	{
        std::cout << "Megnyitja a file-t \n"; 
		std::map<std::string, std::string> warehouseValues;
		warehouseValues = JSON::Parse(inputFile);
		std::string name = warehouseValues["name"];
		return Warehouse(name);
    }else{
        throw fileName;
    }
}