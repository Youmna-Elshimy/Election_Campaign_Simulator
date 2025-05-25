#include "Election.h"

Leader::Leader(): Human() {};

Leader::Leader(string _ID, string _name, vector<Stance> _stanceValues,  map<string, int> _characters):
    Human(_characters)
{
    leaderID = _ID;
    entityName = _name;
    stanceValues = _stanceValues;
}

Leader::Leader(const Leader &leader):
    Human(leader.characteristics)
{
    leaderID = leader.leaderID;
    entityName = leader.entityName;
    stanceValues = leader.stanceValues;
}

void Leader::displayLeader()
{
    cout << entityName << " (" << leaderID << ")";
}

void Leader::displayLeaderStances()
{
    cout << entityName << " (" << leaderID << ")";
    cout.width(20); cout << left << "";
    Entity::displayStance();
}

void Leader::displayLeaderCharacteristics()
{
    cout << entityName << " (" << leaderID << ")" << endl;
    Human::displayCharacteristics();
}
