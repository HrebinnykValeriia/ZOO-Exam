#include "Visitors.h"
#include <cstdlib>
#include <ctime>

VisitorStatistics::VisitorStatistics() {
    visitors.resize(7);
    makeStatistics();
}
void VisitorStatistics::makeStatistics() {
    srand(time(0));
    for (int i = 0; i < 7; i++) {
        if (i < 5) {
            visitors[i] = 150 + rand() % 251;
        }
        else {
            visitors[i] = 400 + rand() % 301;
        }
    }
}
int VisitorStatistics::totalVisitors() const {
    int total = 0;
    for (int visitor : visitors) {
        total += visitor;
    }
    return total;
}
double VisitorStatistics::averageVisitors() const {
    return (double)totalVisitors() / visitors.size();
}
Day VisitorStatistics::maxDay() const {
    int max = visitors[0];
    int maxIndex = 0;
    for (int i = 1; i < 7; i++) {
        if (visitors[i] > max) {
            max = visitors[i];
            maxIndex = i;
        }
    }
    return (Day)maxIndex;
}
Day VisitorStatistics::minDay() const {
    int min = visitors[0];
    int minIndex = 0;
    for (int i = 1; i < 7; i++) {
        if (visitors[i] < min) {
            min = visitors[i];
            minIndex = i;
        }
    }
    return (Day)minIndex;
}
ostream& operator<<(ostream& s, const VisitorStatistics& statistics) {
    string dayNames[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"};
    s << "Visitor statistics:" << endl;
    for (int i = 0; i < 7; i++) {
        s << dayNames[i] << ": " << statistics.visitors[i] << endl;
    }
    s << "Total visitors: " << statistics.totalVisitors() << endl;
    s << "Average visitors: " << statistics.averageVisitors() << endl;
    s << "The busiest day: " << dayNames[statistics.maxDay()] << endl;
    s << "The least busy day: " << dayNames[statistics.minDay()] << endl;
    return s;
}