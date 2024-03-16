//
// Created by o_ark on 16.03.2024.
//

#ifndef SPACE_VOYAGERS_DIVAN_EDITION_GOTY_SHIPPROPERTY_H
#define SPACE_VOYAGERS_DIVAN_EDITION_GOTY_SHIPPROPERTY_H

#include <iostream>
#include <random>
#include <memory>
#include "Ship.h"

//Fast Ship Properties
class fastShip : public ship {

private:
    int fuel{100};
    float health{100};
    int money{0};
    int fuelCost{33};
    float damageModifier{1.5};
    float escapeModifier{1.5};

public:
    void takeDamage(int damage) override;
    void fuelLoss(int fuelCost) override;
    void moneyWork(int amount) override;
};

//Strong Ship Properties
class strongShip : public ship{

private:
    int fuel{100};
    float health{100};
    int money{0};
    int fuelCost{33};
    float damageModifier{0.5};
    float escapeModifier{0.5};

public:
    void takeDamage(int damage) override;
    void fuelLoss(int fuelCost) override;
    void moneyWork(int amount) override;
};

//Normal Ship Properties
class normalShip : public ship{
private:
    int fuel{100};
    float health{100};
    int money{0};
    int fuelCost{33};
    float damageModifier{1};
    float escapeModifier{1};

public:
    void takeDamage(int damage) override;
    void fuelLoss(int fuelCost) override;
    void moneyWork(int amount) override;

};


#endif //SPACE_VOYAGERS_DIVAN_EDITION_GOTY_SHIPPROPERTY_H
