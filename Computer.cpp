#include "Computer.hpp"

Computer::Computer(std::string name, int price, std::string manufacturer, int quantity, int ramSize, int storage) : Product(name, price, manufacturer, quantity), ramSize(ramSize), storage(storage) {}


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
void Computer::generateTxt(std::string fileName){
    std::fstream insertVlue;
    insertVlue.open(fileName, std::ios_base::app);
    if(insertVlue.is_open()){
    insertVlue << "Termek tipusa: " << type << std::endl;
    insertVlue << "Termek gyartoja: " << getManufacturer() << std::endl;
    insertVlue << "Termek neve: " << getName() << std::endl;
    insertVlue << "Termek RAM merete: " << ramSize << " GB" << std::endl;
    insertVlue << "Termek hattertar merete: " << storage << " GB" << std::endl;
    insertVlue << "Keszleten: " << getQuantity() << " db" << std::endl;
    insertVlue << "AR: " << getPrice() << " Ft" << std::endl;
    insertVlue << std::endl;
    insertVlue.close();
    }
    
    else std::cerr<<"Error";
}

void Computer::generateJson(){
    std::string filename = this->getName();
    std::string::iterator end_pos = std::remove(filename.begin(), filename.end(), ' ');
    filename.erase(end_pos, filename.end());
    filename = "computers/"+filename + ".json";
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
    MyFile <<"\"ramSize\":\"" ;
    MyFile << this->getRamsize() ;
    MyFile <<"\",\n ";
    MyFile <<"\"storage\":\"";
    MyFile <<this->getStorage() ;
    MyFile <<"\"\n }";

    MyFile.close();
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
int Computer::getRamsize(){
    return this->ramSize;
}
    
int Computer::getStorage(){
    return this->storage;
}
std::string Computer::getType() const
{
    return this->type;
}