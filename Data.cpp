///////////////////////////////////////////////////////////////////////////////
// File Name:      Data.cpp
//
// Author:         Maxwell Bruce
// Email:          Maxwellwallacebruce@gmail.com
//
// Description:    The implementation of Data_cpp methods.
///////////////////////////////////////////////////////////////////////////////

#include "Data.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <chrono>

Data::Data(std::string given_data) {
    raw_data = given_data;
    open_price = new std::vector<double>;
    close_price = new std::vector<double>;
    high_price = new std::vector<double>;
    low_price = new std::vector<double>;
    volume= new std::vector<double>;
    set_basic_information();
    set_stored_data();
}

void Data::set_basic_information() {

    std::string ticker_predecessor_string = "Symbol\": \"";
    std::string refreshed_time_predecessor_string = "Last Refreshed\": \"";
    std::string interval_predecessor_string = "Interval\": \"";
    size_t index_ticker = raw_data.find(ticker_predecessor_string);
    size_t index_refreshed_time = raw_data.find(refreshed_time_predecessor_string);
    size_t index_interval = raw_data.find(interval_predecessor_string);

    /**
     * @brief Finding ticker for stock
    */
    int iterator = index_ticker+ticker_predecessor_string.length();
    char temp_char = raw_data[iterator];
    int length = 0;
    while(temp_char != '\"') {
        length++;
        iterator++;
        temp_char = raw_data[iterator];
    }
    ticker = raw_data.substr(index_ticker+ticker_predecessor_string.length(),length);

    /**
     * @brief Finding refreshed_time for stock
    */
    iterator = index_refreshed_time+refreshed_time_predecessor_string.length();
    temp_char = raw_data[iterator];
    length = 0;
    while(temp_char != '\"') {
        length++;
        iterator++;
        temp_char = raw_data[iterator];
    }
    refreshed_time = raw_data.substr(index_refreshed_time+refreshed_time_predecessor_string.length(),length);

    /**
     * @brief Finding the interval for stock
    */
    iterator = index_interval+interval_predecessor_string.length();
    temp_char = raw_data[iterator];
    length = 0;
    while(temp_char != '\"') {
        length++;
        iterator++;
        temp_char = raw_data[iterator];
    }
    interval = raw_data.substr(index_interval+interval_predecessor_string.length(),length);

    /**
     * @brief Finding the amount of periods for the stock
    */
    period_count = 0;
    for(int i=0;i<raw_data.length()-4;i++) {
        if(raw_data[i] == 'o' && raw_data[i+1] == 'p' && raw_data[i+2] == 'e' && raw_data[i+3] == 'n' && raw_data[i+4] == '\"') {
            period_count++;
        }
    }
}

void Data::set_stored_data() {
    std::string temp_raw_data = raw_data;
    std::string open_predecessor_string = "1. open\": \"";
    std::string high_predecessor_string = "2. high\": \"";
    std::string low_predecessor_string = "3. low\": \"";
    std::string close_predecessor_string = "4. close\": \"";
    std::string volume_predecessor_string = "5. volume\": \"";
    std::string info_seperator_string= "},";

    for(int i=0;i<period_count;i++) {

        size_t start_of_info = temp_raw_data.find(info_seperator_string);
        temp_raw_data = temp_raw_data.substr(start_of_info+info_seperator_string.length());
        size_t temp_index_open = temp_raw_data.find(open_predecessor_string);
        size_t temp_index_high = temp_raw_data.find(high_predecessor_string);
        size_t temp_index_low = temp_raw_data.find(low_predecessor_string);
        size_t temp_index_close= temp_raw_data.find(close_predecessor_string);
        size_t temp_index_volume = temp_raw_data.find(volume_predecessor_string);


            /**
             * @brief Finding open price and storing as string open
            */
            int iterator = temp_index_open+open_predecessor_string.length();
            char temp_char = temp_raw_data[iterator];
            int length = 0;
            while(temp_char != '\"') {
                length++;
                iterator++;
                temp_char = temp_raw_data[iterator];
            }
            std::string open = temp_raw_data.substr(temp_index_open+open_predecessor_string.length(),length);
            
            /**
             * @brief Finding high price and storing as string high
            */
            iterator = temp_index_high+high_predecessor_string.length();
            temp_char = temp_raw_data[iterator];
            length = 0;
            while(temp_char != '\"') {
                length++;
                iterator++;
                temp_char = temp_raw_data[iterator];
            }
            std::string high = temp_raw_data.substr(temp_index_high+high_predecessor_string.length(),length);

            /**
             * @brief Finding low price and storing as string low
            */
            iterator = temp_index_low+low_predecessor_string.length();
            temp_char = temp_raw_data[iterator];
            length = 0;
            while(temp_char != '\"') {
                length++;
                iterator++;
                temp_char = temp_raw_data[iterator];
            }
            std::string low = temp_raw_data.substr(temp_index_low+low_predecessor_string.length(),length);

            /**
             * @brief Finding close price and storing as string close
            */
            iterator = temp_index_close+close_predecessor_string.length();
            temp_char = temp_raw_data[iterator];
            length = 0;
            while(temp_char != '\"') {
                length++;
                iterator++;
                temp_char = temp_raw_data[iterator];
            }
            std::string close = temp_raw_data.substr(temp_index_close+close_predecessor_string.length(),length);


                        /**
             * @brief Finding volume and storing as string volume
            */
            iterator = temp_index_volume+volume_predecessor_string.length();
            temp_char = temp_raw_data[iterator];
            length = 0;
            while(temp_char != '\"') {
                length++;
                iterator++;
                temp_char = temp_raw_data[iterator];
            }
            std::string volume_str = temp_raw_data.substr(temp_index_volume+volume_predecessor_string.length(),length);


            /**
             * @brief Performing vector operations
            */
            double temp_open = stod(open);
            open_price->push_back(temp_open);
            double temp_high = stod(high);
            high_price->push_back(temp_open);
            double temp_low = stod(low);
            low_price->push_back(temp_open);
            double temp_close = stod(close);
            close_price->push_back(temp_open);
            double temp_volume = stod(volume_str);
            volume->push_back(temp_volume);
    }
}

std::string Data::get_ticker() {
    return ticker;
}

std::string Data::get_refreshed_time() {
    return refreshed_time;
}

std::string Data::get_interval() {
    return interval;
}

std::vector<double> *Data::get_open_prices() {
    return  open_price;
}

std::vector<double> *Data::get_high_prices() {
    return  high_price;
}

std::vector<double> *Data::get_low_prices() {
    return  low_price;
}

std::vector<double> *Data::get_close_prices() {
    return  close_price;
}

 std::vector<double> *Data::get_volume() {
    return  volume;
 }

 Data::~Data() {
    delete open_price;
    delete close_price;
    delete high_price;
    delete low_price;
    delete volume;
 }