#include "Client.h"
#include <iostream>
#include <cstring>

Client::Client() : Human() {
    strcpy_s(company, "Unknown");
    strcpy_s(address, "Unknown");
    productCount = 0;
    totalToPay = 0.0f;
}

Client::Client(char* FName, char* LName, char* PhoneNumber, char* Email, char* Company, char* Address)
    : Human(FName, LName, PhoneNumber, Email) {
    strcpy_s(company, Company);
    strcpy_s(address, Address);
    productCount = 0;
    totalToPay = 0.0f;
}

Client::~Client() {
   delete[] products;
}

void Client::AddProduct(Stock product) {
    Stock* newProducts = new Stock[productCount + 1];
    for (int i = 0; i < productCount; i++) {
        newProducts[i] = products[i];
    }

    newProducts[productCount] = product;

    delete[] products;
    products = newProducts;
    productCount++;
}

void Client::CalculateTotal() {
    totalToPay = 0.0;
    for (int i = 0; i < productCount; i++) {
        totalToPay += products[i].CalculateTotal();
    }
}

void Client::PrintClient() {
    printf("Client Name: %s %s\n", fname, lname);
    printf("Phone Number: %s\n", phonenumber);
    printf("Email: %s\n", email);
    printf("Company: %s\n", company);
    printf("Address: %s\n", address);
    printf("Products Ordered:\n");

    for (int i = 0; i < productCount; ++i) {
        products[i].PrintStock();
    }

    printf("Total to Pay: %.2f\n", totalToPay);
}