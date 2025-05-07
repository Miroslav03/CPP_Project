#pragma once
struct Stock {
    char name[20];
    float price;
    int count;
    float total;
public:
    Stock();
    Stock(char* Name, float Price, int Count);
    float CalculateTotal() { return count * price; };
    void PrintStock();

};