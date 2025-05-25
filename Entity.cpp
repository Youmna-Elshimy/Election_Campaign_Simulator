#include "Election.h"

string Entity::getEntityName()
{
    return entityName;
}

vector<Stance> Entity::getStanceValues()
{
    return stanceValues;
}

void Entity::setStance(vector<Stance> originalStanceValues)
{
    stanceValues = originalStanceValues;
}

void Entity::changeStance(string issueType, int newApproach, int newSignificance)
{
    for(auto &entity: stanceValues)
    {
        if(entity.getIssueType() == issueType)
        {
            entity.setStanceApproach(newApproach);
            entity.setStanceSignificance(newSignificance);
        }
    }
}

void Entity::displayStance()
{
    for (auto &entity: stanceValues)
    {
        cout.width(20); cout << left << entity.displayPartialStance();
    }
}
