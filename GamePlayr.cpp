//
// Created by o_ark on 16.03.2024.
//

#include "GamePlayr.h"
#include "ShipProperty.h"
#include "Ship.h"

Event randomEventGenerator(){
    std::random_device random_generator; //random generator to choose the events
    std::mt19937 gen(random_generator());
    std::uniform_int_distribution<> distribution(1, 3);
    int event = distribution(gen);
    return static_cast<Event>(event);
}

std::random_device random_generator; //random generator to choose the events
std::mt19937 gen(random_generator());


void displayScore(std::unique_ptr<ship> ship_){
    int score = ship_->getFuel()*5 + ship_->getHealth()*10 + ship_->getMoney()*10;
    std::cout <<  "Fuel:" << ship_->getFuel() << std::endl;
    std::cout <<  "Health:" << ship_->getHealth() << std::endl;
    std::cout <<  "Money:" << ship_->getMoney() << std::endl;
    std::cout <<  "Score:" << score << std::endl;
 }

void pirateAttackEvent(std::unique_ptr<ship> ship_){
    bool escapeAttempt = false;
    bool negotiationAttempt = false;
    std::cout << "Space pirates are approaching! Choose your action:\n";
    std::cout << "1. Escape (" << ship_->getFuelcost() << " fuel cost)\n";
    std::cout << "2. Fight\n";
    std::cout << "3. Negotiate\n";

    while(true){
        int choice;
        std::cin >> choice;

        if (choice == 1 && !escapeAttempt){
            if(ship_->getFuel() < ship_->getFuelcost()){
                escapeAttempt = true;
                continue;
            }
            ship_->fuelLoss(ship_->getFuelcost());
            float escapeChance = ship_->getEscapeModifier()*50;
            std::uniform_int_distribution<>distribution(1,100);
            int escape = distribution(gen);
            if(escape < escapeChance){
                std::cout << "Successfully escaped the space pirates!" << std::endl;
                break;
            }
            else {
                std::cout << "Failed to escape. You cannot escape again." << std::endl;
                escapeAttempt = true;
                continue;
            }
        }

        else if (choice == 2){
            std::uniform_int_distribution<>distribution(1,2);
            int fightwin = distribution(gen);
            switch(fightwin){
                case 1:
                    std::cout << "LOST THE FIGHT" << std::endl;
                    ship_->takeDamage(30);
                    break;
                case 2:
                    std::cout << "WON THE FIGHT" << std::endl;
                    break;
            }
            break;
        }

        else if(choice == 3 && !negotiationAttempt){
            std::uniform_int_distribution<>distribution(1,3);
            int payment = distribution(gen)*10;
            if (ship_->getMoney() < payment){
                std::cout << "Not Enough Gold" << std::endl;
                negotiationAttempt = true;
                continue;
            }
            ship_->moneyWork(-payment);
            std::cout << "Negotiated with pirates for " << payment << " Galactic Credits" << std::endl;
            break;
        }
        else if((choice == 1 && escapeAttempt) || (choice == 3 && negotiationAttempt)){
            std::cout << "You cannot choose this action again." << std::endl;
        }
        else{
            std::cout << "Invalid action. Please Choose Again" << std::endl;
        }
    }

}

void asteroidBeltEvent(std::unique_ptr<ship> ship_){
    std::uniform_int_distribution<> distribution(1, 2);
    int asteroidBeltOutcome = distribution(gen);

    switch (asteroidBeltOutcome) {
        case 1:
            ship_->takeDamage(10);
            break;
        case 2:
            std::cout << "You have escaped the asteroids";
            break;
    }
}

void abandonedPlanetEvent(std::unique_ptr<ship> ship_){
    std::uniform_int_distribution<> distribution(1, 2);
    int abandonedPlanetOutcome = distribution(gen);
    switch (abandonedPlanetOutcome) {
        case 1:
            ship_->moneyWork(10);
            std::cout << "You found an abandoned planet and earned 10 golds";
            break;
        case 2:
            pirateAttackEvent(std::move(ship_));
            break;
    }
}


void eventHandler(const Event &event,std::unique_ptr<ship> ship_){
    switch (event){
        case Event::asteroidBelt:
            asteroidBeltEvent(std::move(ship_));
            break;
        case Event::abandonedPlanet:
            abandonedPlanetEvent(std::move(ship_));
            break;
        case Event::spacePirates:
            pirateAttackEvent(std::move(ship_));
            break;
    }
}

void play(std::unique_ptr<ship> ship_, spaceVoyage& game){
    for (int i = 0; i < 5 && ship_->getFuel() > 0; ++i) {
        eventHandler(randomEventGenerator(), std::move(ship_));
        displayScore(std::move(ship_));
    }
}

