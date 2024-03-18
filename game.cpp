#include "game.h"
#include "ship.h"
#include "event.h"
#include "GeneralFunc.h"
#include "GameStarter.h"

#include <iostream>
#include <random>
#include <sstream>

//Initializing Player Ship Type
std::shared_ptr<Ship> Game::initializePlayerShip() {
    int choice{0};
    std::ostringstream shipInitializationMessage;
    while (true) {
        std::cin >> choice;
        if (choice >= 1 && choice <= 7) {
            break;
        } else {
            shipInitializationMessage << "Invalid choice. Please enter a number between 1 and 3.\n";
        }
    }
    switch (choice) {
        case 1:
            shipInitializationMessage << "You have chosen TORQUE OF GODS" << std::endl
            << "It is said that the TORQUE GOD was a ship design stolen from the very gods hundreds of years ago" << std::endl;
            playerShip_ = std::make_shared<FastShip>();
            break;
        case 2:
            shipInitializationMessage << "You have chosen THE WALL OF JOSEPHUS" << std::endl
            << "The WALL OF JOSEPHUS Holds the power of the walls that once separated the people of JOSEPHUS" << std::endl;
             playerShip_ = std::make_shared<StrongShip>();
            break;
        case 3:
            shipInitializationMessage << "You have chosen THE JENERIQUE" << std::endl
            << "The JENERIQUE is a ship that is widely used around the The GREAT KAELI" << std::endl;
             playerShip_ = std::make_shared<NormalShip>();
            break;
        case 4:
            shipInitializationMessage << "You have chosen THE VOYAGER" << std::endl
            <<"No one knows where the VOYAGER came from however it is said to be the key to understanding the universe" << std::endl;
             playerShip_ = std::make_shared<Voyager>();
            break;
        case 5:
            shipInitializationMessage << "You have chosen THE KAELI STAR" << std::endl
            << "The KAELI STAR is the most powerful ship in THE GREAT KAELI as it uses a KAELI Star to power it's engines" << std::endl;
             playerShip_ = std::make_shared<KÆLIStar>();
            break;
        case 6:
            shipInitializationMessage << "You have chosen THE STERILUS" << std::endl
            << "NO DATA CAN BE FOUND ABOUT THIS USELESS SHIP" << std::endl;
             playerShip_ = std::make_shared<STERILUS>();
            break;
        case 7:
            shipInitializationMessage << "You have chosen THE AURUM" << std::endl
            << "The ship widely used by the space pirates" << std::endl;
             playerShip_ = std::make_shared<AURUM>();
            break;
    }
    shipInitializationMessage << "Your adventure begins as you venture into THE GREAT KAELI" << std::endl;
    GeneralFunc::printWithTypingEffect(shipInitializationMessage.str());
    return playerShip_;
}

//Event Randomizer
Event Game::randomEventGenerator(){
    std::random_device random_generator; //random generator to choose the events
    std::mt19937 gen(random_generator());
    std::uniform_int_distribution<> distribution(0, 2);
    int event = distribution(gen);
    return static_cast<Event>(event);
}


//Event Handler
void Game::eventHandler(const Event &event,std::shared_ptr<Ship>& Ship_){
    switch (event){
        case Event::AsteroidBelt:
            EventFunctions::asteroidBeltEvent(Ship_);
            break;
        case Event::AbandonedPlanet:
            EventFunctions::abandonedPlanetEvent(Ship_);
            break;
        case Event::SpacePirates:
            EventFunctions::pirateAttackEvent(Ship_);
            break;
    }
}

//Score Displayed
void Game::displayScore(std::shared_ptr<Ship>  const& ship_){
    int score = ship_->getFuel()*5 + ship_->getHealth()*10 + ship_->getMoney()*10;
    std::ostringstream status;
    status <<  "Fuel:" << ship_->getFuel() << std::endl
     <<  "Health:" << ship_->getHealth() << std::endl
     <<  "Money:" << ship_->getMoney() << std::endl
     <<  "Score:" << score << std::endl;
    GeneralFunc::printWithTypingEffect(status.str());
}

//Player
void Game::play(std::shared_ptr<Ship> Ship_) {
    for(int i = 1; i <= 5 && Ship_->getFuel() > 0 && Ship_->getHealth() > 0; ++i){
        Game::eventHandler(randomEventGenerator(), Ship_);
        std::cout << "--DAY " << i << " SCORE--" << std::endl;
        Game::displayScore(Ship_);}
    std::cout << "---FINAL SCORE---" << std::endl;
    Game::displayScore(Ship_);
}





