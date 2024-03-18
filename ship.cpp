#include "ship.h"


Ship::Ship(int fuel, int health, int money)
    : fuel_(fuel), health_(health), money_(money) {}

int Ship::getFuel() const { return fuel_; }
int Ship::getHealth() const { return health_; }
int Ship::getMoney() const { return money_; }
void Ship::setFuel(int fuel) { fuel_ += fuel; }
void Ship::endFuel() {fuel_ = 0;}
void Ship::endHealth() {health_ = 0;}
void Ship::setHealth(int health) { health_ += health; }
void Ship::setMoney(int money) { money_ += money; }

//Normal Ship
NormalShip::NormalShip(int fuel, int health, int money): Ship(fuel, health, money) {}
double NormalShip::evasionMultiplier() const {return 1.0;}
double NormalShip::damageMultiplier() const {return 1.0;}
int NormalShip::getFuelCost() const {return 33;}


//Fast Ship
FastShip::FastShip(int fuel, int health, int money): Ship(fuel, health, money) {}
double FastShip::evasionMultiplier() const { return 1.5;}
double FastShip::damageMultiplier() const { return 1.5;}
int FastShip::getFuelCost() const { return 33;}


//Strong Ship
StrongShip::StrongShip(int fuel, int health, int money): Ship(fuel, health, money) {}
double StrongShip::evasionMultiplier() const { return 0.5;}
double StrongShip::damageMultiplier() const { return 0.5;}
int StrongShip::getFuelCost() const { return 33;}


//Voyager
Voyager::Voyager(int fuel, int health, int money): Ship(fuel, health, money) {}
double Voyager::evasionMultiplier() const { return 1.5;}
double Voyager::damageMultiplier() const { return 0.5;}
int Voyager::getFuelCost() const { return 20; }


//KÆELI Star
KÆLIStar::KÆLIStar(int fuel, int health, int money): Ship(fuel, health, money) {}
double KÆLIStar::evasionMultiplier() const { return 0.5;}
double KÆLIStar::damageMultiplier() const { return 1.5;}
int KÆLIStar::getFuelCost() const { return 33; }


// Sterilus
STERILUS::STERILUS(int fuel, int health, int money): Ship(fuel, health, money) {}
double STERILUS::evasionMultiplier() const { return 0.25;}
double STERILUS::damageMultiplier() const { return 1.5;}
int STERILUS::getFuelCost() const { return 40; }


//Aurum
AURUM::AURUM(int fuel, int health, int money): Ship(fuel, health, money) {}
double AURUM::evasionMultiplier() const { return 1.7;}
double AURUM::damageMultiplier() const { return 0.7;}
int AURUM::getFuelCost() const { return 33;}