#ifndef EVENT_H
#define EVENT_H

#include "ship.h"

#include <memory>


enum class Event{ AsteroidBelt, AbandonedPlanet, SpacePirates };

class EventFunctions{
public:
    static void pirateAttackEvent(std::shared_ptr<Ship> &playerShip_);
    static void abandonedPlanetEvent(std::shared_ptr<Ship>& playerShip_);
    static void asteroidBeltEvent(std::shared_ptr<Ship>const&  ship);
};

#endif // EVENT_H
