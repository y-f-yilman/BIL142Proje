#include <iostream>
#include "GamePlayr.h"


int main() {
    int shipChoice;
    std::cout << "Choose your ship:\n";
    std::cout << "1. Fast Ship (Agile, Lower Health)\n";
    std::cout << "2. Strong Ship (Durable, Lower Fuel Efficiency)\n";
    std::cout << "3. Normal Ship (Balanced)\n";
    std::cin >> shipChoice;

    spaceVoyage game(static_cast<shipType>(shipChoice-1));
    GamePlayr gameplayer;

    gameplayer.play(std::make_unique<<shipType>());

    return 0;

}
