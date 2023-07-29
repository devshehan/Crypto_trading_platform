#include "Wallet.h"
#include <string>

Wallet::Wallet()
{

}


void Wallet::insertCurrency(std::string type, double amount)
{
    double balance;
    if ( amount < 0 )
    {
        throw std::exception{};
    }
    if (currencies.count(type) == 0)
    {
        balance = 0;
    }
    else
    {
        balance = currencies[type];
    }

    balance += amount;
    currencies[type] = balance;
}

bool Wallet::removeCurrency(std::string type, double amount)
{
    double balance;
    if ( amount < 0)
    {
        throw std::exception{};
    }
    if ( containsCurrency(type,amount))
    {
        currencies[type] -= amount;
        return true;
    }
    else{
        return false;
    }
}



bool Wallet::containsCurrency(std::string type, double amount)
{
    if (currencies.count(type) == 0)
    {
        return false;
    }
    else
    {
        return currencies[type] >= amount ;
    }
}

std::string Wallet::toString()
{
    std::string s;
    for(std::pair<std::string,double> e : currencies)
    {
        std::string currency = e.first;
        double amount = e.second;
        s += currency + " : " + std::to_string(amount) + "\n";
    }
    return s;
}