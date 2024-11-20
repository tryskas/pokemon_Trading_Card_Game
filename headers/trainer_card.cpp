#include "trainer_card.h"

TrainerCard::TrainerCard(const string name, const string effect)
:trainerEffect(effect)
{
    setCardName(name);
}

void TrainerCard::displayInfo(){
    Card::displayInfo();
    
    cout << "trainer effect : " << trainerEffect << endl;
}