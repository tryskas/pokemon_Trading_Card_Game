#include "player.h"

Player::Player(const string name)
    : playerName(name)
{
}

void Player::addCardToBench(Card* card){
    benchCards.push_back(card);
    cout << "add a new card to the deck !!!" << endl;
    cout << endl;
}
void Player::activatePokemonCard(int index) {
    if (index < 0 || index >= benchCards.size()) {
        cout << playerName << " cannot activate a card: invalid index." << endl;
        return;
    }

    PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(benchCards[index]);
    if (pokemonCard) {
        actionCards.push_back(pokemonCard);
        benchCards.erase(benchCards.begin() + index);
        cout << playerName << " is activating a Pokemon Card: " << pokemonCard->getCardName() << endl;
    } else {
        cout << playerName << " cannot activate this card: it is not a Pokemon card." << endl;
    }
}


void Player::attachEnergyCard(int energyIndex, int pokemonIndex) {
    if (pokemonIndex < 0 || pokemonIndex >= actionCards.size()) {
        cout << "Invalid Pokemon Card index." << endl;
        return;
    }

    EnergyCard* energyCard = dynamic_cast<EnergyCard*>(benchCards[energyIndex]);
    if (energyCard) {
        actionCards[pokemonIndex]->attachEnergy(1);
        cout << playerName << " is attaching Energy Card of type " << energyCard->getEnergyType()
             << " to the Pokemon " << actionCards[pokemonIndex]->getCardName() << endl;
    } else {
        cout << "Selected card is not an Energy Card!" << endl;
    }
}
void Player::displayBench() {
    if (benchCards.empty()) {
        cout << "Bench cards for Player " << playerName << ": empty." << endl;
        return;
    }

    cout << "Bench cards for Player " << playerName << ":" << endl;
    for (Card* card : benchCards) {
        card->displayInfo();
    }
}
void Player::displayAction() {
    if (actionCards.empty()) {
        cout << "Action cards for Player " << playerName << ": no active Pokémon." << endl;
        return;
    }

    cout << "Action cards for Player " << playerName << ":" << endl;
    for (PokemonCard* pokemon : actionCards) {
        pokemon->displayInfo();
    }
}

void Player::attack(int actionCardIndex, int attackIndex, Player& opponent, int targetPokemonIndex) {
    if (actionCardIndex < 0 || actionCardIndex >= actionCards.size()) {
        cout << "Invalid action card index." << endl;
        return;
    }

    PokemonCard* attacker = actionCards[actionCardIndex];
    if (attackIndex < 0 || attackIndex >= attacker->getAttacks().size()) {
        cout << "Invalid attack index." << endl;
        return;
    }

    // Récupérer l'attaque et effectuer l'attaque sur le Pokémon cible de l'adversaire
    auto attack = attacker->getAttacks()[attackIndex];
    int damage = get<3>(attack);

    // Trouver le Pokémon cible de l'adversaire
    if (targetPokemonIndex < 0 || targetPokemonIndex >= opponent.getActionCards().size()) {
        cout << "Invalid target Pokémon index." << endl;
        return;
    }

    PokemonCard* target = opponent.getActionCards()[targetPokemonIndex];
    target->takeDamage(damage);
    cout << playerName << " attacks " << opponent.getPlayerName() << "'s " 
         << target->getCardName() << " with " << attacker->getCardName() 
         << "'s attack " << get<2>(attack) << ", dealing " << damage << " damage!" << endl;
}

void Player::useTrainer(int index){
    if (index < 0 || index >= static_cast<int>(benchCards.size())) {
        cout << "Invalid index. No Trainer Card found at the given position." << endl;
        return;
    }

    // Vérifie si la carte sélectionnée est une TrainerCard
    TrainerCard* trainerCard = dynamic_cast<TrainerCard*>(benchCards[index]);
    if (!trainerCard) {
        cout << "The selected card is not a Trainer Card." << endl;
        return;
    }

    // Afficher l'effet de la carte d'entraîneur
    cout << playerName << " is using Trainer Card: " << trainerCard->getCardName() << endl;
    trainerCard->displayInfo();

    benchCards.erase(benchCards.begin() + index);
    cout << "Trainer Card has been used and removed from the bench." << endl;
}

vector<Card*> Player::getBenchCard(){
    return this->benchCards;
}
vector<PokemonCard*> Player::getActionCards(){
    return actionCards;
}
string Player::getPlayerName(){
    return playerName;
}