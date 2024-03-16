//
// Created by o_ark on 16.03.2024.
//

#ifndef SPACE_VOYAGERS_DIVAN_EDITION_GOTY_SPACEVOYAGE_H
#define SPACE_VOYAGERS_DIVAN_EDITION_GOTY_SPACEVOYAGE_H


#include "Ship.h"
#include "ShipProperty.h",

class spaceVoyage {
private:
    std::unique_ptr<ship> ship;
    int fuel = 100;
    int health = 100;
    int money = 0;

public:
    spaceVoyage(const shipType &type);

};

#endif //SPACE_VOYAGERS_DIVAN_EDITION_GOTY_SPACEVOYAGE_H
