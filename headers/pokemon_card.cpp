#include "pokemon_card.h"

PokemonCard::PokemonCard(const string name, const string type, const string family, int evolution, int max_hp, int current_hp, 
                         const tuple<int, int, string, int> attack1, const tuple<int, int, string, int> attack2)
    : pokemonType(type), 
      familyName(family), 
      evolutionLevel(evolution), 
      maxHP(max_hp), hp(current_hp) 
{
    setCardName(name);
    attacks.push_back(attack1);
    attacks.push_back(attack2);
}

void PokemonCard::displayInfo() {
    Card::displayInfo();
    
    cout << "Pokemon Type: " << pokemonType << endl;
    cout << "Family Name: " << familyName << endl;
    cout << "Evolution Level: " << evolutionLevel << endl;
    cout << "Max HP: " << maxHP << endl;
    cout << "Current HP: " << hp << endl;
    
    cout << "Attacks:" << endl;
    for (size_t i = 0; i < attacks.size(); ++i) {
        cout << "  Attack " << (i + 1) << ":" << endl;
        cout << "  Energy Cost: " << get<0>(attacks[i]) << endl;
        cout << "  Current Energy Cost: " << get<1>(attacks[i]) << endl;
        cout << "  Description: " << get<2>(attacks[i]) << endl;
        cout << "  Damage: " << get<3>(attacks[i]) << endl;
    }
}
