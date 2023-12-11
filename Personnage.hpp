#ifndef PERSONNAGE
#define PERSONNAGE

#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
using namespace std;

class Personnage {
private:
	string name;
	int maxhealth;
	int health;
	int attack;
	int armor;
	int speed;
	int maxmana;
	int mana;
	int cd_ult;
	int action;
	string passif;
	bool revive = false;
public:
	Personnage(string n, int hp, int atk, int arm, int spe, int man, int cdult);
	~Personnage();

	string get_name();
	int get_maxhealth();
	int get_health();
	int get_attack();
	int get_armor();
	int get_speed();
	int get_maxmana();
	int get_mana();
	int get_cd_ult();
	int get_action();

	void set_maxhealth(int hpmax);
	void set_health(int hp);
	void set_attack(int atk);
	void set_armor(int arm);
	void set_speed(int spe);
	void set_maxmana(int manmax);
	void set_mana(int man);
	void set_cd_ult(int cdult);
	void set_action(int act);

	int encaisser(int armorvictim, int predamage);
	int esquive(int armorvictim, int speedvictim, int predamage);
	int parer(int armorvictim, int predamage);

	bool is_ult_usable();

	int regen_mana(int pourcentage);

	void set_passif(string pas);
	string get_passif();
	bool has_passif();

	void can_revive(bool rev);
	bool has_revive();
};
#endif // !PERSONNAGE
