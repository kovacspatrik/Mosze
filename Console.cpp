#include "Console.hpp"

Console::Console(std::string name, int price, std::string manufacturer, int storage) : Product(name, price, manufacturer), storage(storage) {}

void Console::print()
{
    std::cout << "Termek tipusa: " << type << std::endl;
    std::cout << "Termek gyartoja: " << getManufacturer() << std::endl;
    std::cout << "Termek neve: " << getName() << std::endl;
    std::cout << "Termek hattertar merete: " << storage << " GB" << std::endl;
    std::cout << "AR: " << getPrice() << " Ft" << std::endl;
    std::cout << std::endl;
}