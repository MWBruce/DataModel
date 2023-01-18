//////////////////////////////////////////////////////////////////////////////////////////////
// File Name:       main.cpp
//
// Author:          Maxwell Bruce
// Email:           Maxwellwallacebruce@gmail.com
//
// Description:     C++ main program that calls the data class
// API Key:         OJRPKNUZ0N9GFAZS
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cctype>
#include "Link.h"

int main() {

    std::string input_ticker;
    std::cout << "What ticker would you like the html for? ";
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
    std::cout << stock.get_html() << std::endl;
    std::string HTML_Link = stock.get_html();

    return 0;
}