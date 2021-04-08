/**
 * \class Notebook
 * 
 * \brief Notebook class
 * 
 * This is the Notebook class, which is inherited from the Product class and has the attributes for a notebook type product
 * 
 * \version 1.0
 * 
 * \author R4ktarV4adasz0k team
 * 
 * \date 2021/04/08 9:05
 * 
 * Created on: 2021/04/08 9:05
*/

#ifndef NOTEBOOK_HPP
#define NOTEBOOK_HPP

#include "Product.hpp"
#include "JSON.hpp"

class Notebook : public Product
{
private:
    const int ramSize;             ///< The amount of RAM in the notebook (in gigabytes)
    const double weight;           ///< The weight of the notebook
    std::string type = "Notebook"; ///< The type of the notebbok

public:
    Notebook(std::string name, int price, std::string manufacturer, int quantity, int ramSize, double weight); ///< Notebbok constructor, that puts the input parameters to the data members

    /** \brief Get size of RAM in the notebook
      * \param none
      * \return the amount of RAM in gigabytes
    */
    int getRamSize() const;
    void print(); ///< Function that prints the attributes of a notebook

    /** \brief Get weight of the notebook
      * \param none
      * \return the weight of the notebook in kilograms
    */
    double getWeight() const;

    /** \brief Parse a notebook object from file
      * \param fileName reference to a constant string
      * \return the notebook object made with the given attributes
    */
    static Notebook ParseNotebook(const std::string &fileName);

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