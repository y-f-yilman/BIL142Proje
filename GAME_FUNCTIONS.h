//
// Created by o_ark on 24.02.2024.
//

#ifndef UNTITLED4_GAME_FUNCTIONS_H
#define UNTITLED4_GAME_FUNCTIONS_H
#include <iostream>
#include <string>
#include <random>

using namespace std;

class Ship{
public:
    string Type;
    int Fuel;
    int Health;
    int Money;
};

class GAME {
    Ship Player;

    GAME() {
        int fuelcost{33};
        Player.Fuel = 100;
        Player.Health = 100;
        Player.Money = 0;
    }

    void ShipSelection() {
        cout << "Welcome To Cosmic Voyager Divan Edition" << endl
             << "Please choose the kind of ship you want to explore our galaxy with(STRONG, FAST or NORMAL:" << endl;
        cin >> Player.Type;
        if(Player.Type == "STRONG" || Player.Type == "FAST" || Player.Type == "NORMAL"){
            cout << "You have selected the " << Player.Type << "EST of all the ships in the galaxy";
        }
    }

    void PirateAttack(){
        int Damage;
        int EscapeRatio;
        string choice;
        if (Player.Type == "STRONG"){
            Damage = 15;
            EscapeRatio = 1;
        }
        else if (Player.Type == "FAST"){
            Damage = 45;
            EscapeRatio = 3;
        }
        else if (Player.Type == "NORMAL"){
            Damage = 30;
            EscapeRatio = 1;
        }
        cout << "Bir Seçenek Seç:";
        cin >> choice;

    }

    void AbandonedPlanet(){
        if (rand % 2 == 0){
            Player.Money +=10;
        }
        else if(rand % 2 == 1){
            PirateAttack();
        }
    }
};
#endif //UNTITLED4_GAME_FUNCTIONS_H
