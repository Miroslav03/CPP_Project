// main.cpp
#include "Storage.h"
#include "TradeRep.h"
#include "Client.h"
#include "Stock.h"
#include <stdio.h>
#include <string.h>

int main() {
    Storage storage("My Warehouse");

    char s1[20] = "Laptop";
    Stock prod1(s1, 999.99f, 1);
    storage.AddStock(prod1);

    char s2[20] = "Dock";
    Stock prod2(s2, 149.99f, 2);
    storage.AddStock(prod2);

    Client* client1 = new Client((char*)"Bob", (char*)"Johnson", (char*)"222-333-4444", (char*)"bob@company.com",
                                 (char*)"BizTech", (char*)"456 Business Rd");
    client1->AddProduct(prod1);
    client1->AddProduct(prod2);
    client1->CalculateTotal();
    storage.AddClient(*client1);

    TradeRep rep((char*)"Karen", (char*)"Taylor", (char*)"555-111-9999", (char*)"karen@trades.com");
    rep.AddClient(client1);
    storage.AddTradeRep(rep);

    const char* queryName = "Laptop";
    int queryQty = 1;
    printf("\n--- Реализиране на заявка ---\n");
    printf("Име на стоката: %s\n", queryName);
    printf("Количество: %d\n", queryQty);

    Stock* queried = storage.FindStock(queryName);
    if (queried && queried->count >= queryQty) {
        float cost = queried->price * queryQty;
        queried->count -= queryQty;
        printf("Заявката е реализирана. Цена: %.2f\n", cost);
    } else {
        printf("Няма достатъчно стока или не съществува такъв артикул.\n");
    }

    printf("\n--- Информация за склада ---\n");
    storage.PrintStorage();

    printf("\n--- Търговски представител и клиенти ---\n");
    rep.PrintHuman();
    rep.PrintClients();

    delete client1;
    return 0;
}
