#include "Area.h"
Area::Area(string name, string animalType, int maxAnimals) {
    this->name = name;
    this->animalType = animalType;
    this->maxAnimals = maxAnimals;
}
Area::~Area() {
}
bool Area::addAnimal(Animal* animal) {
    if (animal->getType() != animalType) {
        throw "This animal cannot be added to this enclosure";
    }
    if (animals.size() >= maxAnimals) {
        throw "This enclosure is full!";
    }
    animals.push_back(animal);
    cout << animal->getName() << " was added to " << name << endl;
    return true;
}
void Area::deleteAnimal(Animal* animal) {
    for (int i = 0; i < animals.size(); i++) {
        if (animals[i] == animal) {
            animals.erase(animals.begin() + i);
            cout << animal->getName() << " was removed from " << name << endl;
            return;
        }
    }
    throw "Animal isn't in this enclosure";
}
bool Area::hasFreeSpace() {
    return animals.size() < maxAnimals;
}
int Area::getCount() {
    return animals.size();
}
string Area::getName() {
    return name;
}
string Area::getAnimalType() {
    return animalType;
}
int Area::getMaxAnimals() {
    return maxAnimals;
}
vector<Animal*> Area::getAnimals() {
    return animals;
}
ostream& operator<<(ostream& s, const Area& enclosure) {
    s << endl;
    s << "Name: " << enclosure.name << endl;
    s << "Type: " << enclosure.getType() << endl;
    s << "Animal type: " << enclosure.animalType << endl;
    s << "Animals: " << enclosure.animals.size() << "/" << enclosure.maxAnimals << endl;
    enclosure.printInfo(s);
    for (Animal* animal : enclosure.animals) {
        s << "- " << animal->getName() << endl;
    }
    return s;
}
ofstream& operator<<(ofstream& s, const Area& enclosure) {
    s << enclosure.name << endl;
    s << enclosure.animalType << endl;
    s << enclosure.maxAnimals << endl;
    return s;
}
LandEnclosure::LandEnclosure(string name, string animalType, int maxAnimals, double area)
    : Area(name, animalType, maxAnimals) {
    this->area = area;
}
string LandEnclosure::getType() const {
    return "LandEnclosure";
}
double LandEnclosure::getArea() const {
    return area;
}
void LandEnclosure::printInfo(ostream& s) const {
    s << "Area: " << area << " m2" << endl;
}
Aquarium::Aquarium(string name, string animalType, int maxAnimals, double waterTemperature)
    : Area(name, animalType, maxAnimals) {
    this->waterTemperature = waterTemperature;
}
string Aquarium::getType() const {
    return "Aquarium";
}
double Aquarium::getWaterTemperature() const {
    return waterTemperature;
}
void Aquarium::printInfo(ostream& s) const {
    s << "Water temperature: " << waterTemperature << " C" << endl;
}
Terrarium::Terrarium(string name, string animalType, int maxAnimals, double temperature, double humidity)
    : Area(name, animalType, maxAnimals) {
    this->temperature = temperature;
    this->humidity = humidity;
}
string Terrarium::getType() const {
    return "Terrarium";
}
double Terrarium::getTemperature() const {
    return temperature;
}
double Terrarium::getHumidity() const {
    return humidity;
}
void Terrarium::printInfo(ostream& s) const {
    s << "Temperature: " << temperature << " C" << endl;
    s << "Humidity: " << humidity << "%" << endl;
}
