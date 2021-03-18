#include "Notebook.hpp"

Notebook::Notebook(std::string name, int price, std::string manufacturer, int ramSize, double weight) : Product(name, price, manufacturer), ramSize(ramSize), weight(weight) {}

void Notebook::print()
{
    std::cout << "Termek tipusa: " << type << std::endl;
    std::cout << "Termek gyartoja: " << getManufacturer() << std::endl;
    std::cout << "Termek neve: " << getName() << std::endl;
    std::cout << "Termek RAM merete: " << ramSize << " GB" << std::endl;
    std::cout << "Termek sulya: " << weight << " kg" << std::endl;
    std::cout << "AR: " << getPrice() << " Ft" << std::endl;
    std::cout << std::endl;
}