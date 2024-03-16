//
// Created by o_ark on 16.03.2024.
//
#include "ShipProperty.h"

void fastShip::takeDamage(int damage) {health -= damage*damageModifier;}
void fastShip::fuelLoss(int fuelCost){fuel -= fuelCost;}
void fastShip::moneyWork(int moneywork) {money += moneywork;}

void normalShip::takeDamage(int damage) {health -= damage*damageModifier;}
void normalShip::fuelLoss(int fuelCost){fuel -= fuelCost;}
void normalShip::moneyWork(int moneywork) {money += moneywork;}
S
void strongShip::takeDamage(int damage) {health -= damage*damageModifier;}
void strongShip::fuelLoss(int fuelCost){fuel -= fuelCost;}
void strongShip::moneyWork(int moneywork) {money += moneywork;}
