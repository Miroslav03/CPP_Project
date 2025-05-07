#include "Human.h"
#include <iostream>
#include <cstring>

Human::Human() {
    strcpy_s(fname, "John");
    strcpy_s(lname, "Doe");
    strcpy_s(phonenumber, "000-000-0000");
    strcpy_s(email, "example@email.com");
}

Human::Human(char* FName, char* LName, char* PhoneNumber, char* Email) {
    strcpy_s(fname, FName);
    strcpy_s(lname, LName);
    strcpy_s(phonenumber, PhoneNumber);
    strcpy_s(email, Email);
}

void Human::PrintHuman() {
    printf("First Name: %s\n", fname);
    printf("Last Name: %s\n", lname);
    printf("Phone Number: %s\n", phonenumber);
    printf("Email: %s\n", email);
}