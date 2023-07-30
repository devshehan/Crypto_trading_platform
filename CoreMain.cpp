#include "CoreMain.h"
#include <iostream>
#include <vector>
#include <limits>
#include "CSVReader.h"

CoreMain::CoreMain()
{

}

void CoreMain::init()
{
    int input;
    current_time = orderbook.getEarliestTime();

    wallet.insertCurrency("USDT",4000);

    while(true)
    {
        printMenu();
        std::cout << "Current Time: " << current_time << std::endl;
        input = getUserOption();
        processUserOption(input);
    }
}

void CoreMain::printMenu()
{
    std::cout << "\n1. Pring help" << std::endl;
    std::cout << "2. Pring exchange stats" << std::endl;
    std::cout << "3. Make an ask" << std::endl;
    std::cout << "4. Make a bid" << std::endl;
    std::cout << "5. Print wallet" << std::endl;
    std::cout << "6. Continue" << std::endl;
    std::cout << "********************" << std::endl;
}

void CoreMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and earn." << std::endl;
}

void CoreMain::printMarketStats()
{
    for(std::string const p : orderbook.getKnownProducts())
    {
        std::cout << "Product : " << p << std::endl;

        std::vector<OrderBookEntry> askEntries = orderbook.getOrders(OrderBookType::ask,p,current_time);
        std::vector<OrderBookEntry> bidEntries = orderbook.getOrders(OrderBookType::bid,p,current_time);

        std::cout << "Ask seen : " << askEntries.size() << "\t\tBid seen:\t" << bidEntries.size() << std::endl;
        std::cout << "Max Asks : " << OrderBook::getHighPrice(askEntries)<< "\tMax bids:\t" << OrderBook::getHighPrice(bidEntries)  << std::endl;
        std::cout << "Min Asks : " << OrderBook::getLowPrice(askEntries)<< "\tMin bids:\t" << OrderBook::getHighPrice(bidEntries)   << std::endl;
        std::cout << std::endl;
    }

    // std::cout << "Market contains " << orders.size() << " entries." << std::endl;

    // unsigned int bids = 0;
    // unsigned int asks = 0 ; 

    // for(OrderBookEntry& e : orders)
    // {
    //     if( e.orderType == OrderBookType::ask)
    //     {
    //         asks ++;
    //     }
    //     if( e.orderType == OrderBookType::bid)
    //     {
    //         bids ++;
    //     }
    // }

    // std::cout << "Order Books asks: " << asks << " bids: " << bids << " entries." << std::endl;
}

void CoreMain::enterAsk()
{
    std::cout << "Mark and ask - enter the amount : product, price, amount, eg ETH/BTC,200,0.5" << std::endl;
    std::string input;

    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input,',');

    if(tokens.size() != 3)
    {
        std::cout << "CoreMain::enterAsk Bad input" << input << std::endl;
    }
    else
    {
        try
        {
            OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1],tokens[2],current_time,tokens[0],OrderBookType::ask);
            obe.userName = "simuser";
            if(wallet.canFullfillOrder(obe))
            {
                std::cout << "Wallet can complete this order." << std::endl;
                orderbook.insertOrder(obe);
            }
            else{
                std::cout << "Wallet has not insufficient balance." << std::endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cout << "CoreMain::enterAsk  Bad Line" << std::endl; 
        }
    }

    std::cout << "You typed : " << input << std::endl;

}

void CoreMain::enterBid()
{
    std::cout << "Mark and bid - enter the amount : product, price, amount, eg ETH/BTC,200,0.5" << std::endl;
    std::string input;

    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input,',');

    if(tokens.size() != 3)
    {
        std::cout << "CoreMain::enterAsk Bad input" << input << std::endl;
    }
    else
    {
        try
        {
            OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1],tokens[2],current_time,tokens[0],OrderBookType::bid);
            obe.userName = "simuser";
            if(wallet.canFullfillOrder(obe))
            {
                std::cout << "Wallet can complete this order." << std::endl;
                orderbook.insertOrder(obe);
            }
            else{
                std::cout << "Wallet has not insufficient balance." << std::endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cout << "CoreMain::enterBid  Bad Line" << std::endl; 
        }
    }
    std::cout << "You typed : " << input << std::endl;
}

void CoreMain::printWallet()
{
    std::cout << wallet.toString() << std::endl;
}

void CoreMain::gotoNextTimeframe()
{
    std::cout << "Going to next time frame." << std::endl;

    for(std::string p : orderbook.getKnownProducts())
    {
        std::cout << "Matching : " << p << std::endl;
        std::vector<OrderBookEntry> sales = orderbook.matchAskToBids(p,current_time);
        
        std::cout << "Sales: " << sales.size() << std::endl;
        for(OrderBookEntry& e : sales)
        {
            std::cout << "Sale price: " << e.price << " amount " << e.amount << std::endl;
            if(e.userName == "simuser")
            {
                // update the wallet
                wallet.processSale(e);
            }
        }
    }


    current_time = orderbook.getNextTime(current_time);
}

int CoreMain::getUserOption()
{
    int userOption = 0;
    std::string line;
    std::cout << "Type in 1-6 : ";
    std::getline(std::cin,line);

    try
    {
        userOption = std::stoi(line);
    }
    catch(const std::exception& e)
    {
        std::cout << "CoreMain::getUserOption Bad line" << std::endl;
    }

    std::cout << "\nYou chose: " << userOption << std::endl;
    return userOption;
}

int CoreMain::processUserOption(int userOption)
{
    if(userOption == 0)
    {   
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }

    if(userOption == 1)
    {   
        printHelp();
    }

    if(userOption == 2)
    {   
        printMarketStats();
    }

    if(userOption == 3)
    {   
        enterAsk();
    }

    if(userOption == 4)
    {   
        enterBid();
    }

    if(userOption == 5)
    {   
        printWallet();
    }

    if(userOption == 6)
    {   
        gotoNextTimeframe();
    }
    return -1;
}
