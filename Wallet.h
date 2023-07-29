#pragma once
#include <string>
#include <map>

class Wallet
{
    public:
        Wallet();

        /** insert currency into the wallet */
        void insertCurrency(std::string type, double amount);
        bool containsCurrency(std::string type, double amount);
        
        bool removeCurrency(std::string type, double amount);
        std::string toString();

    private:
        std::map<std::string,double> currencies;  
};