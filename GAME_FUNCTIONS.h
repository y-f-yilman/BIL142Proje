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

public:

    Ship Player;
    GAME() {
        int fuelcost{33};
        Player.Fuel = 100;
        Player.Health = 100;
        Player.Money = 0;
    }

    void ShipSelection() {
        cout << "Welcome To Cosmic Voyager Divan Edition" << endl
             << "Please choose the kind of ship you want to explore our galaxy with(STRONG, FAST or NORMAL):" << endl;
        cin >> Player.Type;
        if(Player.Type == "STRONG" || Player.Type == "FAST" || Player.Type == "NORMAL"){
            cout << "You have selected the " << Player.Type << "EST of all the ships in the galaxy" << endl;
        }
    }

    void PirateAttack(){
        int Damage;
        int EscapeRatio;
        int FightOutcome;
        int BargainMoney;
        string choice;

        random_device random_generator;
        mt19937 gen(random_generator());

        if (Player.Type == "STRONG"){
            Damage = 15;
            EscapeRatio = 3;
        }
        else if (Player.Type == "FAST"){
            Damage = 45;
            EscapeRatio = 1;
        }
        else if (Player.Type == "NORMAL"){
            Damage = 30;
            EscapeRatio = 2;
        }
        cout << "The pirates have you surrounded, Choose an option(RUN, FIGHT or BARGAIN):" << endl;
        cin >> choice;
        if (choice == "RUN"){
            if (Player.Fuel < 33){
                cout << "You don't have enough fuel to escape" << endl;
                Player.Fuel = 0;
            }
            else {
                Player.Fuel -= 33;
                uniform_int_distribution<>distribution(0, 4);
                int EscapeState = distribution(gen);
                if(EscapeRatio < EscapeState){
                    cout << "You have failed to fly away" << endl;
                    PirateAttack();
                }
                else {
                    cout << "You have successfully flied away" << endl;

                }
            }
        }
        else if(choice == "FIGHT"){
            uniform_int_distribution<>distribution(1, 2);
            FightOutcome = distribution(gen);
            switch (FightOutcome) {
                case 1:
                    cout << "You have taken "<< Damage <<" Damage from the pirates" << endl;
                    Player.Health -= Damage;
                    if (Player.Health < 0){
                        Player.Health = 0;
                    }
                    break;
                case 2:
                    cout << "You have successfully escaped the pirates!" << endl;
                    break;
            }
        }
        else if(choice == "BARGAIN"){
            uniform_int_distribution<>distribution(1, 3);
            BargainMoney = distribution(gen)*10;
            cout << "The pirates have decided to let you go if you pay them " << BargainMoney << " Galactic Credits" << endl;
            if(BargainMoney > Player.Money){
                cout << "You don't have enough money you have to escape or fight, choose your next action:" << endl;
                PirateAttack();
            }
            else if(BargainMoney < Player.Money){
                Player.Money -= BargainMoney;
            }
        }
    }

    void AbandonedPlanet(){
        int probability;
        random_device random_generator;
        mt19937 gen(random_generator());
        uniform_int_distribution<>distribution(1, 2);
        probability = distribution(gen);

        switch (probability) {
            default:
            case 1:
                cout << "You have found 10 Galactic credits" << endl;
                Player.Money += 10;
                break;
            case 2:
                cout << "You have encountered Pirates on the planet" << endl;
                PirateAttack();
                break;
        }
    }

    void AsteroidBelt(){
        int escape_probability;
        int Damage;
        int EscapeRatio;
        random_device random_generator;
        mt19937 gen(random_generator());
        uniform_int_distribution<>distribution(1, 2);
        escape_probability = distribution(gen);
        cout << "You have encountered an Asteroid Belt" << endl;

        if (Player.Type == "STRONG"){
            Damage = 5;
            EscapeRatio = 1;
        }
        else if (Player.Type == "FAST"){
            Damage = 15;
            EscapeRatio = 3;
        }
        else if (Player.Type == "NORMAL"){
            Damage = 10;
            EscapeRatio = 2;
        }

        switch (escape_probability) {
            default:
            case 1:
                cout << "You have got out of the asteroid belt without taking any damage" << endl;
                break;
            case 2:
                cout << "You have taken " << Damage << " Damage from the asteroid belt" << endl;
                Player.Health -= Damage;
                if (Player.Health < 0){
                        Player.Health = 0;
                }
                break;
        }
    }

    void Play(){
        int EventCaller;
        int score;
        int i;
        for (i = 1 ; i<=5 ; ++i){
            random_device random_generator;
            mt19937 gen(random_generator());
            uniform_int_distribution<>distribution(1, 3);
            EventCaller = distribution(gen);
            switch (EventCaller) {
                case 1:
                    PirateAttack();
                    break;
                case 2:
                    AbandonedPlanet();
                    break;
                case 3:
                    AsteroidBelt();
                    break;
            }
            score = (Player.Fuel*5) + (Player.Health*10) + (Player.Money*10) ;
            cout << "End of Day " << i << endl;
            cout << "Fuel: " << Player.Fuel<< endl;
            cout << "Health: " << Player.Health << endl;
            cout << "Galactic Credits: "<< Player.Money << endl;
            cout << "Day Score: " << score << endl;
            cout << "-----------------------------------------------" << endl;

            if(Player.Fuel == 0){
                cout << "You ran out of fuel, end of game" << endl;
                cout << "Your Final Score is "<< score << " points" << endl;
                return;
            }
            else if(Player.Health == 0){
                cout << "Your ship is obliterated" << endl;
                cout << "Your Final Score is "<< score << " points" << endl;
                return;
            }
        }
        if(Player.Fuel == 0){
            cout << "You ran out of fuel, end of game" << endl;
        }
        else if(Player.Health == 0){
            cout << "Your ship is obliterated" << endl;
        }
        else if(i = 5){
            cout << "Game ENDED" << endl;
        }
        cout << "Your Final Score is "<< score << " points" << endl;
    }
};
#endif //UNTITLED4_GAME_FUNCTIONS_H
