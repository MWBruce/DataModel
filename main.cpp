//////////////////////////////////////////////////////////////////////////////////////////////
// File Name:       main.cpp
//
// Author:          Maxwell Bruce
// Email:           Maxwellwallacebruce@gmail.com
//
// Description:     C++ main program that calls the Link class
// API Key:         OJRPKNUZ0N9GFAZS
/////////////////////////////////////////////////////////////////////////////////////////////

#include "Link.h"
#include "Data.h"
#include <iostream>
#include <cctype>
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::system("clear");
    std::string input_ticker = "aapl";
    // std::cout << "What ticker would you like the html for? ";
    // std::cin >> input_ticker;
    Link stock(input_ticker); // Creates Link Object
    bool escape_selected = false; // Used to confirm that user is still wanting to search for a stock
    while(!stock.check_html() && escape_selected == false) { // Confirms valid link or that user still is searching for a stock
        std::cout << "The URL associated with that ticker doesn't work, please try again (Or type 'esc')! What ticker would you like the html for? ";
        std::cin >> input_ticker;
        stock.set_ticker(input_ticker);
        if(input_ticker.length() == 3 && (tolower(input_ticker[0]) == 'e' && tolower(input_ticker[1]) == 's' && tolower(input_ticker[2]) == 'c')) {
            escape_selected = true;
        }
    } 
    std::string HTML_info = stock.get_html();
    if(HTML_info != "N/A") {
        Data DataObj(HTML_info);
        std::vector<double> *Price_Info = DataObj.get_high_prices();
        // for(auto i=Price_Info->begin();i<Price_Info->end();i++) {
        //     std::cout << *i << std::endl;
        // }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << diff.count() << std::endl;
    return 0;
}