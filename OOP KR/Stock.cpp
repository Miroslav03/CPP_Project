#include "Stock.h"
#include <iostream>
#include <cstring>

Stock::Stock()
{
    strcpy_s(name, "aaa");
    price = 0;
    count = 0;
    total = CalculateTotal();
}

Stock::Stock(char* Name, float Price, int Count)
{
    strcpy_s(name, Name);
    price = Price;
    count = Count;
    total = CalculateTotal();
}

void Stock::PrintStock()
{
    printf("Name: %s\n", name);
    printf("Price: %.2f\n", price);
    printf("Count: %d\n", count);
    printf("Total: %.2f\n", total);

}