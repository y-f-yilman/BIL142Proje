#ifndef GAME_H
#define GAME_H

#include "event.h"
#include "ship.h"

#include <memory>
#include <vector>

class Game {
public:
    void play(std::shared_ptr<Ship> Ship_);
    std::shared_ptr<Ship> initializePlayerShip();
    static void eventHandler(const Event &event,std::shared_ptr<Ship> &ship);
    static void displayScore(std::shared_ptr<Ship>const& playerShip_);

private:
    std::shared_ptr<Ship> playerShip_;
    static Event randomEventGenerator();
};


#endif // GAME_H
