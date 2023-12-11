#ifndef MECHANT
#define MECHANT

#include "Personnage.hpp"

class Mechant : public Personnage {
private:
    string attack1;
    string attack2;
    string attack3;
    string ultime;
    int damage_attack1;
    int damage_attack2;
    int damage_attack3;
    int manacost_attack1;
    int manacost_attack2;
    int manacost_attack3;
public:

    Mechant(string n, int hp, int atk, int arm, int spe, int man, int cost1, int cost2, int cost3, int cdult, string at1, string at2, string at3, string ult);
    ~Mechant();

    string get_attack1();
    string get_attack2();
    string get_attack3();
    string get_ultime();

    int get_damage_attack1();
    int get_damage_attack2();
    int get_damage_attack3();

    int get_manacost_attack1();
    int get_manacost_attack2();
    int get_manacost_attack3();

    int set_attack1();
    int set_attack2();
    int set_attack3();
    int set_ultimate();

    int set_manacost_attack1(int mana);
    int set_manacost_attack2(int mana);
    int set_manacost_attack3(int mana);
};
#endif