#include "Hero.hpp"

Hero::Hero(string n, int hp, int atk, int arm, int spe, int man, int cost1, int cost2, int cost3, int cdult, string at1, string at2, string at3, string ult) : Personnage(n, hp, atk, arm, spe, man, cdult) {
    attack1 = at1;
    attack2 = at2;
    attack3 = at3;
    ultime = ult;
    manacost_attack1 = cost1;
    manacost_attack2 = cost2;
    manacost_attack3 = cost3;
}

Hero::~Hero() {}

string Hero::get_attack1() {
    return attack1;
}

string Hero::get_attack2() {
    return attack2;
}

string Hero::get_attack3() {
    return attack3;
}

string Hero::get_ultime() {
    return ultime;
}

int Hero::get_damage_attack1() {
    return get_attack() + rand() % 11;
}

int Hero::get_damage_attack2() {
    return get_attack() + 10 + rand() % 16;
}

int Hero::get_damage_attack3() {
    return get_attack() + 25 + rand() % 26;
}

int Hero::get_ultimate() {
    return get_damage_attack1() + get_damage_attack2() + get_damage_attack3();
}

int Hero::get_manacost_attack1() {
    return manacost_attack1;
}

int Hero::get_manacost_attack2() {
    return manacost_attack2;
}

int Hero::get_manacost_attack3() {
    return manacost_attack3;
}

int Hero::set_manacost_attack1(int mana) {
    return mana;
}

int Hero::set_manacost_attack2(int mana) {
    return mana;
}

int Hero::set_manacost_attack3(int mana) {
    return mana;
}
