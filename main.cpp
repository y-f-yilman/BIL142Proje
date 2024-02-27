#include "GameEngine.h"
#include "Ship.h"
#include <iostream>
#include <limits> // Include for std::numeric_limits
#include <string>

void displayWelcomeMessage() {
    std::cout << "Welcome to the Space Adventure Game!" << std::endl;
    std::cout << "You are the captain of a spaceship embarking on a perilous journey." << std::endl;
}

void displayShipSelection() {
    std::cout << "Please select your ship type:" << std::endl;
    std::cout << "1. Fast Ship - Higher escape probability, takes more damage." << std::endl;
    std::cout << "2. Strong Ship - Lower escape probability, takes less damage." << std::endl;
    std::cout << "3. Normal Ship - Balanced characteristics." << std::endl;
}

Ship::Type getUserShipSelection() {
    int selection = 0;
    while (selection < 1 || selection > 3) {
        std::cout << "Enter your choice (1-3): ";
        std::cin >> selection;
        if (std::cin.fail() || selection < 1 || selection > 3) {
            std::cout << "Invalid choice. Please select a valid ship type." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return static_cast<Ship::Type>(selection - 1);
}

int main() {
    displayWelcomeMessage();
    displayShipSelection();

    Ship::Type selectedShipType = getUserShipSelection();
    GameEngine gameEngine(selectedShipType);

    gameEngine.startGame();

    return 0;
}

