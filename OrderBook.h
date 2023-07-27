#pragma once

#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <string> 
#include <vector>

class OrderBook
{
    public:
        OrderBook(std::string fileName);
        std::vector<std::string> getKnownProducts();
        std::vector<OrderBookEntry> getOrders(OrderBookType type, std::string product, std::string timestamp);

    private:
        std::vector<OrderBookEntry> orders;

};