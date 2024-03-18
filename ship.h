#ifndef SHIP_H
#define SHIP_H

#include <memory>

enum class ShipType { Normal, Fast, Strong, Voyager, KÆLIStar, Sterilus, AURUM };

class Ship {
public:
  Ship(int fuel = 100 , int health = 100 , int money = 0);
  virtual ~Ship() {}

  int getFuel() const;
  int getHealth() const;
  int getMoney() const;

  void setFuel(int fuel);
  void setHealth(int health);
  void setMoney(int money);
  void endFuel();
  void endHealth();

  virtual double evasionMultiplier() const = 0;
  virtual double damageMultiplier() const = 0;
  virtual int getFuelCost() const = 0;

protected:
  int fuel_;
  int health_;
  int money_;
};

class NormalShip : public Ship {
public:
  explicit NormalShip(int fuel = 100, int health = 100, int money = 0);
  double evasionMultiplier() const override;
  double damageMultiplier() const override;
  int getFuelCost() const override;
};

class FastShip : public Ship {
public:
  explicit FastShip(int fuel = 100, int health = 100, int money = 0);
  double evasionMultiplier() const override;
  double damageMultiplier() const override;
  int getFuelCost() const override;
};

class StrongShip : public Ship {
public:
  explicit StrongShip(int fuel = 100, int health = 100, int money = 0);
  double evasionMultiplier() const override;
  double damageMultiplier() const override;
  int getFuelCost() const override;
};

class Voyager : public Ship {
public:
    explicit Voyager(int fuel = 100, int health = 100, int money = 20);
    double evasionMultiplier() const override;
    double damageMultiplier() const override;
    int getFuelCost() const override;
};

class KÆLIStar : public Ship {
public:
    explicit KÆLIStar(int fuel = 100, int health = 165, int money = 100);
    double evasionMultiplier() const override;
    double damageMultiplier() const override;
    int getFuelCost() const override;
};

class STERILUS : public Ship {
public:
    explicit STERILUS(int fuel = 85, int health = 34, int money = 0);
    double evasionMultiplier() const override;
    double damageMultiplier() const override;
    int getFuelCost() const override;
};

class AURUM : public Ship {
public:
    explicit AURUM(int fuel = 150, int health = 100, int money = 0);
    double evasionMultiplier() const override;
    double damageMultiplier() const override;
    int getFuelCost() const override;
};


#endif // SHIP_H
