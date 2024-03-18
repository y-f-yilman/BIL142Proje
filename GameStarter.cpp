//
// Created by o_ark on 18.03.2024.
//

#include "GameStarter.h"
#include <fstream>



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

void displayWelcomeMessage(){
    std::ostringstream welcomeMessage;
    welcomeMessage << "WELCOME TO THE SPACE VOYAGER!" << std::endl
    << "Thank you for purchasing the Divan Edition*"<< std::endl
    << "You unlocked THE VOYAGER[Divan Edition Exclusive] which has a higher chance in overcoming every obstacle in your way." << std::endl
    << "You will start the game with 20 Galactic Credits If you choose the Voyager [Divan Edition Exclusive]" << std::endl
    << "The Space Voyagers are an elite squadron of Space navigators who dedicated their lives to the betterment of the Great KAELI(The Known Galaxy)"<< std::endl
    << "Voyagers go through an extensive training in order to acquire the skills required to protect The Great KAELI"<< std::endl
    << "You are a young voyager candidate who is about to finish their training and become a real protector of The Great KAELI" << std::endl
    << "Your task is to survive 5 days or however long your Zitoka Fuel lasts" << std::endl
    << "Zitoka Fuel is a substance that allows voyagers to travel immense distances in seconds" << std::endl
    << "Voyagers use this as a last resort when they encounter Space Pirates" << std::endl
    << "In order to venture The Great KAELI you need a ship" << std::endl;
    GeneralFunc::printWithTypingEffect(welcomeMessage.str());
}

void displayShipSelection() {
    std::ostringstream shipSelectionStream;
    shipSelectionStream << "You enter the ship harbor of The Voyager's Guild, there are hundreds of ships laying in front of you" << std::endl
    << "Many of your classmates are allowed to choose from 3 ships however as you are the uppermost student of your class you are allowed to choose from 7 ships." << std::endl
    << "1. THE TORQUE GOD  - Higher escape probability, takes more damage."<< std::endl
    << "2. THE JOSEPHUS WALL - Lower escape probability, takes less damage."<< std::endl
    << "3. THE JENERIQUE - Balanced characteristics."<< std::endl
    << "4. THE VOYAGER [Divan Edition Exclusive] - Higher escape probability, takes less damage, uses less fuel"<< std::endl
    << "5. THE KAELI STAR - Higher Health, Lower Escape Probability, takes more damage, player gains 100 Galactic Credits" << std::endl
    << "6. THE STERILUS - Lower+++ Health, Lower+ Escape Probability, takes more damage, Uses More Fuel" << std::endl
    << "7. THE AURUM - Higher+ Escape Probability, Bigger Fuel Tank, takes less damage " << std::endl;
    GeneralFunc::printWithTypingEffect(shipSelectionStream.str());
}

void StartMessage(){
    printASCIIArt();
    displayWelcomeMessage();
    displayShipSelection();
}