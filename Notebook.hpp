#ifndef NOTEBOOK_HPP
#define NOTEBOOK_HPP

#include "Product.hpp"
#include "JSON.hpp"


class Notebook : public Product
{
private:
    const int ramSize;
    const double weight;
    std::string type = "Notebook";

public:
    Notebook(std::string name, int price, std::string manufacturer, int quantity, int ramSize, double weight);
    int getRamSize() const;
    void print();
    double getWeight() const;
    static Notebook ParseNotebook(const std::string &fileName);
    void generateTxt(std::string fileName);
    void generateJson();
    std::string getType() const;
};

#endif