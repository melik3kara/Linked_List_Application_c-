/**
*Melike Kara
 *22203094
 *Sec 002
*/
#include <string>
#include <iostream>
#include "Mission.h"
using namespace std;

    Mission::Mission()
    {
        this->name = "";
        this->launchDate = "";
        this->destination="";
        this->spacecraftsOfMission = nullptr;
        this->numSpacecrafts = 0;
    }

    Mission::Mission(const string name, const string &launchDate,const string &destination)
    {
        this->name = name;
        this->launchDate = launchDate;
        this->spacecraftsOfMission = nullptr;
        this->numSpacecrafts = 0;
        this->destination=destination;
    }
    Mission::~Mission(){
        if(spacecraftsOfMission){
            delete[] spacecraftsOfMission;
        }
    }
    Mission& Mission::operator=(const Mission& other) {
        if(this!=&other) {
            name = other.name;
            launchDate = other.launchDate;
            numSpacecrafts = other.numSpacecrafts;
            destination = other.destination;
            if ( numSpacecrafts != other.numSpacecrafts ) {
                if ( numSpacecrafts > 0 ) {
                    delete[] spacecraftsOfMission;
                }
                numSpacecrafts = other.numSpacecrafts;
                if ( numSpacecrafts > 0 ) {
                    spacecraftsOfMission = new Spacecraft[ numSpacecrafts ];
                }
                else {
                    spacecraftsOfMission = nullptr;
                }
            }
            for ( int i = 0; i < numSpacecrafts; i++ ){
                spacecraftsOfMission[ i ] = other.spacecraftsOfMission[ i ];
            }
        }
        return  *this;
    }
