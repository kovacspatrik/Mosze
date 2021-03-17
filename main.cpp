#include <iostream>
#include <vector>
#include "Product.hpp"
#include "Warehouse.hpp"

using namespace std;

int main()
{
    Warehouse Raktar("Ajtok");
    Product t1("AJTO1", 100000, "ELSOGYARTO");
    Product t2("AJTO2", 200000, "MASODIKGYARTO");
    Raktar.addToStorage(&t1);
    Raktar.addToStorage(&t2);
    Raktar.print();
    return 0;
}