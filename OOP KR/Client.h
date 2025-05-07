#pragma once
#include "Human.h"
#include "Stock.h"

class Client : public Human {
private:
    char company[50];
    char address[100];
    Stock* products;   // Dynamic array of Stock (products ordered)
    int productCount;  // Number of products
    float totalToPay;

public:
    Client();
    Client(char* FName, char* LName, char* PhoneNumber, char* Email, char* Company, char* Address);
    ~Client();
    void AddProduct(Stock product);
    void CalculateTotal();
    void PrintClient();
};