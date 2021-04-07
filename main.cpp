#include <iostream>
#include <vector>
#include "Phone.hpp"
#include "Notebook.hpp"
#include "Computer.hpp"
#include "Console.hpp"
#include "Warehouse.hpp"
#include "JSON.hpp"
#include "deleteMenu.hpp"
#include "typeSelection.hpp"
#include "stdio.h"

void deleteJSON(std::string filename,int tipus){
    std::string file = "";
    switch (tipus)
    {
    case 1:
        file = "computers/";
        file.append(filename);
        break;
    case 2:
        file = "consoles/";
        file.append(filename);
        break;
    case 3:
        file = "notebooks/";
        file.append(filename);
        break;
    case 4:
        file = "phones/";
        file.append(filename);
        break;
    default:
        break;
    }
    if(remove(file.c_str()) != 0 )
        perror("Error deleting file");
}

int main(int argc, char *argv[])
{
    Warehouse Raktar("Elektronikai termekek");
    std::string fileName = argv[1];
    std::ifstream file(fileName);
    std::string str;    
    while (std::getline(file, str))
    {
    if (str.find("computers/") != std::string::npos) {
        Computer *c = new Computer(Computer::ParseComputer(str));
        Raktar.addToStorage(c);

    }
    if (str.find("notebooks/") != std::string::npos) {
        Notebook *n = new Notebook(Notebook::ParseNotebook(str));
        Raktar.addToStorage(n);

    }
    if (str.find("phones/") != std::string::npos) {
        Phone *p = new Phone(Phone::ParsePhone(str));
        Raktar.addToStorage(p);

    }
    if (str.find("consoles/") != std::string::npos) {
        Console *cns = new Console(Console::ParseConsole(str));
        Raktar.addToStorage(cns);
    }
    } 
    //Csak akkor ír ki ha teszt
     if(argc>2){
        Raktar.makeFile();
        Raktar.print();
    }
    else{
        int num = 0;
        while (num!=6){
            std::cout << "-------------------\n";
            std::cout << "MENU:\n";
            std::cout << "1: UJ TERMEK FELVETELE\n";
            std::cout << "2: TERMEK SZERKESZTESE\n";
            std::cout << "3: TERMEK TORLESE\n";
            std::cout << "5: OSSZES TERMEK LISTAZASA\n";
            std::cout << "6: KILEPES\n";
            std::cin >> num;
            
            if(num==1){
                std::cout << "Hamarosan...\n";
            }
            if(num==2){//Modositas
                int valasz = typeSelectionMenu();
                int idx = Raktar.selectByType(valasz);
                Raktar.modifyIteminStorage(idx);
                Raktar.getStorage().at(idx)->generateJson();
            }
            if(num==3){//Torles
                int valasz = typeSelectionMenu();
                int idx = Raktar.selectByType(valasz);
                std::cout<<"Biztosan torli a termeket?";
                std::string name = Raktar.getStorage().at(idx)->getName();
                std::string::iterator end_pos = std::remove(name.begin(), name.end(), ' ');
                name.erase(end_pos, name.end());
                name.append(".json");
                deleteJSON(name,valasz);
                Raktar.removeFromStorage(idx);
                continue;
            }
            if(num==5){
                std::cout << "-------------------\n";
                Raktar.print();
                std::cout << "-------------------\n";
            }
            if(num==6){
                std::cout << "Viszlat\n";
                break;
            }
        }
    }
    //Memory Clear
for (auto p : Raktar.getStorage())
   {
     delete p;
   } 
   Raktar.getStorage().clear();
return 0;
}

