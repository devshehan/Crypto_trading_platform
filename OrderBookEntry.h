#pragma once
#include <string>
#include <iostream>

enum class OrderBookType{ask,bid,unknown};

class OrderBookEntry
{
    public:
        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;

    public:
        OrderBookEntry(double _price, double _amount, std::string _timestamp, std::string _product, OrderBookType _orderType);
        
        static OrderBookType stringToOrderBookType(std::string s);

        static bool compareByTimeStamp(OrderBookEntry& e1, OrderBookEntry& e2)
        {
            return e1.timestamp < e2.timestamp;
        }
};
