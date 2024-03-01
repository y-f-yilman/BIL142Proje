#include "GameEngine.h"
#include "General.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iostream>
#include <sstream> // Include for std::ostringstream

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
      statusStream.str(), 25); // Use the typing effect for the status display
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
  std::cout << "The journey begins..." << std::endl;
  displayStatus(); // Initial display of ship status at the start of the game

  while (playerShip.getFuel() > 0 && eventCount < 5) {
    int eventIndex = rand() % eventHandlers.size();
    executeEvent(static_cast<Event>(eventIndex));
    eventCount++;
    displayStatus(); // Display updated status after each event
  }
  calculateFinalScore(); // This will display the final score
}

void GameEngine::executeEvent(Event event) {
  auto eventIndex =
      static_cast<std::vector<std::function<void()>>::size_type>(event);
  if (eventIndex < eventHandlers.size()) {
    eventHandlers[eventIndex]();
  }
}

void GameEngine::handleAsteroidBelt() {
  std::cout << "Navigating through the Asteroid Belt..." << std::endl;
  playerShip.takeDamage(10);
  std::cout << "Took 10 damage!" << std::endl;
}

void GameEngine::handleAbandonedPlanet() {
  std::cout << "Exploring an Abandoned Planet..." << std::endl;
  if (rand() % 2 == 0) {
    std::cout << "Found 10 gold!" << std::endl;
    playerShip.earnMoney(10);
  } else {
    std::cout << "Encountered Space Pirates!" << std::endl;
    handleSpacePirates(); // Directly call Space Pirates event
  }
}

void GameEngine::handleSpacePirates() {
  std::string message = "Facing Space Pirates. Choose your action: Escape (E), "
                        "Fight (F), or Negotiate (N).";
  std::string action;
  bool escapeAttempted = false;
  bool negotiationAttempted = false;

  while (true) {
    General::printWithTypingEffect(message);
    action = General::getUserInput();

    if (action == "E" && !escapeAttempted) {
      if (playerShip.getFuel() < 33) {
        General::printWithTypingEffect("Not enough fuel to escape!");
        escapeAttempted = true; // Mark escape as attempted
        continue;
      }
      float escapeChance = Ship::escapeProbability(playerShip.getType()) *
                           50; // Base escape chance
      if (rand() % 100 < escapeChance) {
        General::printWithTypingEffect(
            "Successfully escaped the space pirates!");
        playerShip.refuel(-33); // Deduct fuel for the escape attempt
        break;                  // Exit the encounter
      } else {
        General::printWithTypingEffect(
            "Failed to escape. You cannot attempt to escape again.");
        escapeAttempted = true; // Mark escape as attempted
      }
    } else if (action == "F") {
      // Fighting logic
      General::printWithTypingEffect(
          rand() % 2 == 0 ? "Won the fight against the space pirates!"
                          : "Lost the fight, taking damage.");
      playerShip.takeDamage(rand() % 2 == 0 ? 0 : 30);
      break; // Exit the encounter
    } else if (action == "N" && !negotiationAttempted) {
      int goldOptions[3] = {10, 20, 30};
      int demand = goldOptions[rand() % 3];
      if (playerShip.getMoney() < demand) {
        General::printWithTypingEffect("Not enough gold to negotiate!");
        negotiationAttempted = true; // Mark negotiation as attempted
        continue;
      }
      playerShip.earnMoney(-demand); // Pay the pirates
      std::ostringstream demandMessage;
      demandMessage << "Negotiated with the pirates for " << demand << " gold.";
      General::printWithTypingEffect(demandMessage.str());
      break; // Exit the encounter
    } else if ((action == "E" && escapeAttempted) ||
               (action == "N" && negotiationAttempted)) {
      General::printWithTypingEffect("You cannot choose this action again.");
    } else {
      General::printWithTypingEffect("Invalid action. Please choose again.");
    }
  }
}

void GameEngine::calculateFinalScore() const {
  int score = (playerShip.getFuel() * 5) + (playerShip.getHealth() * 10) +
              (playerShip.getMoney() * 10);
  std::cout << "Game Over. Your final score is: " << score << std::endl;
}
