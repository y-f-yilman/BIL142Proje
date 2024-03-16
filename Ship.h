//
// Created by o_ark on 16.03.2024.
//

#ifndef SPACE_VOYAGERS_DIVAN_EDITION_GOTY_SHIP_H
#define SPACE_VOYAGERS_DIVAN_EDITION_GOTY_SHIP_H

#include <iostream>
#include <random>
#include <memory>

enum class shipType {Fast, Strong, Normal};

class ship{
private:
    int fuel;
    float health;
    int money;
    int fuelCost;
    float damageModifier;
    float escapeModifier;

public:
    int getFuelcost() const {return fuelCost;}
    int getHealth() const {return health;}
    int getMoney() const { return money;}
    int getFuel() const {return fuel;}
    float getDamageModifier() const {return damageModifier;}
    float getEscapeModifier() const {return escapeModifier;}
    virtual ~ship() = default;
    virtual void takeDamage(int damage) = 0;
    virtual void fuelLoss(int fuelCost) = 0;
    virtual void moneyWork(int moneywork) = 0;
};

#endif //SPACE_VOYAGERS_DIVAN_EDITION_GOTY_SHIP_H
