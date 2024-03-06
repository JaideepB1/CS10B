#include <iostream>
#include <stdexcept>
#include "Elf.h"


using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, string familyName) 
: Character(ELF, name, health, attackStrength), familyName(familyName) {

}

void Elf::attack(Character& opponent) {
    int count = 0;
    if (opponent.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if (this->familyName == opp.familyName) {
            count += 1;
            cout << "Elf " << name << " does not attack Elf " << opp.getName() << "." << endl;
            cout << "They are both members of the " << familyName << " family." << endl;
        }
    }

    if (count == 0) {
        double calc = (health / MAX_HEALTH) * (attackStrength);
        opponent.damage(calc);
        cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
        cout << opponent.getName() << " takes " << calc << " damage." << endl;
    }
}


