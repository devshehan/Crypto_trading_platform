#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "CSVReader.h"

MerkelMain::MerkelMain()
{

}

void MerkelMain::init()
{
    int input;
    std::string current_time = orderbook.getEarliestTime();
    while(true)
    {
        printMenu();
        std::cout << "Current Time: " << current_time << std::endl;
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain::printMenu()
{
    std::cout << "1. Pring help" << std::endl;
    std::cout << "2. Pring exchange stats" << std::endl;
    std::cout << "3. Make an offer" << std::endl;
    std::cout << "4. Make a bid" << std::endl;
    std::cout << "5. Print wallet" << std::endl;
    std::cout << "6. Continue" << std::endl;
    std::cout << "==================" << std::endl;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and earn." << std::endl;
}

void MerkelMain::printMarketStats()
{
    for(std::string const p : orderbook.getKnownProducts())
    {
        std::cout << "Product : " << p << std::endl;

        std::vector<OrderBookEntry> entries = orderbook.getOrders(OrderBookType::ask,p,"2020/03/17 17:02:00.124758");

        std::cout << "Ask seen : " << entries.size() << std::endl;
        std::cout << "Max Asks : " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min Asks : " << OrderBook::getLowPrice(entries) << std::endl;
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

void MerkelMain::enterOffer()
{
    std::cout << "Mark and offer - enter the amount." << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void MerkelMain::printWallet()
{
    std::cout << "Your wallet is empty." << std::endl; 
}

void MerkelMain::gotoNextTimeframe()
{
    std::cout << "Going to next time frame." << std::endl;
}

int MerkelMain::getUserOption()
{
    int userOption;
    std::cout << "Type in 1-6 : ";
    std::cin >> userOption;
    std::cout << "\nYou chose: " << userOption << std::endl;
    return userOption;
}

int MerkelMain::processUserOption(int userOption)
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
        enterOffer();
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
