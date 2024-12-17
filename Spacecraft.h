/**
*Melike Kara
 *22203094
 *Sec 002
*/
#include <string>
#include <iostream>
using namespace std;
#ifndef SPACECRAFT_H
#define SPACECRAFT_H


class Spacecraft {
public:

    Spacecraft();
    string name;
    string type;
    string assignedMission;
    bool isAssigned;

    Spacecraft(const string name, const string type, const string assignedMission);

    Spacecraft& operator=(const Spacecraft& other);
};

#endif // SPACECRAFT_H