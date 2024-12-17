/**
*Melike Kara
 *22203094
 *Sec 002
*/
#include <string>
#include <iostream>
#include "Spacecraft.h"
using namespace std;

Spacecraft::Spacecraft() {
    name = "";
    type = "";
    assignedMission = "";
    isAssigned = false;
}

Spacecraft::Spacecraft(const string name, const string type, const string assignedMission) {
    this->name = name;
    this->type = type;
    this->assignedMission = assignedMission;
    this->isAssigned = false;
}

Spacecraft& Spacecraft::operator=(const Spacecraft& other) {
    if (this != &other) {
        // Copy all members from the other object
        name = other.name;
        type = other.type;
        assignedMission = other.assignedMission;
        isAssigned = other.isAssigned;  // Don't forget to copy this flag
    }
    return *this;
}
