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

   // std::string file1 = argv[1];
   // std::string file2 = argv[2];
   // std::string file3 = argv[3];
   // std::string file4 = argv[4]; 


   // Notebook n = Notebook::ParseNotebook(file1);
    //Computer c = Computer::ParseComputer(file2);
   // Console cns = Console::ParseConsole(file3);
    //Phone p = Phone::ParsePhone(file4);

    //Raktar.addToStorage(&n);
    //Raktar.addToStorage(&c);
   // Raktar.addToStorage(&cns);
   // Raktar.addToStorage(&p); 

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

    /*Warehouse Raktar("Elektronikai termekek");
     Phone t1("Iphone X", 500000, "Apple", 14, 3, "IOS");
    Notebook t2("Vivobook s14", 260000, "Asus", 15, 16, 1.5);
    Computer t3("Predator", 750000, "Acer", 16, 32, 1000);
    Computer t4("Playstation 5", 190000, "Sony", 17, 32, 1000); */

    /* Raktar.addToStorage(&p1);
    Raktar.addToStorage(&n1);
    Raktar.addToStorage(&cns1);
    Raktar.addToStorage(&c1); */

    Raktar.print();

   /*   int num = 0;
     while (num!=6){
        cout << "MENU:\n";
        cout << "1: UJ TERMEK FELVETELE\n";
        cout << "2: TERMEK SZERKESZTESE\n";
        cout << "3: TERMEK TORLESE\n";
        cout << "4: JSON FAJL GENERALASA\n";
        cout << "5: AKTUALIS ALLAPOT MENTESE FAJLBA\n";
        cout << "6: KILEPES\n";
        cin >> num;
        switch (num)
        {
        case 1:
            cout << "Hamarosan...\n";
            break;
        case 2:
            cout << "Hamarosan...\n";
            break;
        case 3:
            cout << "Hamarosan...\n";
            break;
        case 4:
            cout << "Hamarosan...\n";
            break;
        case 5:
            cout << "Hamarosan...\n";
            break;
        case 6:
            break;
        }
    } */
    //Memory Clear
for (auto p : Raktar.getStorage())
   {
     delete p;
   } 
   Raktar.getStorage().clear();
return 0;
}