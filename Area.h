#ifndef AREA_H
#define AREA_H

#include "Animal.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Area {
protected:
    string name;
    string animalType;
    int maxAnimals;
    vector<Animal*> animals;
public:
    Area(string name, string animalType, int maxAnimals);
    virtual ~Area();
    virtual string getType() const = 0;
    virtual void printInfo(ostream& s) const = 0;
    bool addAnimal(Animal* animal);
    void deleteAnimal(Animal* animal);
    bool hasFreeSpace();
    int getCount();
    string getName();
    string getAnimalType();
    int getMaxAnimals();
    vector<Animal*> getAnimals();
    friend ostream& operator<<(ostream& s, const Area& enclosure);
    friend ofstream& operator<<(ofstream& s, const Area& enclosure);
};
class LandEnclosure : public Area {
private:
    double area;
public:
    LandEnclosure(string name, string animalType, int maxAnimals, double area);
    string getType() const override;
    double getArea() const;
    void printInfo(ostream& s) const override;
};
class Aquarium : public Area {
private:
    double waterTemperature;
public:
    Aquarium(string name, string animalType, int maxAnimals, double waterTemperature);
    string getType() const override;
    double getWaterTemperature() const;
    void printInfo(ostream& s) const override;
};
class Terrarium : public Area {
private:
    double temperature;
    double humidity;
public:
    Terrarium(string name, string animalType, int maxAnimals, double temperature, double humidity);
    string getType() const override;
    double getTemperature() const;
    double getHumidity() const;
    void printInfo(ostream& s) const override;
};
#endif