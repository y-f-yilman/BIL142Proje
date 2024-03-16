//
// Created by o_ark on 16.03.2024.
//

#include "SpaceVoyage.h"

spaceVoyage::spaceVoyage(const shipType &type)  {
    switch (type) {
        case shipType::Fast:
            ship = std::make_unique<fastShip>();
            break;
        case shipType::Strong:
            ship = std::make_unique<strongShip>();
            break;
        case shipType::Normal:
            ship = std::make_unique<normalShip>();
            break;
    }
    health = ship->getHealth();
    money = ship->getMoney();
    fuel = ship->getFuel();
}

