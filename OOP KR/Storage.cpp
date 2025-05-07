#include "Storage.h"
#include <stdio.h>
#include <string.h>

Storage::Storage()
{
    strcpy_s(name, "Unnamed Storage");
    tradeReps = nullptr;
    tradeRepCount = 0;
    clients = nullptr;
    clientCount = 0;
    stocks = nullptr;
    stockCount = 0;
}

Storage::Storage(char *Name)
{
    strcpy_s(name, Name);
    tradeReps = nullptr;
    tradeRepCount = 0;
    clients = nullptr;
    clientCount = 0;
    stocks = nullptr;
    stockCount = 0;
}

Storage::~Storage()
{
    delete[] tradeReps;
    delete[] clients;
    delete[] stocks;
}

void Storage::AddTradeRep(TradeRep tradeRep)
{
    TradeRep *newTradeReps = new TradeRep[tradeRepCount + 1];
    for (int i = 0; i < tradeRepCount; ++i)
    {
        newTradeReps[i] = tradeReps[i];
    }
    newTradeReps[tradeRepCount] = tradeRep;

    delete[] tradeReps;
    tradeReps = newTradeReps;
    tradeRepCount++;
}

void Storage::AddClient(Client client)
{
    Client *newClients = new Client[clientCount + 1];
    for (int i = 0; i < clientCount; ++i)
    {
        newClients[i] = clients[i];
    }
    newClients[clientCount] = client;

    delete[] clients;
    clients = newClients;
    clientCount++;
}

void Storage::AddStock(Stock stock)
{
    Stock *newStocks = new Stock[stockCount + 1];
    for (int i = 0; i < stockCount; ++i)
    {
        newStocks[i] = stocks[i];
    }
    newStocks[stockCount] = stock;

    delete[] stocks;
    stocks = newStocks;
    stockCount++;
}

void Storage::PrintStorage()
{
    printf("Storage Name: %s\n", name);

    printf("\n--- Trade Representatives ---\n");
    for (int i = 0; i < tradeRepCount; ++i)
    {
        tradeReps[i].PrintHuman();
    }

    printf("\n--- Clients ---\n");
    for (int i = 0; i < clientCount; ++i)
    {
        clients[i].PrintClient();
    }

    printf("\n--- Stocks ---\n");
    for (int i = 0; i < stockCount; ++i)
    {
        stocks[i].PrintStock();
    }
}

void Storage::PrintClients() const
{
    for (int i = 0; i < clientCount; ++i)
        clients[i].PrintClient();
}

Stock *Storage::FindStock(const char *key) const
{
    for (int i = 0; i < stockCount; ++i)
    {
        if (strcmp(stocks[i].name, key) == 0)
            return &stocks[i];
    }
    return NULL;
}

double Storage::CalculateDailyTurnover() const
{
    double turnover = 0.0;
    for (int i = 0; i < stockCount; ++i)
    {
        turnover += stocks[i].CalculateTotal();
    }
    return turnover;
}
