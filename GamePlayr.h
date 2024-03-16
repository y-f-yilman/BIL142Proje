//
// Created by o_ark on 16.03.2024.
//

#ifndef SPACE_VOYAGERS_DIVAN_EDITION_GOTY_GAMEPLAYR_H
#define SPACE_VOYAGERS_DIVAN_EDITION_GOTY_GAMEPLAYR_H

#include "SpaceVoyage.h"


enum class Event{ asteroidBelt, abandonedPlanet, spacePirates};

class GamePlayr {
public:
    void play(std::unique_ptr<ship> ship);


private:
    int shipProperties(std::unique_ptr<ship> ship);
    Event randomEventGenerator();
    void eventHandler(const Event &event);
    void asteroidBeltEvent(std::unique_ptr<ship> ship);
    void abandonedPlanetEvent(std::unique_ptr<ship> ship);
    void pirateAttackEvent(std::unique_ptr<ship> ship);
    void displayScore(std::unique_ptr<ship> ship);

};

#endif //SPACE_VOYAGERS_DIVAN_EDITION_GOTY_GAMEPLAYR_H
