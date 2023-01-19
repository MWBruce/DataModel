///////////////////////////////////////////////////////////////////////////////
// File Name:      Link.cpp
//
// Author:         Maxwell Bruce
// Email:          Maxwellwallacebruce@gmail.com
//
// Description:    The implementation of Link methods.
///////////////////////////////////////////////////////////////////////////////

#include "Link.h"
#include "ObjectCurl.h"
#include <string>
#include <iostream>

Link::Link(std::string given_ticker) {
    set_ticker(given_ticker);
}

void Link::create_html() {
    html_link = "https://www.alphavantage.co/query?function=TIME_SERIES_INTRADAY&symbol=" + ticker + "&interval=5min&apikey=OJRPKNUZ0N9GFAZS";
}

void Link::set_ticker(std::string given_ticker) {
    ticker = given_ticker;
    create_html();
}

bool Link::check_html() {
   
    ObjectCurl URLChecking(html_link);
    html_information = URLChecking.getData();
    std::string Error_Mesage = "Error Message";
    for(int i=0;i<13;i++) {
        if(Error_Mesage[i] != html_information[i+7]) {
          return true;  
        }
    }
    // std::cout << html_information << std::endl;
    return false;
}

std::string Link::get_html() {
    if(check_html()) {
        return html_information;
    }
    return "N/A";
}

