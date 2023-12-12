#include "Personnage.hpp"

Personnage::Personnage(string n, int hp, int atk, int arm, int spe, int man, int cdult) {
    name = n;
    maxhealth = hp;
    health = hp;
    attack = atk;
    armor = arm;
    speed = spe;
    maxmana = man;
    mana = man;
    cd_ult = cdult;
}

Personnage::~Personnage() {}

string Personnage::get_name() const {
    return name;
}

int Personnage::get_maxhealth() {
    return maxhealth;
}

int Personnage::get_health() {
    if (health < 0) {
        health = 0;
    }
    return health;
}

int Personnage::get_attack() {
    return attack;
}

int Personnage::get_armor() {
    return armor;
}

int Personnage::get_speed() {
    return speed;
}

int Personnage::get_maxmana() {
    return maxmana;
}

int Personnage::get_mana() {
    return mana;
}

int Personnage::get_cd_ult() {
    return cd_ult;
}

int Personnage::get_action() {
    return action;
}

void Personnage::set_maxhealth(int hpmax) {
    maxhealth = hpmax;
    if (health > maxhealth) {
        health = maxhealth;
    }
}

void Personnage::set_health(int hp) {
    health = hp;
    if (health > maxhealth) {
        health = maxhealth;
    }
}

void Personnage::set_attack(int atk) {
    attack = atk;
}

void Personnage::set_armor(int arm) {
    armor = arm;
}

void Personnage::set_speed(int spe) {
    speed = spe;
}

void Personnage::set_maxmana(int manmax) {
    maxmana = manmax;
}

void Personnage::set_mana(int man) {
    mana = man;
}

void Personnage::set_cd_ult(int cdult) {
    cd_ult = cdult;
}

void Personnage::set_action(int act) {
    action = act;
}

int Personnage::encaisser(int armorvictim, int brutdamage) {
    return brutdamage - armor;
}

int Personnage::esquive(int armorvictim, int speedvictim, int brutdamage) {
    srand(time(0));
    int nombreAleatoire = rand() % 101;
    if (nombreAleatoire > speedvictim) {
        cout << "Esquive echoue" << endl;
        return brutdamage;
    }
    else if (nombreAleatoire <= speedvictim) {
        cout << "Esquive reussit" << endl;
        return 0;
    }
}

int Personnage::parer(int armorvictim, int brutdamage) {
    if (get_armor() >= 15) {
        cout << "Parade reussit" << endl;
        return brutdamage / 4;
    }
    else {
        cout << "Parade echoue (Vous n'avez plus d'armure necessaire) !" << endl;
        return encaisser(armorvictim, brutdamage);
    }
}

bool Personnage::is_ult_usable() {
    if (cd_ult > 0) {
        return false;
    }
    else {
        return true;
    }
}

int Personnage::regen_mana(int pourcentage) {
    int pourcent = pourcentage / 100;
    mana += static_cast<int>(maxmana * pourcent);
    if (mana > maxmana) {
        mana = maxmana;
    }
    return mana;
}

void Personnage::set_passif(string pas) {
    passif = pas;
}

string Personnage::get_passif() {
    return passif;
}

bool Personnage::has_passif() {
    if (passif != "") {
        return true;
    }
    else {
        return false;
    }
}

void Personnage::can_revive(bool rev) {
    revive = rev;
}

bool Personnage::has_revive() {
    return revive;
}
