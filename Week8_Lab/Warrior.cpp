#include <iostream>
#include <stdexcept>
#include "Warrior.h"


using namespace std;

Warrior::Warrior(const string &name, double health, double attackStrength, string allegiance) 
: Character(WARRIOR, name, health, attackStrength), allegiance(allegiance) {

}

void Warrior::attack(Character& opponent) {
    int count = 0;
    if (opponent.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if (this->allegiance == opp.allegiance) {
            count += 1;
            cout << "Warrior " << name << " does not attack Warrior " << opp.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
        }
    }

    if (count == 0) {
        double calc = (health / MAX_HEALTH) * (attackStrength);
        opponent.damage(calc);
        cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << calc << " damage." << endl;
    }
}