#include "GameEngine.h"
#include "General.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iostream>
#include <sstream> // Include for std::ostringstream
#include <random>
#include <string>


void GameEngine::displayStatus() const {
  std::ostringstream statusStream;
  int score = (playerShip.getFuel() * 5) + (playerShip.getHealth() * 10) +
              (playerShip.getMoney() * 10);

  statusStream << "\nShip Status:" << std::endl;
  statusStream << "Fuel: " << playerShip.getFuel() << std::endl;
  statusStream << "Health: " << playerShip.getHealth() << std::endl;
  statusStream << "Money: " << playerShip.getMoney() << std::endl;
  statusStream << "Current Score: " << score << "\n" << std::endl;

  General::printWithTypingEffect(
      statusStream.str()); // Typing effect for the status display
}

GameEngine::GameEngine(Ship::Type shipType)
    : playerShip(shipType), eventCount(0) {
  // Seed the random number generator
  srand(static_cast<unsigned>(time(0)));
  // Initialize event handlers
  eventHandlers.push_back(std::bind(&GameEngine::handleAsteroidBelt, this));
  eventHandlers.push_back(std::bind(&GameEngine::handleAbandonedPlanet, this));
  eventHandlers.push_back(std::bind(&GameEngine::handleSpacePirates, this));
}

void GameEngine::startGame() {
  std::cout << "You enter your ship and leave the SPACE VOYAGERs GUILD STRONGHOLD " << std::endl;
   // Initial display of ship status at the start of the game


  while (playerShip.getFuel() > 0 && playerShip.getHealth() > 0  &&eventCount < 5) {
      std::random_device random_generator; //random generator to choose the events
      std::mt19937 gen(random_generator());
      std::uniform_int_distribution<>distribution(0,2);
      int eventIndex = distribution(gen);
    executeEvent(static_cast<Event>(eventIndex));
    eventCount++;
    std::ostringstream Day;
    int k = static_cast<int>(eventCount);
    Day << "Day " << k;
    General::printWithTypingEffect(Day.str());
     displayStatus();// Display updated status after each event
  }
  calculateFinalScore(); // This will display the final score
}

void GameEngine::executeEvent(Event event) {
  auto eventIndex = static_cast<std::vector<std::function<void()>>::size_type>(event);
  if (eventIndex < eventHandlers.size()) {
    eventHandlers[eventIndex]();
  }
}

void GameEngine::handleAsteroidBelt() {
    std::random_device random_generator; //random generator to choose the events
    std::mt19937 gen(random_generator());
    std::uniform_int_distribution<>distribution(1,4);
    int asteroid_event = distribution(gen);
    std::ostringstream asteroidBelt_reason;
    switch (asteroid_event){
        case 1 :
            General::printWithTypingEffect("Your path is blocked by a cosmic anomaly ");
            General::printWithTypingEffect("You have no other choice but to go through the asteroid belt");
            break;
        case 2 :
            General::printWithTypingEffect("You have received a distress signal from an asteroid belt, once you arrived, you find the wreckage of a ship");
            General::printWithTypingEffect("The ship turns into a ball of fire and explodes");
            General::printWithTypingEffect("You have no other choice but to go through the asteroid belt");
            break;
        case 3:
            General::printWithTypingEffect("You came across a VOYAGER claiming that he found a COSMIC POTATO cache in an asteroid belt");
            General::printWithTypingEffect("Once you arrive at the cache you find the place emptied");
            General::printWithTypingEffect("You see pirate ships coming your way");
            General::printWithTypingEffect("You have no other choice but to go through the asteroid belt");
            break;
        case 4:
            General::printWithTypingEffect("A SKFOSMF beast starts to chase your ship");
            General::printWithTypingEffect("You have no other choice but to go through the asteroid belt");
    }
    std::random_device random_generator2; //random generator to choose the events
    std::mt19937 gen2(random_generator2());
    std::uniform_int_distribution<>distribution2(1,2);
    int hitPossibility = distribution2(gen2);
    std::ostringstream hitMessage;
    switch (hitPossibility){
        case 1:
            hitMessage << "You took "<< playerShip.damageModifier((playerShip.getType()))*10 << " damage";
            General::printWithTypingEffect(hitMessage.str());
            playerShip.takeDamage(10);
            break;
        case 2:
            General::printWithTypingEffect("You got out of the asteroid belt without taking damage");
            break;
    }
}

void GameEngine::handleAbandonedPlanet() {
  std::cout << "Exploring an Abandoned Planet..." << std::endl;
    std::random_device random_generator; //random generator to choose the events
    std::mt19937 gen(random_generator());
    std::uniform_int_distribution<>distribution(1,2);
    int abandonedPlanet = distribution(gen);
  if (abandonedPlanet == 1) {
    std::cout << "Found 10 gold!" << std::endl;
    playerShip.earnMoney(10);
  } else {
    std::cout << "Encountered Space Pirates!" << std::endl;
    handleSpacePirates(); // Directly call Space Pirates event
  }
}

void GameEngine::handleSpacePirates() {
    bool escapeAttempt = false;
    bool negotiationAttempt = false;
    std::string message = "Facing Space Pirates. Choose your action: Escape(E), Fight(F) or Negotiate(N)";
    std::string action;
    while (true){
        General::printWithTypingEffect(message);
        action = General::getUserInput(0);
        if(action == "E" && !escapeAttempt){
            if(playerShip.getFuel() < 33){
                General::printWithTypingEffect("NOT ENOUGH FUEL");
                escapeAttempt = true;
                continue;
            }
            playerShip.refuel(-(playerShip.fuelModifier(playerShip.getType())));
            float escapeChance = Ship::escapeProbability(playerShip.getType()) * 50;
            std::random_device random_generator; //random generator to choose the events
            std::mt19937 gen(random_generator());
            std::uniform_int_distribution<>distribution(1,100);
            int escape = distribution(gen);
            if(escape < escapeChance){
                General::printWithTypingEffect("Successfully escaped the space pirates!");
                break;
            }
            else {
                General::printWithTypingEffect("Failed to escape. You cannot escape again.");
                escapeAttempt = true;
                continue;
            }
        }
        else if (action == "F"){
            std::random_device random_generator; //random generator to choose the events
            std::mt19937 gen(random_generator());
            std::uniform_int_distribution<>distribution(1,2);
            int fightwin = distribution(gen);
            switch (fightwin){
                case 1:
                    General::printWithTypingEffect("LOST THE FIGHT");
                    playerShip.takeDamage(30);

                    break;
                case 2:
                    General::printWithTypingEffect("WON THE FIGHT");
                    break;
            }
            break;
        }
        else if(action == "N" && !negotiationAttempt){
            std::random_device random_generator; //random generator to choose the events
            std::mt19937 gen(random_generator());
            std::uniform_int_distribution<>distribution(1,3);
            int payment = distribution(gen)*10;
            if(playerShip.getMoney() < payment){
                General::printWithTypingEffect("NOT ENOUGH GOLD");
                negotiationAttempt = true;
                continue;
            }
                playerShip.earnMoney(-payment);
                std::ostringstream demandMessage;
                demandMessage << "Negotiated with pirates for " << payment << " Galactic Credits";
                General::printWithTypingEffect(demandMessage.str());
                break;
        }
        else if((action == "E" && escapeAttempt) || (action == "N" && negotiationAttempt)) {
            General::printWithTypingEffect("You cannot choose this action again.");
        }
        else{
            General::printWithTypingEffect("Invalid action. Please Choose Again");
        }
    }
}

void GameEngine::calculateFinalScore() const {
  int score = (playerShip.getFuel() * 5) + (playerShip.getHealth() * 10) +
              (playerShip.getMoney() * 10);
  std::cout << "Game Over. Your final score is: " << score << std::endl;
}

