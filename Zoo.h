#ifndef ZOO_H
#define ZOO_H
#include "Animal.h"
#include "Area.h"
#include "Visitors.h"
#include "File.h"
#include <vector>
#include <set>
#include <map>
using namespace std;

class Zoo {
private:
    vector<Animal*> animals;
    vector<Area*> enclosures;
    VisitorStatistics visitorStatistics;
public:
    Zoo();
    ~Zoo();
    void newZoo();
    bool addAnimal(Animal* animal);
    void deleteAnimal(Animal* animal);
    void addEnclosure(Area* enclosure);
    void deleteEnclosure(Area* enclosure);
    void showAnimals();
    void showEnclosures();
    Animal* findAnimal(string name);
    bool addAnimalMenu();
    bool deleteAnimalMenu();
    set<string> getOrigins();
    map<string, int> getAnimalStatistics();
    void saveToFile();
    void loadFromFile();
    void showVisitorStatistics();
    bool addEnclosureMenu();
    bool deleteEnclosureMenu();
};
#endif