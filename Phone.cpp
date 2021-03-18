#include "Phone.hpp"

Phone::Phone(std::string name, int price, std::string manufacturer, int ramSize, std::string opSystem) : Product(name, price, manufacturer), ramSize(ramSize), opSystem(opSystem) {}

int Phone::getRamSize() const { return ramSize; }

void Phone::print() const
{
    std::cout << "Termek tipusa: " << type << std::endl;
    std::cout << "Termek neve: " << getName() << std::endl;
    std::cout << "Termek gyartoja: " << getManufacturer() << std::endl;
    std::cout << "Termek operacios rendszere: " << opSystem << std::endl;
    std::cout << "Termek RAM merete: " << ramSize << " GB" << std::endl;
    std::cout << "AR: " << getPrice() << " Ft" << std::endl;
}