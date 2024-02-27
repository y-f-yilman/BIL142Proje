#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Ship.h"
#include <vector>
#include <functional>

class GameEngine {
public:
    enum class Event { AsteroidBelt, AbandonedPlanet, SpacePirates };

private:
    Ship playerShip;
    int eventCount;
    std::vector<std::function<void()>> eventHandlers;

    void handleAsteroidBelt();
    void handleAbandonedPlanet();
    void handleSpacePirates();
    void calculateFinalScore() const;

public:
    GameEngine(Ship::Type shipType);
    void startGame();
    void executeEvent(Event event);
    void displayStatus() const; // New method to display status
};

#endif // GAMEENGINE_H

