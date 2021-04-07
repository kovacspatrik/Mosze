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

void Console::generateJson(){
    std::string filename = this->getName();
    std::string::iterator end_pos = std::remove(filename.begin(), filename.end(), ' ');
    filename.erase(end_pos, filename.end());
    filename = "consoles/" + filename + ".json";

    std::ofstream MyFile(filename);
    MyFile << "{\n\"name\":\"";
    MyFile << this->getName();
    MyFile << "\",\n";
    MyFile <<"\"price\":\"";
    MyFile << this->getPrice() ;
    MyFile <<"\",\n ";
    MyFile <<"\"manufacturer\":\"";
    MyFile << this->getManufacturer();
    MyFile << "\",\n ";
    MyFile <<"\"quantity\":\"";
    MyFile << this->getQuantity();
    MyFile <<"\",\n ";
    MyFile <<"\"storage\":\"";
    MyFile <<this->getStorage() ;
    MyFile <<"\"\n }";

    MyFile.close();
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

int Console::getStorage() const{
    return this->storage;
}
std::string Console::getType() const
{
    return this->type;
}