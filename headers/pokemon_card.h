#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include "card.h"

class PokemonCard : public Card{
    private:
        string pokemonType;
        string familyName;
        int evolutionLevel;
        int maxHP;
        int hp;
        int energie;
        vector<tuple<int, int, string, int>> attacks;
    public:
        PokemonCard(const string, const string, const string, int, int, int, 
                    const tuple<int, int, string, int>, const tuple<int, int, string, int>);
        void displayInfo() override;
        int getHP();
        void attachEnergy(int);
        void takeDamage(int);
        vector<tuple<int, int, string, int>> getAttacks();
};

#endif