/**
 * \class Computer
 * 
 * \brief Computer class
 * 
 * This is the Computer class, which is inherited from the Product class and has the attributes for a computer type product
 * 
 * \version 1.0
 * 
 * \author R4ktarV4adasz0k team
 * 
 * \date 2021/04/08 9:05
 * 
 * Created on: 2021/04/08 9:05
*/

#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "Product.hpp"
#include "string.h"
#include <algorithm>
#include "JSON.hpp"
#include <iostream>
class Computer : public Product
{
private:
    const int ramSize;       ///< The amount of RAM in the Computer (in gigabytes)
    const int storage;       ///< The amount of storage in the Computer (in gigabytes)
    std::string type = "PC"; ///< The type of the Computer

public:
    Computer(std::string name, int price, std::string manufacturer, int quantity, int ramSize, int storage); ///< Computer constructor, that puts the input parameters to the data members
    void print();                                                                                            ///< Function that prints the attributes of a computer

    /** \brief Get size of RAM in the computer
      * \param none
      * \return the amount of RAM in gigabytes
    */
    int getRamsize();

    /** \brief Get the size of storage in the computer
      * \param none
      * \return the size of storage in gigabytes
    */
    int getStorage();

    /** \brief Parse a computer object from file
      * \param fileName reference to a constant string
      * \return the computer object made with the given attributes
    */
    static Computer ParseComputer(const std::string &fileName);

    /** \brief Generates a txt file from the given file
      * \param fileName reference to a constant string
    */
    void generateTxt(std::string fileName);

    /** \brief Generates a JSON file from the given file
      * \param none
    */
    void generateJson();

    /** \brief gives back the type of the object
      * \param none
      * \return the type of the object
    */
    std::string getType() const;
};

#endif