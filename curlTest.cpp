#include <string>
#include <iostream>
#include <curl/curl.h>
#include "url.hpp"

using namespace std;

//For this demonstration, the contents of the web page are put 
//into this global variable.

int main(int argc, char *argv[]){
    
    Url* google = new Url("www.google.com");
    string google_contents = google->getContents();
    cout << google_contents << endl;

    Url* yahoo = new Url("www.yahoo.com");
    string  yahoo_contents = yahoo->getContents();
    cout << yahoo_contents << endl;
}