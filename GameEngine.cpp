#include "GameEngine.h"
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <chrono>  // For typing effect
#include <thread>  // For typing effect
#include <sstream> // Include for std::ostringstream

// Additional function to get user input
std::string getUserInput() {
    std::string input;
    // Clear any errors with the input stream
    std::cin.clear();
    // Ignore any input left in the input buffer up to the newline character
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Get the whole line of input
    std::getline(std::cin, input);
    return input;
}

void printWithTypingEffect(const std::string& message, unsigned int milliseconds_per_char = 50) {
    for (char ch : message) {
        std::cout << ch << std::flush; // Output each character and flush the stream
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds_per_char));
    }
    std::cout << std::endl; // End with a new line after the message is printed
}

void GameEngine::displayStatus() const {
    std::ostringstream statusStream;
    int score = (playerShip.getFuel() * 5) + (playerShip.getHealth() * 10) + (playerShip.getMoney() * 10);
    
    statusStream << "\nShip Status:" << std::endl;
    statusStream << "Fuel: " << playerShip.getFuel() << std::endl;
    statusStream << "Health: " << playerShip.getHealth() << std::endl;
    statusStream << "Money: " << playerShip.getMoney() << std::endl;
    statusStream << "Current Score: " << score << "\n" << std::endl;

    printWithTypingEffect(statusStream.str()); // Use the typing effect for the status display
}

GameEngine::GameEngine(Ship::Type shipType) : playerShip(shipType), eventCount(0) {
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
    auto eventIndex = static_cast<std::vector<std::function<void()>>::size_type>(event);
    if (eventIndex < eventHandlers.size()) {
        eventHandlers[eventIndex]();
    }
}

void GameEngine::handleAsteroidBelt() {
    std::cout << "Navigating through the Asteroid Belt..." << std::endl;
    playerShip.takeDamage(10); // Simplified damage logic
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
    std::cout << "Facing Space Pirates. Choose your action: Escape (E), Fight (F), or Negotiate (N)." << std::endl;
    std::string action = getUserInput();
    if (action == "E") {
        // Handling escape based on ship type
        float escapeChance = Ship::escapeProbability(playerShip.getType());
        if (rand() % 100 < escapeChance * 50) { // Assuming 50% base chance for normal ship
            std::cout << "Successfully escaped the space pirates!" << std::endl;
            playerShip.refuel(-33); // Deduct fuel for the escape attempt
        } else {
            std::cout << "Failed to escape. Facing the space pirates again." << std::endl;
            handleSpacePirates(); // Recursive call to handle failure case
        }
    } else if (action == "F") {
        // Handling fight with a 50% base chance to win or lose
        if (rand() % 2 == 0) {
            std::cout << "Won the fight against the space pirates!" << std::endl;
        } else {
            std::cout << "Lost the fight, taking damage." << std::endl;
            playerShip.takeDamage(30); // Simplified logic for damage
        }
    } else if (action == "N") {
        // Handling negotiation
        int goldOptions[3] = {10, 20, 30};
        int demand = goldOptions[rand() % 3];
        std::cout << "Pirates demand " << demand << " gold for passage." << std::endl;
        playerShip.earnMoney(-demand); // Assuming the ship has enough gold; in a full game, you'd want to check this
    } else {
        std::cout << "Invalid action. Please choose again." << std::endl;
        handleSpacePirates(); // Ask for input again if invalid
    }
}
void GameEngine::calculateFinalScore() const {
    int score = (playerShip.getFuel() * 5) + (playerShip.getHealth() * 10) + (playerShip.getMoney() * 10);
    std::cout << "Game Over. Your final score is: " << score << std::endl;
}

