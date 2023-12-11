#include "Mechant.hpp"

Mechant::Mechant(string n, int hp, int atk, int arm, int spe, int man, int cost1, int cost2, int cost3, int cdult, string at1, string at2, string at3, string ult) : Personnage(n, hp, atk, arm, spe, man, cdult) {
    attack1 = at1;
    attack2 = at2;
    attack3 = at3;
    ultime = ult;
    manacost_attack1 = cost1;
    manacost_attack2 = cost2;
    manacost_attack3 = cost3;
}

Mechant::~Mechant() {}

string Mechant::get_attack1() {
    return attack1;
}

string Mechant::get_attack2() {
    return attack2;
}

string Mechant::get_attack3() {
    return attack3;
}

string Mechant::get_ultime() {
    return ultime;
}

int Mechant::get_damage_attack1() {
    return damage_attack1;
}

int Mechant::get_damage_attack2() {
    return damage_attack2;
}

int Mechant::get_damage_attack3() {
    return damage_attack3;
}

int Mechant::get_manacost_attack1() {
    return manacost_attack1;
}

int Mechant::get_manacost_attack2() {
    return manacost_attack2;
}

int Mechant::get_manacost_attack3() {
    return manacost_attack3;
}

int Mechant::set_attack1() {
    return get_attack() + 10;
}

int Mechant::set_attack2() {
    return get_attack() + 25;
}

int Mechant::set_attack3() {
    return get_attack() + 50;
}

int Mechant::set_ultimate() {
    return get_damage_attack1() + get_damage_attack2() + get_damage_attack3();
}

int Mechant::set_manacost_attack1(int mana) {
    return mana;
}

int Mechant::set_manacost_attack2(int mana) {
    return mana;
}

int Mechant::set_manacost_attack3(int mana) {
    return mana;
}
