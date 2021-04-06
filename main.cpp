#include <iostream>
#include <vector>
#include "Phone.hpp"
#include "Notebook.hpp"
#include "Computer.hpp"
#include "Console.hpp"
#include "Warehouse.hpp"
#include "JSON.hpp"

using namespace std;

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
        //Raktar.makeFile();
        //Raktar.print();
        Raktar.getStorage().at(0)->generateJson();
    }
    else{
        int num = 0;
        while (num!=6){
            cout << "MENU:\n";
            cout << "1: UJ TERMEK FELVETELE\n";
            cout << "2: TERMEK SZERKESZTESE\n";
            cout << "3: TERMEK TORLESE\n";
            cout << "4: KILEPES\n";
            cin >> num;
            
            if(num==1){
                cout << "Hamarosan...\n";
            }
            if(num==2){
                cout << "Hamarosan...\n";
            }
            if(num==3){
                cout << "Hamarosan...\n";
            }
            if(num==4){
                cout << "Viszlat\n";
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