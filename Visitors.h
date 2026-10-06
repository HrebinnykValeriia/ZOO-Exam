#ifndef VISITORS_H
#define VISITORS_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum Day {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};
class VisitorStatistics {
private:
    vector<int> visitors;
public:
    VisitorStatistics();
    void makeStatistics();
    int totalVisitors() const;
    double averageVisitors() const;
    Day maxDay() const;
    Day minDay() const;
    friend ostream& operator<<(ostream& s, const VisitorStatistics& statistics);
};
#endif