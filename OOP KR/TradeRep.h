#pragma once
#include "Human.h"
#include "Client.h"

class TradeRep : public Human {
private:
    Client** clients;     // Array of pointers to Client
    int clientCount;      // Number of clients

public:
    TradeRep();
    TradeRep(char* FName, char* LName, char* PhoneNumber, char* Email);
    ~TradeRep();

    void AddClient(Client* client);
    void PrintClients();
};