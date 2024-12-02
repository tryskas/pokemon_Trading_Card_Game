#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include "card.h"

class EnergyCard : public Card{
    private:
        string energyType;
    public:
        EnergyCard(const string);
        void displayInfo() override;
        string getEnergyType();
};

#endif