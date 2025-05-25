#include "Election.h"

Group::Group(string _name, vector<Stance> _sValues, int _population)
{
    entityName = _name;
    stanceValues = _sValues;
    population = _population;
}

int Group::getPopulation()
{
    return population;
}

void Group::displayGroupStanceValues()
{
    cout.width(40); cout << left << entityName + " (Population: " + to_string(population) + ")";
    Entity::displayStance();
}
