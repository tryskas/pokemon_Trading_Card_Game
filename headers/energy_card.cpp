#include "energy_card.h"

EnergyCard::EnergyCard(const string energy)
    : energyType(energy)
{
    setCardName("Energy");
}

void EnergyCard::displayInfo(){
    Card::displayInfo();
    
    cout << "Energy Type: " << energyType << endl;
}