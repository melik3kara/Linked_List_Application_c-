/**
*Melike Kara
 *22203094
 *Sec 002
*/
#include <string>
#include "Mission.h"
#include "Spacecraft.h"
using namespace std;
class SpaceMissionManagementSystem {
public:
    Mission* missions; // dynamically allocated array of mission pointers
    int numMissions;

    Spacecraft* spacecrafts; // dynamically allocated array of spacecraft pointers
    int numSpacecrafts;

    SpaceMissionManagementSystem();

    ~SpaceMissionManagementSystem();

    void addMission(const string name, const string launchDate, const string destination);

    void removeMission(const string name);

    void addSpacecraft(const string name, const string type);

    void removeSpacecraft(const string name);

    void assignSpacecraftToMission(const string spacecraftName, const string missionName);

    void dropSpacecraftFromMission(const string spacecraftName);

    void showAllMissions() const;

    void showAllSpacecrafts() const;

    void showMission(const string name) const;

    void showSpacecraft( const string name ) const;

    bool isThereSameMission(const string name) const;

    bool isThereSameSpacecraft(const string name) const;

    int findMissionsIndex(const string name) const;

    int findSpacecraftsIndex(const string name) const;
};
