#include "Election.h"

ManagerialTeam::ManagerialTeam() {};

ManagerialTeam::ManagerialTeam(string _name, vector<Stance> _stanceValues, int _eventImpact)
{
    entityName = _name;
    stanceValues = _stanceValues;
    teamEventImpact = _eventImpact;
}

ManagerialTeam::ManagerialTeam(const ManagerialTeam &team)
{
    entityName = team.entityName;
    stanceValues = team.stanceValues;
    teamEventImpact = team.teamEventImpact;
}

int ManagerialTeam::getTeamEventImpact()
{
    return teamEventImpact;
}

void ManagerialTeam::setEventImpact(int _eventImpact)
{
    teamEventImpact = _eventImpact;
}

void ManagerialTeam::displayTeamEventImpact()
{
    cout << "Name: " << entityName << endl;
    cout << "Team Event Impact: " << teamEventImpact << "\n" << endl;
}

void ManagerialTeam::displayTeamStances()
{
    cout.width(30); cout << left << entityName;
    Entity::displayStance();
}
