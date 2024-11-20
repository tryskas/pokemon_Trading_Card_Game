#include "card.h"

Card::Card()
    : cardName("")
{
}

void Card::displayInfo(){
    cout << "card name : " << cardName << endl;
}

void Card::setCardName(const string name){
    cardName = name;
}