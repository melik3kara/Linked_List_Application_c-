/**
*Melike Kara
 *22203094
 *Sec 002
*/
#include <string>
#include <iostream>
#include "Spacecraft.h"
using namespace std;
#ifndef MISSION_H
#define MISSION_H


class Mission
{
public:

    Mission();
    Mission(const string name, const string &launchDate,const string &destination);
    ~Mission();
    string name;
    string launchDate;
    string destination;
    int numSpacecrafts;
    Spacecraft* spacecraftsOfMission;
    Mission& operator=(const Mission& other);
};

#endif // MISSION_H