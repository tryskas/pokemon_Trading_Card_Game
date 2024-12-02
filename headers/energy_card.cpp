#include "energy_card.h"

EnergyCard::EnergyCard(const string energy)
    : energyType(energy)
{
    setCardName("Energy");
}

void EnergyCard::displayInfo() {
    cout << "Energy Card - Type: " << energyType << endl;
}

string EnergyCard::getEnergyType(){
    return energyType;
}
