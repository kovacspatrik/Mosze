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
    Warehouse Raktar("Ajtok");
    Phone t1("Iphone X", 500000, "Apple", 3, "IOS");
    Notebook t2("Vivobook s14", 260000, "Asus", 16, 1.5);
    Computer t3("Predator", 750000, "Acer", 32, 1000);
    Computer t4("Playstation 5", 190000, "Sony", 32, 1000);
    Raktar.addToStorage(&t1);
    Raktar.addToStorage(&t2);
    Raktar.addToStorage(&t3);
    Raktar.addToStorage(&t4);
    Raktar.print();
    return 0;
}