#include "Hero.hpp"
#include "Mechant.hpp"

void printCharList(vector<Hero*>& herolist, vector<Mechant*>& mechantlist, bool ishero) {
    if (ishero) {
        if (herolist.size() == 0) {
            cout << "Votre liste de Hero est vide !" << endl;
        }
        else {
            for (int i = 0; i <= herolist.size() - 1; i++) {
                if (herolist[i]->get_name() != "Saitama") {
                    cout << "[" << i << "] : " << herolist[i]->get_name() << endl;
                    cout << "PV : " << herolist[i]->get_health() << " | Attaque : " << herolist[i]->get_attack() << " | Armure : " << herolist[i]->get_armor() << " | Vitesse : " << herolist[i]->get_speed() << " | Mana : " << herolist[i]->get_mana() << endl;
                    cout << "Technique :" << endl;
                    if (herolist[i]->get_maxmana() > 0) {
                        cout << "1 - " << herolist[i]->get_attack1() << " | Mana : " << herolist[i]->get_manacost_attack1() << endl;
                        cout << "2 - " << herolist[i]->get_attack2() << " | Mana : " << herolist[i]->get_manacost_attack2() << endl;
                        cout << "3 - " << herolist[i]->get_attack3() << " | Mana : " << herolist[i]->get_manacost_attack3() << endl;
                    }
                    else {
                        cout << "1 - " << herolist[i]->get_attack1() << endl;
                        cout << "2 - " << herolist[i]->get_attack2() << endl;
                        cout << "3 - " << herolist[i]->get_attack3() << endl;
                    }
                    cout << "0 - " << herolist[i]->get_ultime() << " | CD : " << herolist[i]->get_cd_ult() << endl;
                    if (herolist[i]->has_passif()) {
                        cout << "Passif :" << endl;
                        cout << herolist[i]->get_passif() << endl;
                    }
                    printf("\n");
                }
            }
        }
    }
    else {
        if (mechantlist.size() == 0) {
            cout << "Votre liste de Mechant est vide !" << endl;
        }
        else {
            for (int i = 0; i <= mechantlist.size() - 1; i++) {
                if (mechantlist[i]->get_name() != "Kira") {
                    cout << "[" << i << "] : " << mechantlist[i]->get_name() << endl;
                    cout << "PV : " << mechantlist[i]->get_health() << " | Attaque : " << mechantlist[i]->get_attack() << " | Armure : " << mechantlist[i]->get_armor() << " | Vitesse : " << mechantlist[i]->get_speed() << " | Mana : " << mechantlist[i]->get_mana() << endl;
                    cout << "Technique :" << endl;
                    if (mechantlist[i]->get_maxmana() > 0) {
                        cout << "1 - " << mechantlist[i]->get_attack1() << " | Mana : " << mechantlist[i]->get_manacost_attack1() << endl;
                        cout << "2 - " << mechantlist[i]->get_attack2() << " | Mana : " << mechantlist[i]->get_manacost_attack2() << endl;
                        cout << "3 - " << mechantlist[i]->get_attack3() << " | Mana : " << mechantlist[i]->get_manacost_attack3() << endl;
                    }
                    else {
                        cout << "1 - " << mechantlist[i]->get_attack1() << endl;
                        cout << "2 - " << mechantlist[i]->get_attack2() << endl;
                        cout << "3 - " << mechantlist[i]->get_attack3() << endl;
                    }
                    cout << "0 - " << mechantlist[i]->get_ultime() << " | CD : " << mechantlist[i]->get_cd_ult() << endl;
                    if (mechantlist[i]->has_passif()) {
                        cout << "Passif :" << endl;
                        cout << mechantlist[i]->get_passif() << endl;
                    }
                    printf("\n");
                }
            }
        }
    }
}

void printStat(Personnage* p) {
    printf("\n");
    cout << "Vie restante : " << p->get_health() << "/" << p->get_maxhealth() << endl;
    cout << "Attaque : " << p->get_attack() << endl;
    if (p->get_armor() > 0) {
        cout << "Armure : " << p->get_armor() << endl;
    }
    cout << "Vitesse : " << p->get_speed() << endl;
    if (p->get_maxmana() > 0) {
        cout << "Mana restant : " << p->get_mana() << "/" << p->get_maxmana() << endl;
    }
    printf("\n");
}

Hero* suggestHeroChoice(string name, vector<Hero*>& herolist, vector<Mechant*>& mechantlist) {
    int h;
    cout << name << ") Vous etes un Hero" << endl;

    while (true) {
        cout << name << ") Choisissez un hero parmi la liste suivante :" << endl;
        printCharList(herolist, mechantlist, true);
        cin >> h;

        if (h >= 0 && h < herolist.size()) {
            Hero* p1c = herolist[h];
            cout << name << ") Vous avez choisi " << p1c->get_name() << endl;
            return p1c;
        }
        else {
            cout << "Votre choix ne figure pas dans la liste !" << endl;
        }
    }
}


Mechant* suggestMechantChoice(string name, vector<Hero*>& herolist, vector<Mechant*>& mechantlist) {
    int h;
    cout << name << ") Vous etes un Mechant" << endl;
    while (true) {
        cout << name << ") Choisissez un mechant parmis la liste suivante :" << endl;
        printCharList(herolist, mechantlist, false);
        cin >> h;
        if (h > herolist.size() - 1) {
            cout << "Votre choix ne figure pas dans la liste !" << endl;
        }
        else {
            Mechant* p2c = mechantlist[h];
            cout << name << ") Vous avez choisit " << p2c->get_name() << endl;
            return p2c;
        }

    }
}

void checkWin(Personnage* p1, Personnage* p2, string p1name, string p2name) {
    if (p1->get_health() <= 0 && p1->has_revive()) {
        if (p2->get_name() != "Kira") {
            if (p1->get_name() == "Gojo") {
                cout << p1->get_name() << " : Sur Terre comme au Ciel, moi seul merite d'etre honore" << endl;
                cout << p1name << " se releve de ses blessures !" << endl;
                p1->set_maxmana(p1->get_maxmana() - 400);
                p1->set_maxhealth(75);
                p1->set_health(75);
                cout << p1name << ") -400 Mana Max" << endl;
                cout << p1name << ") " << p1->get_health() << "/" << p1->get_maxhealth() << "PV" << endl;
            }
            else if (p1->get_name() == "Ener") {
                cout << p1->get_name() << " : Les gens ne craignent pas Dieu, la peur elle-même est Dieu" << endl;
                cout << p1name << " se releve de ses blessures !" << endl;
                p1->set_maxhealth(95);
                p1->set_health(95);
                cout << p1name << ") " << p1->get_health() << "/" << p1->get_maxhealth() << "PV" << endl;
            }
            p1->can_revive(false);
        }
    }
    if (p1->get_health() <= 0) {
        cout << "Victoire de " << p1name << endl;
        delete p1;
        delete p2;
        p1 = nullptr;
        p2 = nullptr;
        exit(0);
    }
    else if (p2->get_health() <= 0) {
        cout << "Victoire de " << p2name << endl;
        delete p1;
        delete p2;
        p1 = nullptr;
        p2 = nullptr;
        exit(0);
    }
}

int makeAction(Personnage* p, int attacksender) {
    int brutdamage;
    printf("\n");
    if (p->get_action() == 1) {
        brutdamage = p->get_damage_attack1();
        p->set_mana(p->get_mana() - p->get_manacost_attack1());
        cout << p->get_attack1() << " !" << endl;
    } else if (p->get_action() == 2) {
        brutdamage = p->get_damage_attack2();
        p->set_mana(p->get_mana() - p->get_manacost_attack2());
        cout << p->get_attack2() << " !" << endl;
    } else if (p->get_action() == 3) {
        brutdamage = p->get_damage_attack3();
        p->set_mana(p->get_mana() - p->get_manacost_attack3());
        cout << p->get_attack3() << " !" << endl;
    } else if (p->get_action() == 0) {
        if (p->get_name() == "Gogeta") {
            brutdamage = 999999;
        } else {
            brutdamage = p->get_ultimate();
        }
        cout << p->get_ultime() << " !" << endl;
    }
    return brutdamage;
}

int chooseAttack(Personnage* p, string name) {
    int action;
    while (true) {
        cout << name << ") Quel attaque souhaitez-vous faire ?" << endl;
        if (p->get_maxmana() > 0) {
            cout << "1 - " << p->get_attack1() << " | Mana : " << p->get_manacost_attack1() << endl;
            cout << "2 - " << p->get_attack2() << " | Mana : " << p->get_manacost_attack2() << endl;
            cout << "3 - " << p->get_attack3() << " | Mana : " << p->get_manacost_attack3() << endl;
        }
        else {
            cout << "1 - " << p->get_attack1() << endl;
            cout << "2 - " << p->get_attack2() << endl;
            cout << "3 - " << p->get_attack3() << endl;
        }
        if (!p->is_ult_usable()) {
            cout << "0 - " << p->get_ultime() << " | Utilisable dans : " << p->get_cd_ult() << " tours" << endl;
        }
        else {
            cout << "0 - " << p->get_ultime() << " | Utilisable !" << endl;
        }

        cin >> action;
        if (action == 0) {
            if (!p->is_ult_usable()) {
                cout << "Vous etes encore en Cooldown de votre Ultime" << endl;
                continue;
            }
        }
        else if (action == 1) {
            if (p->get_mana() < p->get_manacost_attack1()) {
                cout << "Vous n'avez pas assez de mana pour utiliser cette Technique !" << endl;
                continue;
            }
        }
        else if (action == 2) {
            if (p->get_mana() < p->get_manacost_attack2()) {
                cout << "Vous n'avez pas assez de mana pour utiliser cette Technique !" << endl;
                continue;
            }
        }
        else if (action == 3) {
            if (p->get_mana() < p->get_manacost_attack3()) {
                cout << "Vous n'avez pas assez de mana pour utiliser cette Technique !" << endl;
                continue;
            }
        }
        printf("\n");
        if (action == 1) {
            if (p->get_maxmana() > 0) {
                cout << name << ") -" << p->get_manacost_attack1() << " Mana" << endl;
            }
        }
        else if (action == 2) {
            if (p->get_maxmana() > 0) {
                cout << name << ") -" << p->get_manacost_attack2() << " Mana" << endl;
            }
        }
        else if (action == 3) {
            if (p->get_maxmana() > 0) {
                cout << name << ") -" << p->get_manacost_attack3() << " Mana" << endl;
            }
        }
        p->set_action(action);
        return makeAction(p, p->get_attack());
    }


}

int chooseArmor(Personnage* p, Personnage* p2, string name) {
    printf("\n");
    int action;
    if (p2->get_action() == 0 || p->get_name() == "Saitama" || p2->get_name() == "Saitama") {
        action = 1;
    }
    else if (p2->get_action() != 0) {
        cout << name << ") Quel defense souhaitez-vous faire ?" << endl;
        cout << "1 - Encaisser" << endl;
        cout << "2 - Esquiver " << p->get_speed() << "%" << endl;
        cout << "3 - Parer" << endl;
        cin >> action;
    }
    return action;
}

void makeArmor(int action, Personnage* p, int brutdamage, Personnage* p2, string p1name, string p2name) {
    int damage;
    printf("\n");
    if (action == 1) {
        if (p->get_name() == "Zoro") {
            srand(time(0));
            int nombreAleatoire = rand() % 66;
            damage = p->encaisser(0, brutdamage);
            p->set_health(p->get_health() - damage);
        } else {
            damage = p->encaisser(p->get_armor(), brutdamage);
            p->set_health(p->get_health() - damage);
        }
    }
    else if (action == 2) {
        damage = p->esquive(p->get_armor(), p->get_speed(), brutdamage);
        if (damage == 0) {
            p->set_speed(p->get_speed() - 5);
            cout << p1name << ") " << p2->get_speed() << "Vitesse (-5 Vitesse)" << endl;
        }
        else {
            p->set_health(p->get_health() - damage);
        }
    }
    else if (action == 3) {
        if (p->get_name() == "Zoro") {
            srand(time(0));
            int nombreAleatoire = rand() % 66;
            damage = p->encaisser(0, brutdamage);
        } else {
            damage = p->parer(p->get_armor(), brutdamage);
        }
        if (damage == brutdamage / 4) {
            p->set_health(p->get_health() - damage);
            p->set_armor(p->get_armor() - 15);
            p2->set_health(p2->get_health() - damage / 2);
            cout << p1name << ") " << p2->get_health() << "/" << p2->get_maxhealth() << " (-" << damage << " PV)" << endl;
            cout << p1name << ") " << p2->get_armor() << " Armure (-15 Armure)" << endl;
        }
    }
    if (damage > 0) {
        cout << p2name << ") " << p->get_health() << "/" << p->get_maxhealth() << " (-" << damage << " PV)" << endl;
    }
    checkWin(p, p2, p1name, p2name);
    if (damage > 0 || damage == brutdamage / 4) {
        if (p2->get_name() == "Shigaraki") {
            float pourcent = 10.0 / 100;
            int malus_health = static_cast<int>(p->get_maxhealth() * pourcent);
            p->set_maxhealth(p->get_maxhealth() - malus_health);
            cout << "Desintegration" << endl;
            cout << p1name << ") " << "(-" << malus_health << " PV Max)" << endl;
        }

    }
    checkWin(p, p2, p1name, p2name);
}

void resetround(Personnage* p1, Personnage* p2) {
    p1->set_cd_ult(p1->get_cd_ult() - 1);
    p2->set_cd_ult(p2->get_cd_ult() - 1);

    p1->regen_mana(10);
    p2->regen_mana(10);

    if (p2->get_name() == "Kokushibo") {
        if (p1->get_name() != "Yorrichi") {
            p2->set_health(p2->get_health() + 100);
            cout << "Regeneration Passive de Kokushibo +100PV" << endl;
        }
        else {
            cout << "Le Souffle du Soleil empeche la Regeneration Passive de Kokushibo !" << endl;
        }
    }
    else if (p2->get_name() == "Zamasu") {
        srand(time(0));
        int randomValue = rand() % 100 + 1;
        if (randomValue <= 5) {
            std::cout << "Volonté de Zamasu !" << std::endl;
            p1->set_health(0);
        }
    }
    else if (p1->get_name() == "Gojo") {
        if (p1->get_mana() <= 450) {
            p1->set_speed(p1->get_speed() - 25);
            cout << "Malus de Super Vitesse (-25 Vitesse)" << endl;
        }
        else {
            if (p1->get_speed() <= 45) {
                p1->set_speed(p1->get_speed() + 25);
                cout << "Bonus de Super Vitesse (+25 Vitesse)" << endl;
            }
        }
    }
    else if (p1->get_name() == "Izuku") {
        float pourcent = 5.0 / 100;
        int buff_attack = static_cast<int>(p1->get_attack() * pourcent);
        int buff_armor = static_cast<int>(p1->get_armor() * pourcent);
        int buff_speed = static_cast<int>(p1->get_speed() * pourcent);
        p1->set_attack(p1->get_attack() + buff_attack);
        p1->set_armor(p1->get_armor() + buff_armor);
        p1->set_speed(p1->get_speed() + buff_armor);
        cout << "One For All ! Revetement Integral : " << (p1->get_attack() + p1->get_armor() + p1->get_speed()) / 3 << " %" << endl;
        cout << "+ " << buff_attack << " Attaque" << endl;
        cout << "+ " << buff_armor << " Armure" << endl;
        cout << "+ " << buff_speed << " Vitesse" << endl;
    }
}

int main() {
    vector<Hero*> herolist;
    vector<Mechant*> mechantlist;

    string p1 = "Joueur 1";
    cout << p1 << " quel est votre pseudo ?" << endl;
    cin >> p1;
    string p2 = "Joueur 2";
    cout << p2 << " quel est votre pseudo ?" << endl;
    cin >> p2;

    Hero* gojo = new Hero("Gojo", 150, 60, 15, 50, 1000, 75, 200, 500, 5, "Rouge : Flammes Incandescentes", "Bleu : Vague d'Eau Abyssale", "Violet : Eclair Pourpre", "Extension du territoire : Domaine de l'Infini");
    gojo->set_passif("Sort D'Inversion : Lors de sa Premiere mort, Gojo reviendra a la vie avec 75 PV mais perdra 400 de Mana de facon permanente\nSuper Vitesse : S'il a moins de 450 de Mana, sa Vitesse diminuera de 25");
    gojo->can_revive(true);
    herolist.push_back(gojo);
    Hero* izuku = new Hero("Izuku", 200, 40, 25, 30, 250, 20, 50, 100, 3, "Detroit Smash", "Delaware Smash", "Texas Smash", "Delaware Detroit Smash");
    izuku->set_passif("One For All : Izuku gagnera 5% de sa force, de son armure et de sa vitesse a chaque tour");
    herolist.push_back(izuku);
    Hero* zoro = new Hero("Zoro", 250, 35, 40, 30, 70, 25, 35, 50, 3, "Santoryu : Ittoryu Iai : Shishi Sonson", "Santoryu : Nitoryu : 108 Pound Phoenix", "Santoryu : Kyutoryu : Asura", "Santoryu : Sanzen Sekai");
    zoro->set_passif("Revêtement du Haki des Rois : Les attaques de Zoro ont 65% de passer a travers l'Armure");
    herolist.push_back(zoro);
    Hero* yoriichi = new Hero("Yoriichi", 230, 35, 10, 35, 800, 35, 75, 250, 5, "Valse", "Ciel d'Azur Sans Nuages", "Dragon du Halo Solaire - Tete Dansante", "Treizieme Mouvement");
    yoriichi->set_passif("Souffle du Soleil : Le joueur face a Yorrichi est dans l'incapacite de recuperer de la vie de quelconque facon");
    herolist.push_back(yoriichi);
    Hero* gogeta = new Hero("Gogeta", 235, 40, 15, 40, 1250, 100, 225, 500, 10, "Kikoha", "Big Bang Attack", "Big Bang Kamé Hamé Ha", "Soul Punisher");
    gogeta->set_passif("Soul Punisher : Son Ultime tue directement l'adversaire");
    herolist.push_back(gogeta);
    Hero* saitama = new Hero("Saitama", 999999, 999999, 999999, 999999, 0, 0, 0, 0, 0, "Eternuement", "Pichenette", "-30% sur le rayon fromage", "Serious Punch");
    herolist.push_back(saitama);

    Mechant* toji = new Mechant("Toji", 240, 50, 35, 35, 0, 0, 0, 0, 3, "Lame Tranchante", "Contre", "Impact Brutal", "Zero Absolu");
    toji->set_passif("Serment Inne : Toji ne possède pas de Mana et aucune de ses attaques n'en consomment");
    mechantlist.push_back(toji);
    Mechant* shigaraki = new Mechant("Shigaraki", 180, 45, 15, 25, 350, 30, 65, 125, 4, "Toucher de la Mort", "Decomposition", "Onde de Choc Desintegrante", "Regeneration Anormale");
    shigaraki->set_passif("Desintegration : A chaque Attaque que fera Shigaraki, le joueur touche perdra 10% de ses PV Max");
    mechantlist.push_back(shigaraki);
    Mechant* ener = new Mechant("Ener", 190, 55, 25, 40, 100, 25, 30, 45, 4, "Sango", "Despia", "El Thor", "Raigo");
    ener->set_passif("Shinzo Massage : Ener reviendra a la vie avec 95 PV Max");
    ener->can_revive(true);
    mechantlist.push_back(ener);
    Mechant* kokushibo = new Mechant("Kokushibo", 150, 50, 20, 35, 700, 50, 75, 300, 4, "Premier Mouvement : Lune Obscur: Palais Vesperal", "Septieme Mouvement : Miroir Malefique, Sublimation Lunaire", "Dixieme Mouvement : Rayons de Lune Perforant le Feuillage", "Seizieme Mouvement : Arc-en-Ciel Lunaire - Demi-Lune");
    kokushibo->set_passif("Regeneration Naturel : Kokushibo regenere 100 PV a chaque tours");
    mechantlist.push_back(kokushibo);
    Mechant* zamasu = new Mechant("Zamasu", 235, 40, 15, 40, 1250, 100, 225, 500, 4, "Kikoha", "Zettai no Ikazuchi", "Illusion smash", "Hikari no KabeSoul Punisher");
    zamasu->set_passif("Volonté de Zamasu : Zamazu a 5% de chance à chaque fin de tour de directement gagner la partie.");
    mechantlist.push_back(zamasu);
    Mechant* kira = new Mechant("Kira", 0, 0, 0, 0, 0, 0, 0, 0, 0, "", "", "", "");
    mechantlist.push_back(kira);

    int HMchoice;
    while (true) {
        cout << p1 << ") Hero(1) ou Mechant(2) ?" << endl;
        cin >> HMchoice;
        if (HMchoice < 1 || HMchoice > 2) {
            cout << "Vous devez choisir Hero(1) ou Mechant(2) !" << endl;
        }
        else {
            break;
        }
    }


    int armor;
    int brutdamage;
    printf("\n");
    if (HMchoice == 1) {
        Hero* p1c = suggestHeroChoice(p1, herolist, mechantlist);
        printf("\n");
        Mechant* p2c = suggestMechantChoice(p2, herolist, mechantlist);
        if (p2c->get_name() == "Kira") {
            string reponse;
            cout << "Ryuk : Voici ton cahier Light, ecris le nom de ta victime dessus, cependant si tu te trompes, sa sera toi la victime" << endl;
            cin >> reponse;
            if (reponse == p1) {
                p2c->set_health(0);
            }
            else {
                p1c->set_health(0);
            }
            checkWin(p1c, p2c, p1, p2);
        }
        while (true) {
            if (p1c->get_speed() >= p2c->get_speed()) {
                printStat(p1c);
                if (p1c->is_ult_usable() || p1c->get_manacost_attack1() <= p1c->get_mana()) {
                    brutdamage = chooseAttack(p1c, p1);
                    armor = chooseArmor(p2c, p1c, p2);
                    makeArmor(armor, p2c, brutdamage, p1c, p1, p2);
                } else {
                    cout << p1 << ") Vous n'avez plus assez de Mana pour executer une Attaque" << endl;
                }
                printStat(p2c);
                if (p2c->is_ult_usable() || p2c->get_manacost_attack1() <= p2c->get_mana()) {
                    brutdamage = chooseAttack(p2c, p2);
                    armor = chooseArmor(p1c, p2c, p1);
                    makeArmor(armor, p1c, brutdamage, p2c, p2, p1);
                } else {
                    cout << p2 << ") Vous n'avez plus assez de Mana pour executer une Attaque" << endl;
                }
                resetround(p1c, p2c);
            }
            else {
                printStat(p2c);
                if (p2c->is_ult_usable() || p2c->get_manacost_attack1() <= p2c->get_mana()) {
                    brutdamage = chooseAttack(p2c, p2);
                    armor = chooseArmor(p1c, p2c, p1);
                    makeArmor(armor, p1c, brutdamage, p2c, p2, p1);
                } else {
                    cout << p2 << ") Vous n'avez plus assez de Mana pour executer une Attaque" << endl;
                }
                printStat(p1c);
                if (p1c->is_ult_usable() || p1c->get_manacost_attack1() <= p1c->get_mana()) {
                    brutdamage = chooseAttack(p1c, p1);
                    armor = chooseArmor(p2c, p1c, p2);
                    makeArmor(armor, p2c, brutdamage, p1c, p1, p2);
                } else {
                    cout << p1 << ") Vous n'avez plus assez de Mana pour executer une Attaque" << endl;
                }
                resetround(p1c, p2c);
            }
        }

    }
    else if (HMchoice == 2) {
        Mechant* p1c = suggestMechantChoice(p1, herolist, mechantlist);
        printf("\n");
        Hero* p2c = suggestHeroChoice(p2, herolist, mechantlist);
        if (p1c->get_name() == "Kira") {
            string reponse;
            cout << "Ryuk : Voici ton cahier Light, ecris le nom de ta victime dessus, cependant si tu te trompes, sa sera toi la victime" << endl;
            cin >> reponse;
            if (reponse == p2) {
                p1c->set_health(0);
            }
            else {
                p2c->set_health(0);
            }
            checkWin(p2c, p1c, p2, p1);
        }
        while (true) {
            if (p1c->get_speed() >= p2c->get_speed()) {
                printStat(p1c);
                if (p1c->is_ult_usable() || p1c->get_manacost_attack1() <= p1c->get_mana()) {
                    brutdamage = chooseAttack(p1c, p1);
                    armor = chooseArmor(p2c, p1c, p2);
                    makeArmor(armor, p2c, brutdamage, p1c, p2, p1);
                } else {
                    cout << p1 << ") Vous n'avez plus assez de Mana pour executer une Attaque" << endl;
                }
                printStat(p2c);
                if (p2c->is_ult_usable() || p2c->get_manacost_attack1() <= p2c->get_mana()) {
                    brutdamage = chooseAttack(p2c, p2);
                    armor = chooseArmor(p1c, p2c, p1);
                    makeArmor(armor, p1c, brutdamage, p2c, p1, p2);
                } else {
                    cout << p2 << ") Vous n'avez plus assez de Mana pour executer une Attaque" << endl;
                }
                resetround(p2c, p1c);
            }
            else {
                printStat(p2c);
                if (p2c->is_ult_usable() || p2c->get_manacost_attack1() <= p2c->get_mana()) {
                    brutdamage = chooseAttack(p2c, p2);
                    armor = chooseArmor(p1c, p2c, p1);
                    makeArmor(armor, p1c, brutdamage, p2c, p1, p2);
                }else {
                    cout << p2 << ") Vous n'avez plus assez de Mana pour executer une Attaque" << endl;
                }
                printStat(p1c);
                if (p1c->is_ult_usable() || p1c->get_manacost_attack1() <= p1c->get_mana()) {
                    brutdamage = chooseAttack(p1c, p1);
                    armor = chooseArmor(p2c, p1c, p2);
                    makeArmor(armor, p2c, brutdamage, p1c, p2, p1);
                } else {
                    cout << p1 << ") Vous n'avez plus assez de Mana pour executer une Attaque" << endl;
                }
                resetround(p2c, p1c);
            }
        }
    }
    for (Hero* hero : herolist) {
        delete hero;
        hero = nullptr;
    }
    herolist.clear();
    for (Mechant* mechant : mechantlist) {
        delete mechant;
        mechant = nullptr;
    }
    mechantlist.clear();
}
