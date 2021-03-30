#include "Console.hpp"

Console::Console(std::string name, int price, std::string manufacturer, int quantity, int storage) 
: Product(name, price, manufacturer, quantity), storage(storage) {}

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
void Console::generateTxt(std::string fileName){
    std::fstream insertVlue;
    insertVlue.open(fileName, std::ios_base::app);
    if(insertVlue.is_open()){
    insertVlue << "Termek tipusa: " << type << std::endl;
    insertVlue << "Termek gyartoja: " << getManufacturer() << std::endl;
    insertVlue << "Termek neve: " << getName() << std::endl;
    insertVlue << "Termek hattertar merete: " << storage << " GB" << std::endl;
    insertVlue << "Keszleten: " << getQuantity() << " db" << std::endl;
    insertVlue << "AR: " << getPrice() << " Ft" << std::endl;
    insertVlue << std::endl;
    insertVlue.close();}
    else std::cerr<<"Error";
}

Console Console::ParseConsole(const std::string &fileName){
     std::ifstream inputFile(fileName);
    if (inputFile.is_open())
	{
		std::map<std::string, std::string> consoleValues;
		consoleValues = JSON::Parse(inputFile);

		std::string name = consoleValues["name"];
		int price = std::stoi(consoleValues["price"]);
		std::string manufacturer = consoleValues["manufacturer"];
        int quantity = std::stoi(consoleValues["quantity"]);
       	int storage = std::stoi(consoleValues["storage"]);
		return Console(name, price, manufacturer,quantity,storage);
    }else{
        throw fileName;
    }
}