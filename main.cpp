#include "Zoo.h"
#include "User.h"
#include <set>
#include <map>

int main() {
    admin admin;
    if (!admin.exists()) {
        cout << "There is no admin" << endl;
        if (!admin.registerAdmin()) {
            return 0;
        }
    }
    if (!admin.loginAdmin()) {
        return 0;
    }

    Zoo zoo;
    int menu;
    bool changed = false;
    do {
        cout << endl;
        cout << "MENU " << endl;
        cout << "1. Show all animals (short info)" << endl;
        cout << "2. Show all enclosures" << endl;
        cout << "3. Find animal (to get more info about each animal)" << endl;
        cout << "4. Add animal" << endl;
        cout << "5. Delete animal" << endl;
        cout << "6. Add enclosure" << endl;
        cout << "7. Delete enclosure" << endl;
        cout << "8. Show origins" << endl;
        cout << "9. Show animal statistics" << endl;
        cout << "10. Show visitor statistics" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> menu;

        try {
            switch (menu) {
                case 1:
                    zoo.showAnimals();
                    break;
                case 2:
                    zoo.showEnclosures();
                    break;
                case 3:
                    { string name;
                    cout << "Enter animal name: ";
                    cin >> name;
                    Animal* animal = zoo.findAnimal(name);
                    if (animal != nullptr) {
                        cout << endl;
                        cout << *animal << endl;
                    }
                    else {
                        cout << "Animal not found" << endl;
                    }
                    break;
                }
                case 4:
                    if (zoo.addAnimalMenu()) {
                        changed = true;
                    }
                    break;
                case 5:
                    if (zoo.deleteAnimalMenu()) {
                        changed = true;
                    }
                    break;
                case 6:
                    if (zoo.addEnclosureMenu()) {
                        changed = true;
                    }
                    break;
                case 7:
                    if (zoo.deleteEnclosureMenu()) {
                        changed = true;
                    }
                    break;
                case 8:
                {
                    set<string> origins = zoo.getOrigins();
                    cout << "Origins:" << endl;
                    for (string origin : origins) {
                        cout << "- " << origin << endl;
                    }
                    break;
                }
                case 9:
                {
                    map<string, int> statistics = zoo.getAnimalStatistics();
                    cout << "Animal statistics:" << endl;
                    for (auto item : statistics) {
                        cout << item.first << ": " << item.second << endl;
                    }
                    break;
                }
                case 10:
                    zoo.showVisitorStatistics();
                    break;
                case 0:
                    cout << "Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice" << endl;
            }
        }
        catch (const char* error) {
            cout << "Error: " << error << endl;
        }
    } while (menu != 0);
    if (changed) {
        zoo.saveToFile();
    }
    return 0;
}