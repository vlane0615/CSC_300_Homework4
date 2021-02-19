#include "url.hpp"
#include <iostream>
#include <curl/curl.h>

using namespace std;

std::string Url::contents = "";

Url::Url(string url){
    this->url = url;
}

//this is like a full address. The Url:: tells where getContents from the header
string Url::getContents(){
    contents = "";
    CURL*curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL,this->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,handle_data);
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (res == 0){
            return contents; 
        }
        else{
            cerr << "Error: " << res << endl;
        }
      return "No contents!";
    }
    return "No contents!";
}
size_t Url::handle_data(void *ptr, size_t size, size_t nmemb,void *stream){
    int numbytes = size*nmemb;
    char lastchar = *((char *)ptr + numbytes -1);
    *((char *) ptr + numbytes -1) = '\0';

    contents.append((char*)ptr);
    contents.append(1, lastchar);
    *((char*) ptr + numbytes - 1) = lastchar; //might not need this?
    return size*nmemb;
}



//write handledata in the cpp file
//instantiate a URL
//call get Contents
//put this in the driver file (put it in the CurlTest)