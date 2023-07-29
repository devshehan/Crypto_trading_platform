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
        void insertOrder(OrderBookEntry& order);

        /* return the earliest time in the order book*/
        std::string getEarliestTime();

        /* get the time stamp and through the orders find next time stamp
            if does not exist wrap around to the first order in the orders.
        */
        std::string getNextTime(std::string timestamp);

        static double getHighPrice(std::vector<OrderBookEntry>& orders);
        static double getLowPrice(std::vector<OrderBookEntry>& orders);

    private:
        std::vector<OrderBookEntry> orders;

};