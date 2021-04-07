#include "Warehouse.hpp"

Warehouse::Warehouse(std::string name) : name(name) {}

std::string Warehouse::getName() const { return name; }

void Warehouse::print() const
{
    std::cout << "RAKTAR NEVE: " << name << "\n";
    std::cout << "-------------------\n";
    for (Product *k : storage)
    {
        k->print();
    }
}

void Warehouse::makeFile()
{
    std::string fileName ="outputfile.txt";
    std::ofstream myFile(fileName);
    if (myFile.is_open()){
    myFile << "RAKTAR NEVE: " << name << "\n";
    myFile << "-------------------\n";
    myFile.close();
    for (Product *k : storage)
    {
        k->generateTxt(fileName);
    }
    }
    else std::cout<<"Nem tudtuk megnyitni!";
}

void Warehouse::addToStorage(Product *p)
{
    storage.push_back(p);
}

void Warehouse::removeFromStorage(int index){
    std::vector<Product*>::iterator it = (storage.begin()+(index));
    storage.erase(it);
}

Warehouse Warehouse::ParseWarehouse(const std::string &fileName){
    std::string StrFile = "warehouses/"+fileName;
    std::ifstream inputFile(StrFile);
    if (inputFile.is_open())
	{
        std::cout << "Megnyitja a file-t \n"; 
		std::map<std::string, std::string> warehouseValues;
		warehouseValues = JSON::Parse(inputFile);
		std::string name = warehouseValues["name"];
		return Warehouse(name);
    }else{
        throw fileName;
    }
}
std::vector<Product*> Warehouse::getStorage(){
    return this->storage;
}

int Warehouse::selectByType(int type) const
{
    std::string tipus="";
    int valasz = 0;
    int counter = 1;
    int index = 0;
    switch (type)
    {
    case 1:
        tipus = "PC"; 
        break;
    case 2:
        tipus = "Jatekkonzol"; 
        break;
    case 3:
        tipus = "Notebook"; 
        break;
    case 4:
        tipus = "Mobiltelefon"; 
        break;
    default:
        std::cout<< "Hiba\n";
        break;
    }
    std::cout << "-------------------\n";
    for (Product *k : storage)
    {
        if(k->getType().compare(tipus) == 0){
            std::cout << counter <<" ";
            k->printName();
            counter++;
        }
    }
    std::cout << "-------------------\n";
    std::cout << "\nAdja meg melyik termeket valasztja: ";
    std::cin >> valasz;
    if(valasz==0){
        return 0;
    }
    counter = 1;
    for (Product *k : storage)
    {
        if((k->getType().compare(tipus) == 0)){
            if( counter == valasz){
                auto it = std::find(storage.begin(), storage.end(),  k);
                index = it - storage.begin();
                return index;
                }
            counter++;
            } 
    }
    return index;
}

void Warehouse::modifyIteminStorage(int index){
    int valasz = 0;
    //ar vagy mennyiseg
    std::cout<<"Arat vagy mennyiseget szeretne modositani?\n";
    std::cout<<"1. Ar\n";
    std::cout<<"2. Mennyiseg\n";
    std::cout<<"3. Visszalepes\n";
    std::cin >> valasz;
    if(valasz==3){
        return;
    }
    if(valasz==1){
        double n_price = 0.0;
        std::cout<<"Kerem adja meg az uj arat:";
        std::cin >> n_price;
        storage.at(index)->setPrice(n_price);
        return;
    }
    if(valasz==2){
        int n_q = 0.0;
        std::cout<<"Kerem adja meg az uj mennyiseget:";
        std::cin >> n_q;
        storage.at(index)->setQuantity(n_q);
        return;
    }
}

void Warehouse::createNewItem(int indx)
{
    std::string writeFile, readSablon, filename;

    std::fstream modInput;
    modInput.open("input.txt", std::ios_base::app);

    std::cout << "Kerem adja meg a temek nevet szokozok nelkul: " << std::endl;
    std::cin >> filename;
    std::cout << "Adja meg a termek adatait!" << std::endl;

    if (indx == 1)
    {
        readSablon = "computers/computers.txt";
        writeFile = "computers/" + filename + ".json";
        modInput << std::endl;
        modInput << writeFile;
        writeJSON(writeFile, readSablon);
    }

    else if (indx == 2)
    {
        readSablon = "consoles/consoles.txt";
        writeFile = "consoles/" + filename + ".json";
        modInput << std::endl;
        modInput << writeFile;

        writeJSON(writeFile, readSablon);
    }

    else if (indx == 3)
    {
        readSablon = "notebooks/notebooks.txt";
        writeFile = "notebooks/" + filename + ".json";
        modInput << std::endl;
        modInput << writeFile;

        writeJSON(writeFile, readSablon);
    }

    else
    {
        readSablon = "phones/phones.txt";
        writeFile = "phones/" + filename + ".json";
        modInput << std::endl;
        modInput << writeFile;

        writeJSON(writeFile, readSablon);
    }
}

void Warehouse::writeJSON(std::string writeFile, std::string readSablon)
{
    std::string myText, value;

    std::ifstream readFile;

    std::ofstream file;

    std::string line;
    int i,j;
    j=1;
    readFile.open(readSablon);
    for (i = 0; std::getline(readFile, line); ++i);
    readFile.close();

    readFile.open(readSablon);
    file.open(writeFile);
    file << "{";
    file << std::endl;
    while (getline(readFile, myText))
    {
        std::cout << myText << ":";
        std::cin >> value;
        file <<"\"" << myText << "\"" << ": \"" << value << "\"";
        if(j<i){
            file << ",";
        } 
        file << std::endl;
        ++j;
    }
    file << "}";
    readFile.close();
    file.close();
}