///////////////////////////////////////////////////////////////////////////////
// File Name:      Data.h
//
// Author:         Maxwell Bruce
// Email:          Maxwellwallacebruce@gmail.com
//
// Description:    The declaration of Data_cpp methods.
///////////////////////////////////////////////////////////////////////////////

#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>
#include <unordered_map>

class Data {
    private:
        std::string ticker;
        std::string raw_data;
        std::string refreshed_time;
        std::string interval;
        int period_count;
        std::vector<double> *open_price;
        std::vector<double> *close_price;
        std::vector<double> *high_price;
        std::vector<double> *low_price;
        std::vector<double> *volume;

    public:
        /**
         * @brief Constructor for Data class
         * 
         * @param TICKER The ticker for the stock the data is being allocated for.
         * @param RAW_DATA The Raw HTML data.
         * @param REFRESHED_TIME The time the data was last refreshed at.
         * @param INTERVAL The interval size of the data.
         * @param PERIOD_COUNT The amount of intervals.
        */
        Data(std::string given_data);

        /**
         * @brief Sets the basic information for the stock (ticker, refreshed_time, interval, period_count).
        */
        void set_basic_information();

        /**
         * @brief Sets the stored_data map with vectors containing the open, high, low, close and volume.
        */
        void set_stored_data();

        /**
         * @brief Returns ticker.
        */
        std::string get_ticker();

        /**
         * @brief Returns refreshed_time.
        */
        std::string get_refreshed_time();

        /**
         * @brief Returns interval.
        */
        std::string get_interval();

        /**
         * @brief Returns vector of open_prices.
        */
        std::vector<double> *get_open_prices();

        /**
         * @brief Returns vector of high_prices.
        */
        std::vector<double> *get_high_prices();
        
        /**
         * @brief Returns vector of low_prices.
        */
        std::vector<double> *get_low_prices();
        
        /**
         * @brief Returns vector of close_prices.
        */
        std::vector<double> *get_close_prices();
        
        /**
         * @brief Returns vector of volume.
        */
        std::vector<double> *get_volume();

        /**
         * @brief Destructor
        */
       ~Data();
};

#endif /* Data_cpp */