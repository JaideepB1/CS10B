#include <string>
#include "Character.h"

using namespace std;

#ifndef __ELF_H__
#define __ELF_H__

class Elf : public Character{
 private:
	string familyName;

 public:
 	Elf(const string &name, double health, double attackStrength, string familyName);
 	void attack(Character& opponent) override;
 };

#endif