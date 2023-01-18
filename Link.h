///////////////////////////////////////////////////////////////////////////////
// File Name:      Link.h
//
// Author:         Maxwell Bruce
// Email:          Maxwellwallacebruce@gmail.com
//
// Description:    The declaration of Link_cpp methods.
///////////////////////////////////////////////////////////////////////////////

#ifndef LINK_H
#define LINK_H

#include <string>

class Link {
    private:
    	std::string html_link;
        std::string ticker;
    public:
        /**
         * @brief Constructor for Link Object.
         * 
         * @param HTML_LINK The html link that will be modifed and used to collect data.
         * @param TICKER The ticker of the company the html link is created for.
         * @param VALID_HTML Bool value confirming that the html works.
         * 
        */
        Link(std::string given_ticker);

        /**
         * @brief Sets html link to a link which would provide all neccessary information for the selected stock.
        */
        void create_html();

        /**
         * @brief sets ticker
        */
        void set_ticker(std::string given_ticker);

        /**
         * @brief Checks if the current html variable is a working link with data on it.
        */
        bool check_html();

        /**
         * @brief Returns html if valid and returns "N/A" if not.
        */
        std::string get_html();

};

#endif /* Link_cpp */
