#include <iostream>
#include <vector>
#include "Product.hpp"

using namespace std;

int main()
{
    Product t("Ajto(fa)", 10);
    Product t2("Ajto(vas)", 20);

    vector<Product *> v;
    v.push_back(&t);
    v.push_back(&t2);
    for (Product *k : v)
    {
        k->print();
    }

    t2.addQuantity(5);
    t.reduceQuantity(5);

    for (Product *k : v)
    {
        k->print();
    }

    return 0;
}