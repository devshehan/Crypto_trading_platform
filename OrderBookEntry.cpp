#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry(
                                double _price, 
                                double _amount, 
                                std::string _timestamp, 
                                std::string _product, 
                                OrderBookType _orderType,
                                std::string _userName)
:   price(_price), 
    amount(_amount), 
    timestamp(_timestamp), 
    product(_product), 
    orderType(_orderType),
    userName(_userName)
{

}

OrderBookType OrderBookEntry::stringToOrderBookType(std::string s)
{
    if( s == "ask")
    {
        return OrderBookType::ask;
    }
    if (s == "bid")
    {
        return OrderBookType::bid;
    }
    return OrderBookType::unknown;
}
