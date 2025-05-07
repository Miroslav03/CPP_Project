#include "TradeRep.h"
#include "Human.h"
#include <iostream>
#include <cstring>

TradeRep::TradeRep() : Human() {
    clients = nullptr;
    clientCount = 0;
}

TradeRep::TradeRep(char* FName, char* LName, char* PhoneNumber, char* Email)
    : Human(FName, LName, PhoneNumber, Email) {
    clients = nullptr;
    clientCount = 0;
}

TradeRep::~TradeRep() {
    delete[] clients; // We are not deleting the actual Client objects, only the array of pointers
}

void TradeRep::AddClient(Client* client) {
    Client** newClients = new Client * [clientCount + 1];

    for (int i = 0; i < clientCount; ++i) {
        newClients[i] = clients[i];
    }

    newClients[clientCount] = client;

    delete[] clients;
    clients = newClients;
    clientCount++;
}

void TradeRep::PrintClients() {
    printf("Trade Representative: %s %s\n", fname, lname);
    printf("Manages %d client(s):\n", clientCount);
    for (int i = 0; i < clientCount; ++i) {
        printf("\nClient %d:\n", i + 1);
        clients[i]->PrintClient();
    }
}