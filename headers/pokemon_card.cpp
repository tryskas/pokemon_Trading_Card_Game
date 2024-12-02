#include "pokemon_card.h"

PokemonCard::PokemonCard(const string name, const string type, const string family, int evolution, int max_hp, int current_hp, 
                         const tuple<int, int, string, int> attack1, const tuple<int, int, string, int> attack2)
    : pokemonType(type), 
      familyName(family), 
      evolutionLevel(evolution), 
      maxHP(max_hp), 
      hp(max_hp),
      energie(0)
{
    setCardName(name);
    attacks.push_back(attack1);
    attacks.push_back(attack2);
}

void PokemonCard::displayInfo() {
    cout << "Pokemon Card - Name: " << getCardName()
         << " , Type: " << pokemonType
         << " , Evolution Level: " << evolutionLevel
         << " of the family \"" << familyName
         << " , HP: " << hp << "/" << maxHP << "\"" << endl;

    cout << "Attacks:" << endl;
    for (size_t i = 0; i < attacks.size(); ++i) {
        auto [cost, currentEnergy, description, damage] = attacks[i];
        cout << "Attack #" << i + 1 << ":" << endl;
        cout << "  Attack cost: " << cost << endl;
        cout << "  Current energy storage: " << currentEnergy << endl;
        cout << "  Attack description: " << description << endl;
        cout << "  Attack damage: " << damage << endl;
    }
}
int PokemonCard::getHP(){
    return hp;
}
void PokemonCard::attachEnergy(int amount) {
    energie += amount;

    // Distribution de l'énergie vers les attaques
    for (auto& attack : attacks) {
        int& cost = get<0>(attack);
        int& currentEnergy = get<1>(attack);

        // Ajouter de l'énergie si l'attaque n'est pas encore complètement chargée
        if (currentEnergy < cost) {
            int energyNeeded = cost - currentEnergy;
            int energyToAdd = min(amount, energyNeeded);
            currentEnergy += energyToAdd;
            amount -= energyToAdd;

            if (amount <= 0) break; // Si toute l'énergie est utilisée, arrêter
        }
    }
}
void PokemonCard::takeDamage(int damage) {
    hp -= damage;

    if (hp < 0) {
        hp = 0;
    }

    cout << getCardName() << " now has " << hp << " HP remaining." << endl;
}


vector<tuple<int, int, string, int>> PokemonCard::getAttacks(){
    return attacks;
}