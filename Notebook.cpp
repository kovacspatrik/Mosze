#include "Notebook.hpp"


Notebook::Notebook(std::string name, int price, std::string manufacturer, int quantity, int ramSize, double weight) 
: Product(name, price, manufacturer, quantity), ramSize(ramSize), weight(weight) {}

void Notebook::print()
{
    std::cout << "Termek tipusa: " << type << std::endl;
    std::cout << "Termek gyartoja: " << getManufacturer() << std::endl;
    std::cout << "Termek neve: " << getName() << std::endl;
    std::cout << "Termek RAM merete: " << ramSize << " GB" << std::endl;
    std::cout << "Termek sulya: " << weight << " kg" << std::endl;
    std::cout << "Keszleten: " << getQuantity() << " db" << std::endl;
    std::cout << "AR: " << getPrice() << " Ft" << std::endl;
    std::cout << std::endl;
}

void Notebook::generateTxt(std::string fileName){
    std::fstream insertVlue;
    insertVlue.open(fileName, std::ios_base::app);
    if(insertVlue.is_open()){
    insertVlue << "Termek tipusa: " << type << std::endl;
    insertVlue << "Termek gyartoja: " << getManufacturer() << std::endl;
    insertVlue << "Termek neve: " << getName() << std::endl;
    insertVlue << "Termek RAM merete: " << ramSize << " GB" << std::endl;
    insertVlue << "Termek sulya: " << weight << " kg" << std::endl;
    insertVlue << "Keszleten: " << getQuantity() << " db" << std::endl;
    insertVlue << "AR: " << getPrice() << " Ft" << std::endl;
    insertVlue << std::endl;
    insertVlue.close();
    }
    
    else std::cerr<<"Error";
}

Notebook Notebook::ParseNotebook(const std::string &fileName){
     std::ifstream inputFile(fileName);
    if (inputFile.is_open())
	{
		std::map<std::string, std::string> notebookValues;
		notebookValues = JSON::Parse(inputFile);

		std::string name = notebookValues["name"];
		int price = std::stoi(notebookValues["price"]);
		std::string manufacturer = notebookValues["manufacturer"];
        int quantity = std::stoi(notebookValues["quantity"]);
       	int ramSize = std::stoi(notebookValues["ramSize"]);
        double weight = std::stod(notebookValues["weight"]);
		return Notebook(name, price, manufacturer,quantity,ramSize,weight);
    }else{
        throw fileName;
    }
}