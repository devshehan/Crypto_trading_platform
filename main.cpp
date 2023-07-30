#include "CoreMain.h"
#include "CSVReader.h"
#include "Wallet.h"

int main()
{
    CoreMain app{};
    app.init(); 

    // Wallet wallet;
    // wallet.insertCurrency("ETH",20);
    // wallet.insertCurrency("BTC",20);
    // wallet.insertCurrency("USDT",2000);


    // std::cout << "Wallet has ETH " << wallet.containsCurrency("ETH", 10) << std::endl;
    // std::cout << wallet.toString() << std::endl;

    // std::cout << " \n" << std::endl;
    // wallet.removeCurrency("USDT",40);

    // std::cout << wallet.toString() << std::endl;

    return 0;
}