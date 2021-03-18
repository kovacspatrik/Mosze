#include <iostream>
#include <vector>
#include "Product.hpp"
#include "Phone.hpp"
#include "Warehouse.hpp"

using namespace std;

int main()
{
    Warehouse Raktar("Ajtok");
    Product t1("AJTO1", 100000, "ELSOGYARTO");
    Phone t2("Iphone X", 500000, "Apple", 3, "IOS");
    Raktar.addToStorage(&t1);
    Raktar.addToStorage(&t2);
    Raktar.print();
    return 0;
}