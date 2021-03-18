#include "Computer.hpp"

Computer::Computer(std::string name, int price, std::string manufacturer, int ramSize, int storage) : Product(name, price, manufacturer), ramSize(ramSize), storage(storage) {}

void Computer::print()
{
    std::cout << "Termek tipusa: " << type << std::endl;
    std::cout << "Termek gyartoja: " << getManufacturer() << std::endl;
    std::cout << "Termek neve: " << getName() << std::endl;
    std::cout << "Termek RAM merete: " << ramSize << " GB" << std::endl;
    std::cout << "Termek hattertar merete: " << storage << " GB" << std::endl;
    std::cout << "AR: " << getPrice() << " Ft" << std::endl;
    std::cout << std::endl;
}