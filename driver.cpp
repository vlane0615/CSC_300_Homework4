#include "Card.hpp"
#include "url.hpp"
#include <iostream>
#include <string.h>

using namespace std;


int main(int argc, char** argv){
   Url* u1 = new Url("https://api.hearthstonejson.com/v1/25770/enUS/cards.JSON");
    cout << u1 -> getContents() << endl;

};