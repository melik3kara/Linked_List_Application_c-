/**
 *Melike Kara
 *22203094
 *Sec 002
*/
#include <iostream>
#include <string>
#include "Mission.h"
#include "Spacecraft.h"
#include "SpaceMissionManagementSystem.h"
using namespace std;
    SpaceMissionManagementSystem::SpaceMissionManagementSystem()
    {
        missions = nullptr;
        spacecrafts = nullptr;
        numMissions = 0;
        numSpacecrafts = 0;
    }

    SpaceMissionManagementSystem::~SpaceMissionManagementSystem() {
        if(spacecrafts){
            delete[] spacecrafts;
        }
        if(missions){
            delete[] missions;
        }
    }

        void SpaceMissionManagementSystem::addMission(const string name, const string launchDate, const string destination) {
            if(isThereSameMission(name)) {
                cout<<"Cannot add mission. Mission " <<name<< " already exists."<< endl;
            }
            else {
                Mission * tempMissions = new Mission[numMissions+1];
                for(int i = 0; i < numMissions; i++) {
                    tempMissions[i] = missions[i];
                }
                tempMissions[numMissions].name =name;
                tempMissions[numMissions].launchDate =launchDate;
                tempMissions[numMissions].destination =destination;
                cout<<"Added mission " << tempMissions[numMissions].name<< "."<< endl;
                if(missions != nullptr) {
                    delete[] missions;
                }
                missions = tempMissions;
                numMissions++;
            }
        }

        void SpaceMissionManagementSystem::removeMission(const string name) {
            if(isThereSameMission(name)) {

                int index = findMissionsIndex(name);

                if(missions[index].numSpacecrafts != 0) {
                    for (int i = 0; i < missions[index].numSpacecrafts; i++) {
                        for (int j = 0; j < numSpacecrafts; j++) {
                            if(missions[index].spacecraftsOfMission[i].name == spacecrafts[j].name) {
                                missions[index].spacecraftsOfMission[i].isAssigned = false;
                                spacecrafts[j].isAssigned=false;
                            }
                        }
                    }
                }

                if(numMissions>1) {
                    Mission* tempMissions = new Mission[numMissions-1];
                    for(int i = 0; i < index; i++){
                        tempMissions[i] = missions[i];
                    }
                    for(int i = index + 1; i < numMissions; i++){
                        tempMissions[i - 1] = missions[i];
                    }
                    numMissions--;
                    delete[] missions;
                    missions = tempMissions;
                }
                else {
                    delete[] missions;
                    missions = nullptr;
                    numMissions = 0;
                }
                cout<<"Removed mission " << name<< "."<<endl;
            }
            else {
                cout<<"Cannot remove mission. Mission "<< name<< " does not exist."<<endl;
            }
        }

        void SpaceMissionManagementSystem::addSpacecraft(const string name, const string type) {
            if(isThereSameSpacecraft(name)) {
                cout<<"Cannot add spacecraft. Spacecraft " <<name<< " already exists."<< endl;
            }
            else {
                Spacecraft* tempSpacecrafts = new Spacecraft[numSpacecrafts + 1];
                for(int i = 0; i < numSpacecrafts; i++){
                    tempSpacecrafts[i] = spacecrafts[i] ;
                }

                tempSpacecrafts[numSpacecrafts].isAssigned = false;
                tempSpacecrafts[numSpacecrafts].name = name;
                tempSpacecrafts[numSpacecrafts].type = type;
                cout<<"Added spacecraft " << tempSpacecrafts[numSpacecrafts].name<< "."<<endl;
                if(spacecrafts != nullptr) {
                    delete[] spacecrafts;
                }
                spacecrafts = tempSpacecrafts;
                numSpacecrafts ++;
            }
        }

        void SpaceMissionManagementSystem::removeSpacecraft(const string name) {
            if(isThereSameSpacecraft(name)) {
                int indexSpacecraft = -1;
                for(int i = 0; i < numSpacecrafts; i++) {
                    if(spacecrafts[i].name == name) {
                        indexSpacecraft = i;
                        break;
                    }
                }
                if(spacecrafts[indexSpacecraft].isAssigned) {
                    cout<<"Cannot remove spacecraft. Spacecraft " << spacecrafts[indexSpacecraft].name << " is assigned to a mission."<< endl;
                }
                else {
                    if(numSpacecrafts > 1) {
                        Spacecraft* tempSpacecrafts = new Spacecraft[numSpacecrafts -1] ;
                        for(int i = 0; i < indexSpacecraft; i++) {
                            tempSpacecrafts[i] = spacecrafts[i];
                        }
                        for(int i = indexSpacecraft + 1; i < numSpacecrafts; i++) {
                            tempSpacecrafts[i-1] = spacecrafts[i];
                        }
                        if(spacecrafts != nullptr) {
                            delete[] spacecrafts;
                        }
                        spacecrafts = tempSpacecrafts;
                        numSpacecrafts--;
                    }
                    else {
                        if(spacecrafts != nullptr) {
                            delete[] spacecrafts;
                        }
                        spacecrafts = nullptr;
                        numSpacecrafts = 0;
                    }
                    cout << "Removed spacecraft " << name << "."<< endl;
                }
            }
            else {
                cout << "Cannot remove spacecraft. Spacecraft " <<name<<" does not exist." << endl;
            }
    }

    void SpaceMissionManagementSystem::assignSpacecraftToMission(const string spacecraftName, const string missionName) {
        if(isThereSameSpacecraft(spacecraftName)==false) {
            cout<<"Cannot assign spacecraft. Spacecraft " <<spacecraftName << " does not exist."<< endl;
        }
        else if(isThereSameMission(missionName)==false){
            cout<<"Cannot assign spacecraft. Mission " <<missionName << " does not exist."<< endl;
        }
        else {
            Mission * missionTarget = &(missions[findMissionsIndex(missionName)]);
            Spacecraft * spacecraftsTarget = &(spacecrafts[findSpacecraftsIndex(spacecraftName)]);

            if(spacecrafts[findSpacecraftsIndex(spacecraftName)].isAssigned) {
                cout<<"Cannot assign spacecraft. Spacecraft " <<spacecraftName << " is already assigned to mission " << spacecrafts[findSpacecraftsIndex(spacecraftName)].assignedMission << "."<< endl;
            }
            else {
                Spacecraft* temp_spacecrafts = new Spacecraft[missionTarget->numSpacecrafts + 1];
                for (int i = 0; i < missionTarget->numSpacecrafts; i++) {
                    temp_spacecrafts[i] = missionTarget->spacecraftsOfMission[i];
                }
                temp_spacecrafts[missionTarget->numSpacecrafts] = *spacecraftsTarget;
                if(missionTarget->spacecraftsOfMission != nullptr) {
                    delete[] missionTarget->spacecraftsOfMission;
                }
                spacecraftsTarget->assignedMission = missionTarget->name;
                spacecraftsTarget->isAssigned = true;
                missionTarget->numSpacecrafts ++;
                missionTarget->spacecraftsOfMission = temp_spacecrafts;
                spacecrafts[findSpacecraftsIndex(spacecraftName)].isAssigned=true;
                cout<<"Assigned spacecraft " << spacecraftName<< " to mission "<< missionName<< "."<< endl;
            }
        }
    }

    void SpaceMissionManagementSystem::dropSpacecraftFromMission(const string spacecraftName) {
        if(isThereSameSpacecraft(spacecraftName)) {
            int index = -1;//dummy number
            index = findSpacecraftsIndex(spacecraftName);
            if(spacecrafts[index].isAssigned==false) {
                cout<<"Cannot drop spacecraft. Spacecraft " << spacecraftName<< " is not assigned to any mission." << endl;
                return;
            }

            Mission* missionTarget = &missions[findMissionsIndex(spacecrafts[index].assignedMission)];
            Spacecraft* temp_spacecrafts =  new Spacecraft[missionTarget->numSpacecrafts-1];
            int spaceIndexInArray = -1;
            for (int i = 0; i < missionTarget->numSpacecrafts; ++i) {
                if(missionTarget->spacecraftsOfMission[i].name==spacecraftName) {
                    spaceIndexInArray = i;
                }
            }
            for (int i = 0; i < spaceIndexInArray; i++) {
                temp_spacecrafts[i] = missionTarget->spacecraftsOfMission[i] ;
            }
            for (int i = spaceIndexInArray + 1; i < missionTarget->numSpacecrafts; i++) {
                temp_spacecrafts[i-1] = missionTarget->spacecraftsOfMission[i] ;
            }
            if(missionTarget->spacecraftsOfMission!=nullptr) {
                delete[] missionTarget->spacecraftsOfMission;
            }
            missionTarget->spacecraftsOfMission = temp_spacecrafts;
            missionTarget->numSpacecrafts --;
            spacecrafts[index].assignedMission = "";
            spacecrafts[index].isAssigned = false;

            cout<<"Dropped spacecraft " << spacecraftName<< " from mission "<<missionTarget->name<<"." << endl;
        }
        else {
            cout<<"Cannot drop spacecraft. Spacecraft " << spacecraftName<< " does not exist." << endl;
        }
    }

    void SpaceMissionManagementSystem::showAllMissions() const {
        cout << "Missions in the space mission management system:" << endl;
        if(numMissions > 0){
            for(int i = 0; i < numMissions; i++){
                cout <<"Mission: "<< missions[i].name << ", Launch Date: " << missions[i].launchDate << ", Destination: "
                << missions[i].destination <<", Assigned Spacecraft Count: " << missions[i].numSpacecrafts <<endl;
            }
        }
        else{
            cout << "None" << endl;
        }
    }

    void SpaceMissionManagementSystem::showAllSpacecrafts() const {
            cout << "Spacecrafts in the space mission management system:" << endl;
            if(numSpacecrafts > 0){

                for(int i = 0; i < numSpacecrafts; i++){
                    if(!spacecrafts[i].isAssigned) {
                        cout <<"Spacecraft: "<< spacecrafts[i].name << ", Type: " << spacecrafts[i].type
                    << ", Status: " << "Available" <<endl;
                    }
                    else {
                        cout <<"Spacecraft: "<< spacecrafts[i].name << ", Type: " << spacecrafts[i].type
                    << ", Status: " << "Assigned" <<endl;
                    }

                }
            }
            else{
                cout << "None" << endl;
            }
    }

    void SpaceMissionManagementSystem::showMission(const string name) const {
        if(isThereSameMission(name))
        {
            int index = -1; //dummy number
            for(int i = 0; i<numMissions; i++) {
                if(missions[i].name == name) {
                    index = i;
                }
            }

            cout << "Mission:"<<endl<< "  Name: "<<missions[index].name << endl<<"  Launch Date: " << missions[index].launchDate << endl<<"  Destination: "
                    << missions[index].destination <<endl<<
                        "  Assigned Spacecrafts:"  <<endl;
            if(missions[index].numSpacecrafts==0) {
                cout<<"    None"<<endl;
            }
            else {
                for(int i = 0; i<missions[index].numSpacecrafts; i++) {
                    cout<<"  - " << missions[index].spacecraftsOfMission[i].name<< endl;
                }
            }

        }
        else{
            cout << "Cannot show mission. Mission " << name<< " does not exist."<< endl;
        }
    }

    void SpaceMissionManagementSystem::showSpacecraft( const string name ) const {
        if(isThereSameSpacecraft(name))
        {
            int index = -1; //dummy number
            for(int i = 0; i<numSpacecrafts; i++) {
                if(spacecrafts[i].name == name) {
                    index = i;
                }
            }
            cout<<"Spacecraft: ";
            if(spacecrafts[index].isAssigned) {
                cout << spacecrafts[index].name << ", Type: " << spacecrafts[index].type
                    << ", " << "Status: Assigned" <<endl;
            }
            else {
                cout << spacecrafts[index].name << ", Type: " << spacecrafts[index].type
                    << ", " << "Status: Available" <<endl;
            }
        }
        else{
            cout << "Cannot show spacecraft. Spacecraft " << name<< " does not exist."<< endl;
        }
    }

    //helper methods
    bool SpaceMissionManagementSystem::isThereSameMission(string name) const{
        bool thereIs = false;
        for(int i = 0; i < numMissions && !thereIs; i++){
            if(missions[i].name.compare(name) == 0){
                thereIs = true;
            }
        }
        return thereIs;
    }

    bool SpaceMissionManagementSystem::isThereSameSpacecraft(string name) const{
        bool thereIs = false;
        for(int i = 0; i < numSpacecrafts && !thereIs; i++){
            if(spacecrafts[i].name.compare(name) == 0){
                thereIs = true;
            }
        }
        return thereIs;
    }

    int SpaceMissionManagementSystem::findMissionsIndex(const string name) const {
        int ind = -1;//dummy num
        if(isThereSameMission(name)){
            for(int i = 0; i < numMissions; i++){
                if(missions[i].name.compare(name) == 0){
                    ind = i;
                }
            }
        }
        return ind;
    }
    int SpaceMissionManagementSystem::findSpacecraftsIndex(const string name) const {
        int ind = -1;//dummy num
        if(isThereSameSpacecraft(name)){
            for(int i = 0; i < numSpacecrafts; i++){
                if(spacecrafts[i].name.compare(name) == 0){
                    ind = i;
                }
            }
        }
        return ind;
    }