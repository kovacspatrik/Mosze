/**
 * \class Console
 * 
 * \brief Console class
 * 
 * This is the Console class, which is inherited from the Product class and has the attributes for a console type product
 * 
 * \version 1.0
 * 
 * \author R4ktarV4adasz0k team
 * 
 * \date 2021/04/08 9:05
 * 
 * Created on: 2021/04/08 9:05
*/

#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include "Product.hpp"
#include "JSON.hpp"

class Console : public Product
{
private:
    const int storage;                ///< The amount of storage in the console (in gigabytes)
    std::string type = "Jatekkonzol"; ///< The type of the console

public:
    Console(std::string name, int price, std::string manufacturer, int quantity, int storage); ///< Console constructor, that puts the input parameters to the data members
    void print();                                                                              ///< Function that prints the attributes of a console

    /** \brief Get size of storage in the console
      * \param none
      * \return the size of storage in gigabytes
    */
    int getStorage() const;

    /** \brief Parse a console object from file
      * \param fileName reference to a constant string
      * \return the console object made with the given attributes
    */
    static Console ParseConsole(const std::string &fileName);

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