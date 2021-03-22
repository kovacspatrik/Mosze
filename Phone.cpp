#include "Phone.hpp"

Phone::Phone(std::string name, int price, std::string manufacturer, int quantity, int ramSize, std::string opSystem) 
: Product(name, price, manufacturer, quantity), ramSize(ramSize), opSystem(opSystem) {}

void Phone::print()
{
    std::cout << "Termek tipusa: " << type << std::endl;
    std::cout << "Termek gyartoja: " << getManufacturer() << std::endl;
    std::cout << "Termek neve: " << getName() << std::endl;
    std::cout << "Termek operacios rendszere: " << opSystem << std::endl;
    std::cout << "Termek RAM merete: " << ramSize << " GB" << std::endl;
    std::cout << "Keszleten: " << getQuantity() << " db" << std::endl;
    std::cout << "AR: " << getPrice() << " Ft" << std::endl;
    std::cout << std::endl;
}

Phone Phone::ParsePhone(const std::string &fileName){
    std::ifstream inputFile(fileName);
    if (inputFile.is_open())
	{
		std::map<std::string, std::string> phoneValues;
		phoneValues = JSON::Parse(inputFile);

		std::string name = phoneValues["name"];
		int price = std::stoi(phoneValues["price"]);
		std::string manufacturer = phoneValues["manufacturer"];
        int quantity = std::stoi(phoneValues["quantity"]);
        int ramSize = std::stoi(phoneValues["ramSize"]);
       	std::string opSystem = phoneValues["opSystem"];
		return Phone(name, price, manufacturer,quantity,ramSize,opSystem);
    }else{
        throw fileName;
    }
}