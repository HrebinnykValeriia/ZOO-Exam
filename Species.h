#ifndef SPECIES_H
#define SPECIES_H
#include "Animal.h"
using namespace std;

class Tiger : public Animal {
public:
    Tiger(string name, string origin, int age, double weight, double foodDay);
    string getType() const override;
};
class Crocodile : public Animal {
private:
    double length;
public:
    Crocodile(string name, string origin, int age, double weight, double foodDay, double length);
    string getType() const override;
    double getLength() const;
};
class Kangaroo : public Animal {
public:
    Kangaroo(string name, string origin, int age, double weight, double foodDay);
    string getType() const override;
};
class Koala : public Animal {
public:
    Koala(string name, string origin, int age, double weight, double foodDay);
    string getType() const override;
};
class Capybara : public Animal {
public:
    Capybara(string name, string origin, int age, double weight, double foodDay);
    string getType() const override;
};
class Lion : public Animal {
public:
    Lion(string name, string origin, int age, double weight, double foodDay);
    string getType() const override;
};
class Elephant : public Animal {
public:
    Elephant(string name, string origin, int age, double weight, double foodDay);

    string getType() const override;
};
class Penguin : public Animal {
public:
    Penguin(string name, string origin, int age, double weight, double foodDay);
    string getType() const override;
};
class Snake : public Animal {
public:
    Snake(string name, string origin, int age, double weight, double foodDay);
    string getType() const override;
};
#endif