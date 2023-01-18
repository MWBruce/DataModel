///////////////////////////////////////////////////////////////////////////////
// File Name:      ObjectCurl.h
//
// Author:         Maxwell Bruce
// Email:          Maxwellwallacebruce@gmail.com
//
// Description:    The declaration of ObjectCurl methods.
///////////////////////////////////////////////////////////////////////////////

#ifndef OBJECTCURL_H
#define OBJECTCURL_H


#include <string>
#include <curl/curl.h>

class ObjectCurl {
protected:
    CURL * curl;
    std::string curlBuffer;
public:
    /**
     * @brief Constructor for the curl object.
     *
     * @param html_link of the page to scrape.
     * @param 
     */
    ObjectCurl(std::string html_link);

    /**
     * @brief Writer for html information received
     * 
    */
    static int WriteCurl(char *data, size_t size, size_t nmemb, std::string *buffer){
        int result = 0;
        if(buffer == NULL) {
            return result;
        } else {
            buffer->append(data, size * nmemb);
            result = size * nmemb; 
        }
        return result;
    }

    /**
     * @brief Returns string containing page data.
    */
    std::string getData();
};

#endif /* ObjectCurl_cpp */