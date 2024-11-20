#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include "card.h"

class TrainerCard : public Card{
    private:
        string trainerEffect;
    public:
        TrainerCard(const string, const string);
        void displayInfo() override;
};

#endif