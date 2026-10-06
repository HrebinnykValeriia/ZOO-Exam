#include "Species.h"

Tiger::Tiger(string name, string origin, int age, double weight, double foodDay)
    : Animal(name, origin, age, weight, foodDay) {
}
string Tiger::getType() const{
    return "Tiger";
}

Crocodile::Crocodile(string name, string origin, int age, double weight, double foodDay, double length)
    :Animal(name, origin, age, weight, foodDay) {
    this->length = length;
}
string Crocodile::getType() const{
    return "Crocodile";
}
double Crocodile::getLength() const {
    return length;
}

Kangaroo::Kangaroo(string name, string origin, int age, double weight, double foodDay)
    : Animal(name, origin, age, weight, foodDay) {
}
string Kangaroo::getType() const{
    return "Kangaroo";
}

Koala::Koala(string name, string origin, int age, double weight, double foodDay)
    : Animal(name, origin, age, weight, foodDay) {
}
string Koala::getType() const{
    return "Koala";
}

Capybara::Capybara(string name, string origin, int age, double weight, double foodDay)
    : Animal(name, origin, age, weight, foodDay) {
}
string Capybara::getType() const{
    return "Capybara";
}

Lion::Lion(string name, string origin, int age, double weight, double foodDay)
    : Animal(name, origin, age, weight, foodDay) {
}
string Lion::getType() const{
    return "Lion";
}

Elephant::Elephant(string name, string origin, int age, double weight, double foodDay)
    : Animal(name, origin, age, weight, foodDay) {
}
string Elephant::getType() const{
    return "Elephant";
}

Penguin::Penguin(string name, string origin, int age, double weight, double foodDay)
    : Animal(name, origin, age, weight, foodDay) {
}
string Penguin::getType() const{
    return "Penguin";
}

Snake::Snake(string name, string origin, int age, double weight, double foodDay)
    :Animal(name, origin, age, weight, foodDay) {
}
string Snake::getType() const{
    return "Snake";
}
