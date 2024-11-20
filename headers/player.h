#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "pokemon_card.h"
#include "energy_card.h"
#include "trainer_card.h"
#include <string>
#include <vector>

using namespace std;

class Player {
    private:
        string playerName;
        vector<Card*> benchCards;
        vector<PokemonCard*> actionCards;

    public:
        Player(const string name);
        void addCardToBench(Card*);
        void activatePokemonCard(int);
        void attachEnergyCard(int, int);
        void displayBench();
        void displayAction();
        void attack(int, int, Player, int);
        void useTrainer(int);
};

#endif
