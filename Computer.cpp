#include "Computer.hpp"

Computer::Computer(std::string name, int price, std::string manufacturer, int quantity, int ramSize, int storage) : Product(name, price, manufacturer, quantity), ramSize(ramSize), storage(storage) {}
Computer::Computer() : Product("", 0, "", 0), ramSize(0), storage(0) {}

void Computer::print()
{
    std::cout << "Termek tipusa: " << type << std::endl;
    std::cout << "Termek gyartoja: " << getManufacturer() << std::endl;
    std::cout << "Termek neve: " << getName() << std::endl;
    std::cout << "Termek RAM merete: " << ramSize << " GB" << std::endl;
    std::cout << "Termek hattertar merete: " << storage << " GB" << std::endl;
    std::cout << "Keszleten: " << getQuantity() << " db" << std::endl;
    std::cout << "AR: " << getPrice() << " Ft" << std::endl;
    std::cout << std::endl;
}

Computer Computer::ParseComputer(const std::string &fileName){
    std::ifstream inputFile(fileName);
    if (inputFile.is_open())
	{
		std::map<std::string, std::string> computerValues;
		computerValues = JSON::Parse(inputFile);

		std::string name = computerValues["name"];
		int price = std::stoi(computerValues["price"]);
		std::string manufacturer = computerValues["manufacturer"];
        int quantity = std::stoi(computerValues["quantity"]);
        int ramSize = std::stoi(computerValues["ramSize"]);
       	int storage = std::stoi(computerValues["storage"]);
		return Computer(name, price, manufacturer,quantity,ramSize,storage);
    }else{
        throw fileName;
    }
}