#include "game.h"
#include <iostream>
#include "GeneralFunc.h"
#include "event.h"
#include "GameStarter.h"
// #include <random>

int main() {
  char answer = 'Y';
  while (answer == 'Y'){
      StartMessage();
      Game game;
      std::shared_ptr<Ship> PlayerShip= game.initializePlayerShip();
      game.play(PlayerShip);
      std::cout << "Continue?(Y/N):";
      GeneralFunc::getUserInput(answer);
  }
    return 0;
}
