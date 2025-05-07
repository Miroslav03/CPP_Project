#pragma once
struct Human {
    char fname[20];
    char lname[20];
    char phonenumber[20];
    char email[40];

public:
    Human();
    Human(char* FName, char* LName, char* PhoneNumber, char* Email);
    void PrintHuman();
};