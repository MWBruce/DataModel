///////////////////////////////////////////////////////////////////////////////
// File Name:      ObjectCurl.cpp
//
// Author:         Maxwell Bruce
// Email:          Maxwellwallacebruce@gmail.com
//
// Description:    The implementation of ObjectCurl methods.
///////////////////////////////////////////////////////////////////////////////

#include "ObjectCurl.h"
#include <string>
#include <curl/curl.h>


ObjectCurl::ObjectCurl(std::string html_link) {
    curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCurl); // Directs to WriteCurl Function
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlBuffer); // Writes infromation to curlBuffer
            curl_easy_setopt(curl, CURLOPT_URL, html_link.c_str()); // Passes html_link as char array
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1); // Allows for one redirect
            curl_easy_setopt(curl, CURLOPT_RANGE, "0-20"); // Only reads in the first 20 bytes
            curl_easy_perform(curl); 
            curl_easy_cleanup(curl);
        }

}

std::string ObjectCurl::getData() {
    return curlBuffer;
}