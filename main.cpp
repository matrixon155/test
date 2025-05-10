#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct postava{
    string jmeno;
    int hp;
    int utok;
};

void uvodniMenu();
void novaHra();

int main(){
    uvodniMenu();
    return 0;
}

void uvodniMenu() {
    cout << "Vitej v textove RPG hre!" << endl;
    cout << "------------------------" << endl;
    cout << "1. Nova hra" << endl;
    cout << "2. Konec" << endl;
    cout << "Zadej volbu: ";
    int volba;
    cin >> volba;
    cin.ignore();
    if (volba == 1) {
        system("cls");
        novaHra();
    } else {
        cout << "Konec hry. Mej se!" << endl;
    }
}

void novaHra() {
    srand(time(0));
    postava hrac;
    postava goblin;

    cout << "Zadej sve jmeno: ";
    getline(cin, hrac.jmeno);

    hrac.hp = 30;
    hrac.utok = 8;

    goblin.jmeno = "Goblin";
    goblin.hp = 20;
    goblin.utok = 5;

    cout << "\nVitej ve hre " << hrac.jmeno << "!" << endl;
    cout << "Z temneho lesa se vynoril " << goblin.jmeno << "!" << endl;
    cout << "Musis ho porazit, abys mohl pokracovat." << endl;
    cout << "Hrac: " << hrac.hp << "hp" << endl;
    cout << goblin.jmeno << ": " << goblin.hp << "hp" << endl;

    while (hrac.hp > 0 && goblin.hp > 0) {
        cout << "\nCo udelas?" << endl;
        cout << "1. Utocit" << endl;
        cout << "2. Branit se" << endl;
        cout << "3. Utect" << endl;
        cout << "> ";
        int volba;
        cin >> volba;
        cin.ignore();
        if (volba == 1) {
            int nahoda = rand() % 100;
            if (nahoda < 70) { // 70% zasah
                goblin.hp -= hrac.utok;
                cout << "Utocis! Goblin ztraci " << hrac.utok << "hp." << endl;
            } else if (nahoda < 90) { // 20% goblin odrazi a zautoci
                hrac.hp -= goblin.utok;
                cout << "Goblin tvuj utok odrazil a zautocil zpet! Ztracis " << goblin.utok << "hp." << endl;
            } else { // 10% hrac utok vrati
                goblin.hp -= 2 * hrac.utok;
                cout << "Parada! Utok jsi vratil goblinovi a on ztraci " << 2 * hrac.utok << "hp!" << endl;
            }
        } else if (volba == 2) {
            int nahoda = rand() % 100;
            if (nahoda < 50) { // 50% obrana uspesna
                cout << "Obrana uspesna! Neztracis zadne hp." << endl;
            } else {
                hrac.hp -= goblin.utok;
                cout << "Obrana selhala! Goblin te zasahl za " << goblin.utok << "hp." << endl;
            }
        } else if (volba == 3) {
            int nahoda = rand() % 100;
            if (nahoda < 40) { // 40% utek uspesny
                cout << "Podarilo se ti utect!" << endl;
                cout << "Stiskni Enter pro ukonceni...";
                cin.get();
                return;
            } else {
                hrac.hp -= goblin.utok;
                cout << "Utek se nepovedl! Goblin te zasahl za " << goblin.utok << "hp." << endl;
            }
        } else {
            cout << "Neplatna volba." << endl;
        }
        cout << "Hrac: " << hrac.hp << "hp" << endl;
        cout << goblin.jmeno << ": " << goblin.hp << "hp" << endl;
    }

    if (hrac.hp <= 0) {
        cout << "Prohral jsi! Chces zacit znovu? (a/n): ";
        char odpoved;
        cin >> odpoved;
        cin.ignore();
        if (odpoved == 'a' || odpoved == 'A') {
            system("cls");
            novaHra();
            return;
        } else {
            cout << "Stiskni Enter pro ukonceni...";
            cin.get();
        }
    } else if (goblin.hp <= 0) {
        cout << "Vyhral jsi! Stiskni Enter pro pokracovani...";
        cin.get();
    }
}
    

