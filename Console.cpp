#include "Console.hpp"

Console::Console(std::string name, int price, std::string manufacturer, int quantity, int storage) : Product(name, price, manufacturer, quantity), storage(storage) {}

void Console::print()
{
    std::cout << "Termek tipusa: " << type << std::endl;
    std::cout << "Termek gyartoja: " << getManufacturer() << std::endl;
    std::cout << "Termek neve: " << getName() << std::endl;
    std::cout << "Termek hattertar merete: " << storage << " GB" << std::endl;
    std::cout << "Keszleten: " << getQuantity() << " db" << std::endl;
    std::cout << "AR: " << getPrice() << " Ft" << std::endl;
    std::cout << std::endl;
}