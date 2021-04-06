#ifndef PHONE_HPP
#define PHONE_HPP

#include "Product.hpp"
#include "JSON.hpp"

class Phone : public Product
{
private:
    int ramSize;
    std::string opSystem;
    std::string type = "Mobiltelefon";

public:
    Phone(std::string name, int price, std::string manufacturer, int quantity, int ramSize, std::string opSystem);
    void print();
    static Phone ParsePhone(const std::string &fileName);
    int getRamSize() const ;
    std::string getOpsystem() const ;
    void generateTxt(std::string fileName);
    void generateJson();
};

#endif