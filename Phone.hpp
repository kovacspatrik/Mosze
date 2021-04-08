/**
 * \class Phone
 * 
 * \brief Phone class
 * 
 * This is the Phone class, which is inherited from the Product class and has the attributes for a phone type product
 * 
 * \version 1.0
 * 
 * \author R4ktarV4adasz0k team
 * 
 * \date 2021/04/08 9:05
 * 
 * Created on: 2021/04/08 9:05
*/

#ifndef PHONE_HPP
#define PHONE_HPP

#include "Product.hpp"
#include "JSON.hpp"

class Phone : public Product
{
private:
    int ramSize;                       ///< The amount of RAM in the phone (in gigabytes)
    std::string opSystem;              ///< The operating system of the phone
    std::string type = "Mobiltelefon"; ///< The type of the phone

public:
    Phone(std::string name, int price, std::string manufacturer, int quantity, int ramSize, std::string opSystem); ///< Phone constructor, that puts the input parameters to the data members
    void print();                                                                                                  ///< Function that prints the attributes of a phone

    /** \brief Parse a phone object from file
      * \param fileName reference to a constant string
      * \return the phone object made with the given attributes
    */
    static Phone ParsePhone(const std::string &fileName);

    /** \brief Get size of RAM in the phone
      * \param none
      * \return the amount of RAM in gigabytes
    */
    int getRamSize() const;

    /** \brief Get the operating system of the phone
      * \param none
      * \return the type of the operating system
    */
    std::string getOpsystem() const;

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