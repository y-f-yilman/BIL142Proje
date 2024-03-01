#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Ship.h"
#include <functional>
#include <unordered_set> // Include unordered_set for storing failed actions
#include <vector>

class GameEngine {
public:
  enum class Event { AsteroidBelt, AbandonedPlanet, SpacePirates };

private:
  Ship playerShip;
  int eventCount;
  std::vector<std::function<void()>> eventHandlers;
  std::unordered_set<char> failedActions; // Set to store failed actions

  void handleAsteroidBelt();
  void handleAbandonedPlanet();
  void handleSpacePirates();
  void calculateFinalScore() const;

public:
  GameEngine(Ship::Type shipType);
  void startGame();
  void executeEvent(Event event);
  void displayStatus() const;
};

#endif // GAMEENGINE_H
