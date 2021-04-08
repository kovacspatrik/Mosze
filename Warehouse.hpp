/**
 * \class Warehouse
 * 
 * \brief Warehouse class
 * 
 * This is the Warehouse class, which is having a list of all our products in stock.
 * 
 * \version 1.0
 * 
 * \author R4ktarV4adasz0k team
 * 
 * \date 2021/04/08 9:05
 * 
 * Created on: 2021/04/08 9:05
*/

#ifndef WAREHOUSE_HPP
#define WAREHOUSE_HPP

#include <iostream>
#include <vector>
#include "Product.hpp"
#include "JSON.hpp"

class Warehouse
{
private:
    std::string name;               ///< the name of the warehouse
    std::vector<Product *> storage; ///< the vector that includes all the products in stock
public:
    Warehouse(std::string name); ///< Warehouse class constructor

    /// This is a constant getter function for the name
    std::string getName() const;
    void print() const;                                           ///< Print function for Warehouse class
    void makeFile();                                              ///< Function that writes outputfile.txt
    void addToStorage(Product *p);                                ///< Function that adds a new item to the list
    void removeFromStorage(int index);                            ///< Function that removes an item from the list
    std::vector<Product *> getStorage();                          ///< Function that returns the memory address of a Warehouse object's vector
    static Warehouse ParseWarehouse(const std::string &fileName); ///< Function that can parse every object from a given file
    int selectByType(int type) const;                             ///< Function that helps the user select the product type what he's searching for
    void modifyIteminStorage(int index);                          ///< Function that can change the price or the quantity of an item
    void createNewItem(int idx);                                  ///< Function that creates a new item in storage
    void writeJSON(std::string filename, std::string readSablon); ///< Function that writes a JSON file out of the storage
};

#endif