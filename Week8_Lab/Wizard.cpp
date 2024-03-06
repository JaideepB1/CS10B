#include <iostream>
#include <stdexcept>
#include "Wizard.h"


using namespace std;

Wizard::Wizard(const string &name, double health, double attackStrength, int rank) 
: Character(WIZARD, name, health, attackStrength), rank(rank) {

}
    

void Wizard::attack(Character& opponent) {
    if (opponent.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        double calc = ((this->rank * 1.0)/ opp.rank) * (attackStrength);
        opp.damage(calc);

        cout << "Wizard " << name << " attacks " << opp.getName() << " --- POOF!!" << endl;
        cout << opp.getName() << " takes " << calc << " damage." << endl;
    }

    else {
        opponent.damage(attackStrength);
        cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << attackStrength << " damage." << endl;
    }
}