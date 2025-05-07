#pragma once
#include "TradeRep.h"
#include "Client.h"
#include "Stock.h"

class Storage
{
private:
    char name[50];
    TradeRep *tradeReps; // Dynamic array of TradeReps
    int tradeRepCount;

    Client *clients; // Dynamic array of Clients
    int clientCount;

    Stock *stocks; // Dynamic array of Stock
    int stockCount;

public:
    Storage();
    Storage(char *Name);
    ~Storage();

    void AddTradeRep(TradeRep tradeRep);
    void AddClient(Client client);
    void AddStock(Stock stock);

    void PrintStorage();
    void PrintClients() const;

    Stock *FindStock(const char *key) const;

    // Calculate total turnover for the day
    double CalculateDailyTurnover() const;
};
