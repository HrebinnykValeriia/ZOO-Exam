#include "Zoo.h"
#include "Species.h"
#include <fstream>

Zoo::Zoo() {
    loadFromFile();
}

Zoo::~Zoo() {
    for (Area *enclosure: enclosures) {
        delete enclosure;
    }
    for (Animal *animal: animals) {
        delete animal;
    }
}

void Zoo::newZoo() {
    addEnclosure(new LandEnclosure("Tiger Area", "Tiger", 5, 1000));
    addEnclosure(new Aquarium("Crocodile Aquarium", "Crocodile", 3, 24));
    addEnclosure(new LandEnclosure("Kangaroo Area", "Kangaroo", 6, 800));
    addEnclosure(new LandEnclosure("Koala Area", "Koala", 4, 300));
    addEnclosure(new LandEnclosure("Capybara Area", "Capybara", 5, 500));
    addEnclosure(new LandEnclosure("Lion Area", "Lion", 5, 1500));
    addEnclosure(new LandEnclosure("Elephant Area", "Elephant", 4, 3000));
    addEnclosure(new Aquarium("Penguin Aquarium", "Penguin", 10, 5));
    addEnclosure(new Terrarium("Snake Terrarium", "Snake", 8, 27, 60));

    addAnimal(new Tiger("Tigger", "Asia", 8, 273, 7));
    addAnimal(new Crocodile("Lolong", "Africa", 27, 776, 2, 6.17));
    addAnimal(new Kangaroo("Roo", "Australia", 4, 18, 1.5));
    addAnimal(new Koala("Clancy", "Australia", 12, 4, 1));
    addAnimal(new Capybara("Cinnamon", "South America", 7, 41, 2));
    addAnimal(new Capybara("JoeJoe", "South America", 8, 56, 3));
    addAnimal(new Lion("Simba", "Africa", 6, 190, 7));
    addAnimal(new Elephant("Dumbo", "Africa", 10, 3500, 30));
    addAnimal(new Penguin("Pingu", "Antarctica", 4, 25, 1));
    addAnimal(new Snake("Kaa", "Asia", 5, 15, 0.5));
}

bool Zoo::addAnimal(Animal *animal) {
    if (animal == nullptr) {
        return false;
    }
    for (Area *enclosure: enclosures) {
        if (enclosure->getAnimalType() == animal->getType()) {
            if (enclosure->hasFreeSpace()) {
                animals.push_back(animal);
                enclosure->addAnimal(animal);
                return true;
            }
        }
    }
    cout << "There is no free space" << endl;
    delete animal;
    return false;
}

void Zoo::addEnclosure(Area *enclosure) {
    if (enclosure == nullptr) {
        return;
    }
    enclosures.push_back(enclosure);
    for (Animal *animal: animals) {
        if (animal->getType() != enclosure->getAnimalType()) {
            continue;
        }
        bool alreadyInEnclosure = false;
        for (Area *other: enclosures) {
            if (other == enclosure) {
                continue;
            }
            vector<Animal *> otherAnimals = other->getAnimals();
            for (Animal *otherAnimal: otherAnimals) {
                if (otherAnimal == animal) {
                    alreadyInEnclosure = true;
                    break;
                }
            }
            if (alreadyInEnclosure) {
                break;
            }
        }
        if (!alreadyInEnclosure && enclosure->hasFreeSpace()) {
            enclosure->addAnimal(animal);
        }
    }
}

void Zoo::deleteEnclosure(Area *enclosure) {
    if (enclosure == nullptr) {
        return;
    }
    for (auto it = enclosures.begin();
         it != enclosures.end();
         ++it) {
        if (*it == enclosure) {
            enclosures.erase(it);
            delete enclosure;
            return;
        }
    }
}

void Zoo::showAnimals() {
    cout << endl;
    cout << "ANIMALS: " << endl;
    int i = 1;
    for (Animal *animal: animals) {
        cout << i << ": " << animal->getType() << " - Name: " << animal->getName() << endl;
        i++;
    }
}

void Zoo::showEnclosures() {
    cout << endl;
    cout << "ENCLOSURES: " << endl;
    for (Area *enclosure: enclosures) {
        cout << *enclosure << endl;
    }
}

Animal *Zoo::findAnimal(string name) {
    for (Animal *animal: animals) {
        if (animal->getName() == name) {
            return animal;
        }
    }
    return nullptr;
}

bool Zoo::addAnimalMenu() {
    int type;
    cout << "Choose animal type:" << endl;
    cout << "1. Tiger" << endl;
    cout << "2. Crocodile" << endl;
    cout << "3. Kangaroo" << endl;
    cout << "4. Koala" << endl;
    cout << "5. Capybara" << endl;
    cout << "6. Lion" << endl;
    cout << "7. Elephant" << endl;
    cout << "8. Penguin" << endl;
    cout << "9. Snake" << endl;
    cout << "Enter type: ";
    cin >> type;
    string animalType;
    switch (type) {
        case 1:
            animalType = "Tiger";
            break;
        case 2:
            animalType = "Crocodile";
            break;
        case 3:
            animalType = "Kangaroo";
            break;
        case 4:
            animalType = "Koala";
            break;
        case 5:
            animalType = "Capybara";
            break;
        case 6:
            animalType = "Lion";
            break;
        case 7:
            animalType = "Elephant";
            break;
        case 8:
            animalType = "Penguin";
            break;
        case 9:
            animalType = "Snake";
            break;
        default:
            cout << "Invalid animal type." << endl;
            return false;
    }
    bool hasFreeSpace = false;
    for (Area *enclosure: enclosures) {
        if (enclosure->getAnimalType() == animalType &&
            enclosure->hasFreeSpace()) {
            hasFreeSpace = true;
            break;
        }
    }
    if (!hasFreeSpace) {
        cout << "There is no free space" << endl;
        return false;
    }
    cout << "There is free space in the enclosure" << endl;

    string name;
    string origin;
    int age;
    double weight;
    double foodDay;
    cout << endl;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter origin: ";
    cin >> origin;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter weight: ";
    cin >> weight;
    cout << "Enter food per day: ";
    cin >> foodDay;
    cout << endl;

    Animal *animal = nullptr;
    switch (type) {
        case 1:
            animal = new Tiger(name, origin, age, weight, foodDay);
            break;
        case 2: {
            double length;
            cout << "Enter length: ";
            cin >> length;
            animal = new Crocodile(
                name, origin, age, weight, foodDay, length
            );
            break;
        }
        case 3:
            animal = new Kangaroo(name, origin, age, weight, foodDay);
            break;
        case 4:
            animal = new Koala(name, origin, age, weight, foodDay);
            break;
        case 5:
            animal = new Capybara(name, origin, age, weight, foodDay);
            break;
        case 6:
            animal = new Lion(name, origin, age, weight, foodDay);
            break;
        case 7:
            animal = new Elephant(name, origin, age, weight, foodDay);
            break;
        case 8:
            animal = new Penguin(name, origin, age, weight, foodDay);
            break;
        case 9:
            animal = new Snake(name, origin, age, weight, foodDay);
            break;
    }
    if (addAnimal(animal)) {
        cout << "Animal was successfully added!" << endl;
        return true;
    }
    return false;
}

set<string> Zoo::getOrigins() {
    set<string> origins;
    for (Animal *animal: animals) {
        origins.insert(animal->getOrigin());
    }
    return origins;
}

map<string, int> Zoo::getAnimalStatistics() {
    map<string, int> statistics;
    for (Animal *animal: animals) {
        statistics[animal->getType()]++;
    }
    return statistics;
}

void Zoo::saveToFile() {
    ofstream file(folderPath + "zoo.txt");
    if (!file.is_open()) {
        cerr << "Error - open file!" << endl;
        return;
    }
    file << animals.size() << endl;
    for (Animal *animal: animals) {
        file << animal->getType() << endl;
        file << animal->getName() << endl;
        file << animal->getOrigin() << endl;
        file << animal->getAge() << endl;
        file << animal->getWeight() << endl;
        file << animal->getFoodDay() << endl;
        if (animal->getType() == "Crocodile") {
            Crocodile *crocodile = dynamic_cast<Crocodile *>(animal);
            file << crocodile->getLength() << endl;
        }
    }
    file << enclosures.size() << endl;
    for (Area *enclosure: enclosures) {
        file << enclosure->getType() << endl;
        file << enclosure->getName() << endl;
        file << enclosure->getAnimalType() << endl;
        file << enclosure->getMaxAnimals() << endl;
        if (enclosure->getType() == "LandEnclosure") {
            LandEnclosure *land = dynamic_cast<LandEnclosure *>(enclosure);
            file << land->getArea() << endl;
        } else if (enclosure->getType() == "Aquarium") {
            Aquarium *aquarium = dynamic_cast<Aquarium *>(enclosure);
            file << aquarium->getWaterTemperature() << endl;
        } else if (enclosure->getType() == "Terrarium") {
            Terrarium *terrarium = dynamic_cast<Terrarium *>(enclosure);
            file << terrarium->getTemperature() << endl;
            file << terrarium->getHumidity() << endl;
        }
        vector<Animal *> enclosureAnimals = enclosure->getAnimals();
        file << enclosureAnimals.size() << endl;
        for (Animal *animal: enclosureAnimals) {
            file << animal->getName() << endl;
        }
    }
    file.close();
}

void Zoo::loadFromFile() {
    ifstream file(folderPath + "zoo.txt");
    if (!file.is_open()) {
        newZoo();
        return;
    }
    int animalCount;
    if (!(file >> animalCount) || animalCount == 0) {
        file.close();
        newZoo();
        return;
    }
    file.ignore();

    for (int i = 0; i < animalCount; i++) {
        string type;
        string name;
        string origin;
        int age;
        double weight;
        double foodDay;
        getline(file, type);
        getline(file, name);
        getline(file, origin);
        file >> age;
        file >> weight;
        file >> foodDay;
        file.ignore();
        Animal *animal = nullptr;
        if (type == "Tiger") {
            animal = new Tiger(name, origin, age, weight, foodDay);
        } else if (type == "Crocodile") {
            double length;
            file >> length;
            file.ignore();
            animal = new Crocodile(name, origin, age, weight, foodDay, length);
        } else if (type == "Kangaroo") {
            animal = new Kangaroo(name, origin, age, weight, foodDay);
        } else if (type == "Koala") {
            animal = new Koala(name, origin, age, weight, foodDay);
        } else if (type == "Capybara") {
            animal = new Capybara(name, origin, age, weight, foodDay);
        } else if (type == "Lion") {
            animal = new Lion(name, origin, age, weight, foodDay);
        } else if (type == "Elephant") {
            animal = new Elephant(name, origin, age, weight, foodDay);
        } else if (type == "Penguin") {
            animal = new Penguin(name, origin, age, weight, foodDay);
        } else if (type == "Snake") {
            animal = new Snake(name, origin, age, weight, foodDay);
        }
        if (animal != nullptr) {
            animals.push_back(animal);
        }
    }
    int enclosureCount;
    file >> enclosureCount;
    file.ignore();
    cout << "CHECK areas: " << enclosureCount << endl;
    for (int i = 0; i < enclosureCount; i++) {
        string type;
        string name;
        string animalType;
        int maxAnimals;
        getline(file, type);
        getline(file, name);
        getline(file, animalType);
        file >> maxAnimals;
        file.ignore();
        Area *enclosure = nullptr;
        if (type == "LandEnclosure") {
            double area;
            file >> area;
            file.ignore();
            enclosure = new LandEnclosure(name, animalType, maxAnimals, area);
        } else if (type == "Aquarium") {
            double waterTemperature;
            file >> waterTemperature;
            file.ignore();
            enclosure = new Aquarium(name, animalType, maxAnimals, waterTemperature);
        } else if (type == "Terrarium") {
            double temperature;
            double humidity;
            file >> temperature;
            file >> humidity;
            file.ignore();
            enclosure = new Terrarium(name, animalType, maxAnimals, temperature, humidity);
        }
        if (enclosure != nullptr) {
            enclosures.push_back(enclosure);
            int enclosureAnimalCount;
            file >> enclosureAnimalCount;
            file.ignore();
            for (int j = 0;
                 j < enclosureAnimalCount;
                 j++) {
                string animalName;
                getline(file, animalName);
                Animal *animal = findAnimal(animalName);
                if (animal != nullptr) {
                    enclosure->addAnimal(animal);
                }
            }
        }
    }
    file.close();
}

void Zoo::showVisitorStatistics() {
    cout << visitorStatistics;
}

void Zoo::deleteAnimal(Animal *animal) {
    if (animal == nullptr) {
        return;
    }
    for (Area *enclosure: enclosures) {
        vector<Animal *> enclosureAnimals = enclosure->getAnimals();
        for (Animal *enclosureAnimal: enclosureAnimals) {
            if (enclosureAnimal == animal) {
                enclosure->deleteAnimal(animal);
                break;
            }
        }
    }
    for (auto it = animals.begin();
         it != animals.end();
         ++it) {
        if (*it == animal) {
            animals.erase(it);
            delete animal;
            return;
        }
    }
}

bool Zoo::deleteAnimalMenu() {
    string name;
    cout << "Enter animal name: ";
    cin >> name;
    Animal *animal = findAnimal(name);
    if (animal == nullptr) {
        cout << "Animal not found" << endl;
        return false;
    }
    deleteAnimal(animal);
    cout << "Animal deleted successfully" << endl;
    return true;
}

bool Zoo::addEnclosureMenu() {
    string type;
    string name;
    string animalType;
    int maxAnimals;
    cout << "Enter enclosure type\n(LandEnclosure/Aquarium/Terrarium): ";
    cin >> type;
    cout << "Enter enclosure name: ";
    cin >> name;
    cout << "Enter animal type: ";
    cin >> animalType;
    cout << "Enter max number of animals: ";
    cin >> maxAnimals;
    Area *enclosure = nullptr;
    if (type == "LandEnclosure") {
        double area;
        cout << "Enter area: ";
        cin >> area;
        enclosure = new LandEnclosure(name, animalType, maxAnimals, area);
    } else if (type == "Aquarium") {
        double waterTemperature;
        cout << "Enter water temperature: ";
        cin >> waterTemperature;
        enclosure = new Aquarium(name, animalType, maxAnimals, waterTemperature);
    } else if (type == "Terrarium") {
        double temperature;
        double humidity;
        cout << "Enter temperature: ";
        cin >> temperature;
        cout << "Enter humidity: ";
        cin >> humidity;
        enclosure = new Terrarium(name, animalType, maxAnimals, temperature, humidity);
    } else {
        cout << "Unknown enclosure type" << endl;
        return false;
    }
    addEnclosure(enclosure);
    cout << "Enclosure added successfully" << endl;
    return true;
}

bool Zoo::deleteEnclosureMenu() {
    string name;
    cout << "Enter enclosure name: ";
    cin >> name;
    Area *found = nullptr;
    for (Area *enclosure: enclosures) {
        if (enclosure->getName() == name) {
            found = enclosure;
            break;
        }
    }
    if (found == nullptr) {
        cout << "Enclosure not found" << endl;
        return false;
    }
    deleteEnclosure(found);
    cout << "Enclosure deleted successfully" << endl;
    return true;
}
