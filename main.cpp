#include "GameEngine.h"
#include "General.h"
#include "Ship.h"
#include <iostream>
#include <limits>  // Include for std::numeric_limits
#include <sstream> // Include for std::ostringstream
#include <chrono>
#include <thread>
#include <atomic>

void printASCIIArt(){
    std::cout << R"(
               ____ ___   ___   _____ ____  _   __ ____ __  __ ___   _____ ____ ___
    ____ ____ / __// _ \ / _ | / ___// __/ | | / // __ \\ \/ // _ | / ___// __// _ \ ____ ____
   /___//___/_\ \ / ___// __ |/ /__ / _/   | |/ // /_/ / \  // __ |/ (_ // _/ / , _//___//___/
            /___//_/   /_/ |_|\___//___/   |___/ \____/  /_//_/ |_|\___//___//_/|_|
                                                                                              )"<< std::endl;
    std::cout << R"(
 ______ _________        _______ _           _______ ______ ________________________________ _
(  __  \\__   __/\     /(  ___  | (    /|   (  ____ (  __  \\__   __|__   __|__   __(  ___  | (    /|
| (  \  )  ) (  | )   ( | (   ) |  \  ( |   | (    \/ (  \  )  ) (     ) (     ) (  | (   ) |  \  ( |
| |   ) |  | |  | |   | | (___) |   \ | |   | (__   | |   ) |  | |     | |     | |  | |   | |   \ | |
| |   | |  | |  ( (   ) )  ___  | (\ \) |   |  __)  | |   | |  | |     | |     | |  | |   | | (\ \) |
| |   ) |  | |   \ \_/ /| (   ) | | \   |   | (     | |   ) |  | |     | |     | |  | |   | | | \   |
| (__/  )__) (___ \   / | )   ( | )  \  |   | (____/\ (__/  )__) (___  | |  ___) (__| (___) | )  \  |
(______/\_______/  \_/  |/     \|/    )_)   (_______(______/\_______/  )_(  \_______(_______)/    )_))"<< std::endl;
    std::cout << std::endl;
}



void displayWelcomeMessage() {
  std::ostringstream welcomeMessage;
  welcomeMessage << "WELCOME TO THE SPACE VOYAGER!" << std::endl;
  welcomeMessage << "Thank you for purchasing the Divan Edition*"<< std::endl;
  welcomeMessage << "You will start the game with 20 Galactic Credits[Divan Edition Exclusive]" << std::endl;
  welcomeMessage << "You unlocked THE VOYAGER[Divan Edition Exclusive] which has a higher chance in overcoming every obstacle in your way." << std::endl;
  welcomeMessage
      << "You are a member of a guild called SPACE VOYAGERS who wishes to explore the endlessness of the space."
      << std::endl;
  welcomeMessage << "You have been chosen by the SPACE VOYAGER COUNCIL as a new voyager." << std::endl;
  welcomeMessage <<"You have five days to prove the guild that you are a worthy voyager." << std::endl;
  General::printWithTypingEffect(welcomeMessage.str());
}

void displayShipSelection() {
  std::ostringstream shipSelectionStream;
  shipSelectionStream << "To Start you first VOYAGE you need a ship, choose a ship:" << std::endl;
  shipSelectionStream
      << "1. TORQUE of GODS  - Higher escape probability, takes more damage."
      << std::endl;
  shipSelectionStream
      << "2. THE WALL of JOSEPHUS - Lower escape probability, takes less damage."
      << std::endl;
  shipSelectionStream << "3. THE JENERIQUE - Balanced characteristics."
                      << std::endl;
  shipSelectionStream << "4. THE VOYAGER [Divan Edition Exclusive] - Higher escape probability, takes less damage, uses more fuel"<< std::endl;
  General::printWithTypingEffect(shipSelectionStream.str());
}

Ship::Type getUserShipSelection() {
  int selection = 0;
  while (selection < 1 || selection > 4) {
    std::cout << "Time to make your choice (1-4): ";
    std::cin >> selection;
    if (std::cin.fail() || selection < 1 || selection > 4) {
      std::cout << "Invalid choice. Please select a valid ship type."
                << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
  return static_cast<Ship::Type>(selection - 1);
}

int main() {

    bool continuPlaying = true;
while (true){
    char answer;
        printASCIIArt();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        displayWelcomeMessage();
        displayShipSelection();
        Ship::Type selectedShipType = getUserShipSelection();
        GameEngine gameEngine(selectedShipType);
        gameEngine.startGame();
        std::cout << "Continue?(Y/N):";
        General::getUserInput(answer);
    switch(answer){
        case 'Y':
            continuPlaying = true;
            break;
        case 'N':
            continuPlaying = false;
            break;
    }
    }
  return 0;
}
