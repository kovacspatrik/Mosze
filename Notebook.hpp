#ifndef NOTEBOOK_HPP
#define NOTEBOOK_HPP

#include "Product.hpp"

class Notebook : public Product
{
private:
    const int ramSize;
    const double weight;
    std::string type = "Notebook";

public:
    Notebook(std::string name, int price, std::string manufacturer, int ramSize, double weight);
    int getRamSize() const;
    void print();
};

#endif