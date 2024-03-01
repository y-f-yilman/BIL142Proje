#include "Ship.h"

Ship::Ship(Type type) : type(type), fuel(100), health(100), money(0) {}

void Ship::takeDamage(int amount) {
  health -= static_cast<int>(amount * damageModifier(type));
}

void Ship::refuel(int amount) { fuel += amount; }

void Ship::earnMoney(int amount) { money += amount; }

Ship::Type Ship::getType() const { return type; }

int Ship::getFuel() const { return fuel; }

int Ship::getHealth() const { return health; }

int Ship::getMoney() const { return money; }

float Ship::escapeProbability(Type type) {
  switch (type) {
  case Type::Fast:
    return 1.5f;
  case Type::Strong:
    return 0.5f;
      case Type::Voyager:
          return 1.5f;
  default:
    return 1.0f;
  }
}

float Ship::damageModifier(Type type) {
  switch (type) {
  case Type::Fast:
    return 1.5f;
  case Type::Strong:
    return 0.5f;
      case Type::Voyager:
          return 0.5f;
  default:
    return 1.0f;
  }
}

int Ship::fuelModifier(Type type){
    switch(type){
        case Type::Voyager:
            return 20;
        default:
            return 33;
    }
}
