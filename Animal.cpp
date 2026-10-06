#include "Animal.h"
Animal::Animal(string name, string origin, int age, double weight, double foodDay){
    this->name = name;
    this->origin = origin;
    this->age = age;
    this->weight = weight;
    this->foodDay = foodDay;
}
Animal::~Animal() {
}
string Animal::getName() {
    return name;
}
string Animal::getOrigin() {
    return origin;
}
int Animal::getAge() {
    return age;
}

double Animal::getWeight() {
    return weight;
}
double Animal::getFoodDay() {
    return foodDay;
}
double Animal::foodMonth() const {
    return foodDay * 30;
}
ifstream& operator>>(ifstream& s, Animal& animal) {
    getline(s, animal.name);
    getline(s, animal.origin);
    s >> animal.age;
    s >> animal.weight;
    s >> animal.foodDay;
    if (s.peek() == (int)'\n') {
        s.ignore();
    }
    return s;
}
ofstream& operator<<(ofstream& s, const Animal& animal) {
    s << animal.name << endl;
    s << animal.origin << endl;
    s << animal.age << endl;
    s << animal.weight << endl;
    s << animal.foodDay << endl;
    return s;
}
ostream& operator<<(ostream& s, const Animal& animal) {
    s << "Type: " << animal.getType()  << endl;
    s << "Name: " << animal.name << endl;
    s << "Origin: " << animal.origin << endl;
    s << "Age: " << animal.age << endl;
    s << "Weight: " << animal.weight << " kg" << endl;
    s << "Food per day: " << animal.foodDay << " kg" << endl;
    s << "Food per month: " << animal.foodMonth() << " kg" << endl;
    return s;
}
