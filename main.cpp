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
    std::system("clear");
    std::string input_ticker;
    std::cout << "What ticker would you like the html for? (e.g aapl, tsla, ibm) ";
    std::cin >> input_ticker;
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
    // auto middle = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> diff_middle = middle - start;
    // std::cout << diff_middle.count() << std::endl;
    std::string HTML_info = stock.get_html();
    auto start = std::chrono::high_resolution_clock::now();
    if(HTML_info != "N/A") {
        Data DataObj(HTML_info);
        std::vector<double> *Price_Info = DataObj.get_high_prices();
        std::cout << "The high prices in 5 minute increments are as follows: " << std::endl;
        for(auto i=Price_Info->begin();i<Price_Info->end();i++) {
            std::cout << *i << std::endl;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "The program took "<< diff.count() << " seconds!" << std::endl;
    return 0;
}