#include <iostream>
using namespace std;

void printMenu(){

    cout << "1: Print help" << endl;
    cout << "2: Print exchange stats" << endl;
    cout << "3: Make an offer" << endl;
    cout << "4: Make a bid" << endl;
    cout << "5: Print wallet" << endl;
    cout << "6: Continue" <<endl << endl;

    cout << "-------------------" << endl <<endl;
}

void printHelp(){
    cout << "Help - your aim is to make money. Analyse the market and make bids and offers." << endl << endl;
}

void printMarketStats(){
    cout << "Market looks good" << endl << endl;
}

void enterOffer(){
    cout << "Make and offer - enter the amount" << endl << endl;
}

void enterBid(){
    cout << "Make a bid - enter the amount" << endl << endl;
}

void printWallet(){
    cout << "Your wallet is empty" << endl << endl;
}

void gotoNextTimeFrame(){
    cout << "Going to next frame" << endl << endl;
}


int getUserOption(){

    int userOption;

    cout << "Select an option 1-6: ";
    cin >> userOption;
    cout << "You chose: " << userOption << endl<< endl;

    return userOption;
}

void processUSerOption(int userOption){
    if (userOption == 0){
        cout << "Invalid choice. Choose 1-6:" << endl << endl;
    }
    if (userOption == 1){
        printHelp();
    }
    if (userOption == 2){
        printMarketStats();
    }
    if (userOption == 3){
        enterOffer();
    }
    if (userOption == 4){
        enterBid();
    }
    if (userOption == 5){
        printWallet();
    }
    if (userOption == 6){
        gotoNextTimeFrame();
    }

}

int main(){

    while (true) {

        printMenu();
        int userOption = getUserOption();  
        processUSerOption(userOption);       
    }
    

    return 0;

}