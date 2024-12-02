#include "trainer_card.h"

TrainerCard::TrainerCard(const string name, const string effect)
:trainerEffect(effect)
{
    setCardName(name);
}

void TrainerCard::displayInfo() {
    cout << "Trainer Card - Name: " << getCardName() << " , Effect: " << trainerEffect << endl;
}
