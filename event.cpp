//
// Created by o_ark on 18.03.2024.
//
#include "event.h"
#include "GeneralFunc.h"

#include <iostream>
#include <random>
#include <sstream>


void EventFunctions::pirateAttackEvent(std::shared_ptr<Ship>& ship){
    std::random_device random_generator; //random generator to choose the events
    std::mt19937 gen(random_generator());
    bool escapeAttempt = false;
    bool negotiationAttempt = false;
    std::ostringstream pirateAttackMessage;

    pirateAttackMessage << "Space Pirates are approaching, You must choose an action"<< std::endl
            << "1. Escape" << std::endl
            << "2. Fight" << std::endl
            << "3. Negotiate" << std::endl;
    GeneralFunc::printWithTypingEffect(pirateAttackMessage.str());
    pirateAttackMessage.str("");
    pirateAttackMessage.clear();
    while(true){
        int choice = GeneralFunc::getUserInput();

        //ESCAPE
        if (choice == 1 && !escapeAttempt){

            //INSUFFICIENT FUEL
            if(ship->getFuel() < ship->getFuelCost()){
                pirateAttackMessage << "The Zitoka fuel left in your ship was not enough to escape" << std::endl;
                GeneralFunc::printWithTypingEffect(pirateAttackMessage.str());
                ship->endFuel();
                pirateAttackMessage.str("");
                pirateAttackMessage.clear();
                escapeAttempt = true;
                continue;
            }

            else {
                //ENOUGH FUEL
                ship->setFuel(-ship->getFuelCost());
                float escapeChance = ship->evasionMultiplier() * 50;
                std::uniform_int_distribution<> distribution(1, 100);
                int escape = distribution(gen);
                //SUCCESSFULLY ESCAPED
                if (escape < escapeChance) {
                    pirateAttackMessage << "You have successfully escaped the pirates" << std::endl;
                    GeneralFunc::printWithTypingEffect(pirateAttackMessage.str());
                    pirateAttackMessage.str("");
                    pirateAttackMessage.clear();
                    break;
                }

                    //ESCAPE FAILED
                else {
                    pirateAttackMessage << "You have failed to escape the pirates, Choose another action" << std::endl;
                    GeneralFunc::printWithTypingEffect(pirateAttackMessage.str());
                    pirateAttackMessage.str("");
                    pirateAttackMessage.clear();
                    escapeAttempt = true;
                    continue;
                }
            }
        }

        //FIGHT
        else if (choice == 2){
            std::uniform_int_distribution<>distribution(1,2);
            int fightwin = distribution(gen);
            switch(fightwin){
                case 1:
                    pirateAttackMessage << "You have successfully defeated the pirates" << std::endl;
                    break;
                case 2:
                    pirateAttackMessage << "You have lost the fight." << std::endl;
                    ship->setHealth(-30 * ship->damageMultiplier());
                    if (ship->getHealth() < 0){
                        ship->endHealth();
                        pirateAttackMessage << "Your ship has been obliterated" << std::endl;
                    }
                    break;
            }
            GeneralFunc::printWithTypingEffect(pirateAttackMessage.str());
            pirateAttackMessage.str("");
            pirateAttackMessage.clear();
            break;
        }

        //NEGOTIATE
        else if(choice == 3 && !negotiationAttempt){
            std::uniform_int_distribution<>distribution(1,3);
            int payment = distribution(gen)*10;
            pirateAttackMessage << "Pirates require "<< payment << " Galactic Credits" << std::endl;
            //NOT ENOUGH MONEY
            if (ship->getMoney() < payment){
               pirateAttackMessage <<"You do not have enough Galactic Credits, choose another action\n";
                GeneralFunc::printWithTypingEffect(pirateAttackMessage.str());
                pirateAttackMessage.str("");
                pirateAttackMessage.clear();
                negotiationAttempt = true;
                continue;
            }
            ship->setMoney(-payment);
            pirateAttackMessage << "Negotiated with pirates for " << payment << " Galactic Credits\n";
            GeneralFunc::printWithTypingEffect(pirateAttackMessage.str());
            pirateAttackMessage.str("");
            pirateAttackMessage.clear();
            break;
        }

        //YOU ALREADY TRIED TO ESCAPE OR NEGOTIATE
        else if((choice == 1 && escapeAttempt) || (choice == 3 && negotiationAttempt)){
           GeneralFunc::printWithTypingEffect("You cannot choose this action again.\n");
        }

        //WRONG INPUT
        else{
             GeneralFunc::printWithTypingEffect("Invalid action. Please Choose Again\n");
        }
    }
}

//ABANDONED PLANET EVENT
void EventFunctions::abandonedPlanetEvent(std::shared_ptr<Ship>& ship){
    std::ostringstream abandonedPlanetMessage;
    abandonedPlanetMessage << "You arrive at a planet not shown on the The Great Kaeli Galactic Map" << std::endl;
    std::random_device random_generator; //random generator to choose the events
    std::mt19937 gen(random_generator());
    std::uniform_int_distribution<> distribution(1, 2);
    int abandonedPlanetOutcome = distribution(gen);
    switch (abandonedPlanetOutcome) {
        case 1:
            abandonedPlanetMessage << "You uncover a cosmic Potato[10 Galactic Credits]" << std::endl;
            ship->setMoney(10);
            break;
        case 2:
            abandonedPlanetMessage<< "Your scanner picks up a life signal on an abandoned planet" << std::endl
                    << "The life signal disappears from your scanner as you enter the atmosphere" << std::endl
                    << "It's A TRAP!, Space pirates surrounded your ship" << std::endl;
            EventFunctions::pirateAttackEvent(ship);
            break;
    }
    GeneralFunc::printWithTypingEffect(abandonedPlanetMessage.str());
}

//ASTEROID BELT EVENT
void EventFunctions::asteroidBeltEvent(std::shared_ptr<Ship>const& ship){
    std::ostringstream asteroidBeltMessage;
    std::random_device random_generator; //random generator to choose the events
    std::mt19937 gen(random_generator());

    std::uniform_int_distribution<>distribution(1,4);
    int asteroid_event = distribution(gen);
    switch (asteroid_event){
        case 1:
            asteroidBeltMessage << "Your path is blocked by a cosmic anomaly " << std::endl
                    <<"You have no other choice but to go through the asteroid belt" << std::endl;
            break;
        case 2:
            asteroidBeltMessage << "You have received a distress signal from an asteroid belt, once you arrived, you find the wreckage of a ship" << std::endl
                    << "The ship turns into a ball of fire and explodes" << std::endl
                    << "You have no other choice but to go through the asteroid belt" << std::endl;
            break;
        case 3:
            asteroidBeltMessage << "You came across a VOYAGER claiming that he found a COSMIC POTATO cache in an asteroid belt" << std::endl
                    << "Once you arrive at the cache you find the place emptied" << std::endl
                    << "You see pirate ships coming your way" << std::endl
                    << "You have no other choice but to go through the asteroid belt in order to escape them" << std::endl;
            break;
        case 4:
            asteroidBeltMessage<< "A Kaeli Star Beast starts to chase your ship" << std::endl
                    << "You have no other choice but to go through the asteroid belt in order to escape" << std::endl;
            break;
    }

    std::uniform_int_distribution<> distribution2(1, 2);
    int asteroidBeltOutcome = distribution2(gen);
    switch (asteroidBeltOutcome) {
        case 1:
            asteroidBeltMessage << "You ship took damage from the asteroids" << std::endl;
            ship->setHealth(-10);
            if (ship->getHealth() < 0){
                ship->endHealth();
            break;
        case 2:
            asteroidBeltMessage << "You have got out of the asteroid belt without taking damage" << std::endl;
            break;
    }

    }
    GeneralFunc::printWithTypingEffect(asteroidBeltMessage.str());
}