#include <string>
#include "Character.h"

using namespace std;

#ifndef __WARRIOR_H__
#define __WARRIOR_H__

class Warrior : public Character{
 private:
	string allegiance;

 public:
 	Warrior(const string &name, double health, double attackStrength, string allegiance);
 	void attack(Character& opponent) override;
 };

#endif