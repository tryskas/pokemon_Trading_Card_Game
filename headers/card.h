#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

class Card{
    private:
        string cardName;
    public:
        Card();
        virtual void displayInfo();
        void setCardName(const string);
        string getCardName();
};

#endif