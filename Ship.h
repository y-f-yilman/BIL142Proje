#ifndef SHIP_H
#define SHIP_H

#include <string>

class Ship {
public:
  enum class Type { Fast, Strong, Normal, Voyager };

private:
  Type type;
  int health;
  int fuel;
  int money;

public:

  Ship(Type type);
  void takeDamage(int amount);
  void refuel(int amount);
  void earnMoney(int amount);
  Type getType() const;
  int getFuel() const;
  int getHealth() const;
  int getMoney() const;
  static float escapeProbability(Type type);
  static float damageModifier(Type type);
  static int fuelModifier(Type type);
};

#endif // SHIP_H
