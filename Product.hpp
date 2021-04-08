/**
 * \class Product
 * 
 * \brief Product class
 * 
 * This is the Product class, this is the parent class of the Computer, Console, Notebook, and Phone classes
 * 
 * \version 1.0
 * 
 * \author R4ktarV4adasz0k team
 * 
 * \date 2021/04/08 9:05
 * 
 * Created on: 2021/04/08 9:05
*/

#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

class Product
{
public:
    Product(std::string name, int price, std::string manufacturer, int quantity); ///< Product constructor, that puts the input parameters to the data members
    Product();                                                                    ///< Product constructor, that generates a product object with no attributes

    /** \brief Get the name of the product
      * \param none
      * \return the name of the product
    */
    std::string getName() const;

    /** \brief Get the price of the product
      * \param none
      * \return the price of the product
    */
    int getPrice() const;

    /** \brief Get the manufacturer of the product
      * \param none
      * \return the manufacturer of the product
    */
    std::string getManufacturer() const;
    virtual void print() = 0; ///< Virtual function that prints the attributes of a product
    void printName() const;   ///< Function that prints the name of a product

    /** \brief Generates a txt file from the given file
      * \param fileName reference to a constant string
    */
    virtual void generateTxt(std::string fileName) = 0;

    /** \brief Generates a JSON file from the given file
      * \param none
    */
    virtual void generateJson() = 0;

    /** \brief Fucntion that changes the price of a product
      * \param newPrice the new price of the product
    */
    void changePrice(int newPrice);

    /** \brief Get the quantity of the product
      * \param none
      * \return the quantity of the product
    */
    int getQuantity() const;

    /** \brief Fucntion that changes the quantity of a product
      * \param newQuantity the new quantity of the product
    */
    void changeQuantity(int newQuantity);

    virtual ~Product() = default; ///< Destructor of the product class

    /** \brief gives back the type of the object
      * \param none
      * \return the type of the object
    */
    virtual std::string getType() const = 0;
    void setPrice(int p);    ///< Setter function for a product's price
    void setQuantity(int q); ///< Setter function for a product's quantity
private:
    std::string name;         ///< The name of the product
    int price;                ///< The price of the product
    std::string manufacturer; ///< The manufacturer of the product
    int quantity;             ///< The quantity in stock of the product
    std::string type;         ///< The type of the product
};

#endif