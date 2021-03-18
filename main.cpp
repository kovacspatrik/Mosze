#include <iostream>
#include <vector>
#include "Phone.hpp"
#include "Notebook.hpp"
#include "Computer.hpp"
#include "Console.hpp"
#include "Warehouse.hpp"

using namespace std;

int main()
{
    Warehouse Raktar("Elektronikai termekek");
    Phone t1("Iphone X", 500000, "Apple", 14, 3, "IOS");
    Notebook t2("Vivobook s14", 260000, "Asus", 15, 16, 1.5);
    Computer t3("Predator", 750000, "Acer", 16, 32, 1000);
    Computer t4("Playstation 5", 190000, "Sony", 17, 32, 1000);
    Raktar.addToStorage(&t1);
    Raktar.addToStorage(&t2);
    Raktar.addToStorage(&t3);
    Raktar.addToStorage(&t4);
    Raktar.print();
    // int num;
    // cout << "MENU:\n";
    // cout << "1: UJ TERMEK FELVETELE\n";
    // cout << "2: TERMEK SZERKESZTESE\n";
    // cout << "3: TERMEK TORLESE\n";
    // cout << "4: JSON FAJL GENERALASA\n";
    // cout << "5: AKTUALIS ALLAPOT MENTESE FAJLBA\n";
    // cout << "6: KILEPES\n";
    // cin >> num;
    // switch (num)
    // {
    // case 1:
    //     cout << "Hamarosan...\n";
    //     break;
    // case 2:
    //     cout << "Hamarosan...\n";
    //     break;
    // case 3:
    //     cout << "Hamarosan...\n";
    //     break;
    // case 4:
    //     cout << "Hamarosan...\n";
    //     break;
    // case 5:
    //     cout << "Hamarosan...\n";
    //     break;
    // case 6:
    //     break;
    // }
    return 0;
}