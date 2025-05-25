#include "Election.h"

Electorate::Electorate(string _areaName, vector<Group> _clusters)
{
    areaName = _areaName;
    clusters = _clusters;
}


bool Electorate::operator < (const Electorate& electorate) const
{
    return areaName < electorate.areaName;
}


string Electorate::getAreaName()
{
    return areaName;
}

vector<Group> Electorate::getCluster()
{
    return clusters;
}

int Electorate::getAreaPopulation()
{
    areaPopulation = 0;

    for (auto &cluster: clusters)
    {
        areaPopulation = areaPopulation + cluster.getPopulation();
    }

    return areaPopulation;
}

void Electorate::changeAreaStanceValues(string type, int newApproach, int newSignificance)
{
    for(auto &cluster: clusters)
        cluster.changeStance(type, newApproach, newSignificance);
}

void Electorate::displayArea()
{
    cout << areaName << " (Population: " << getAreaPopulation() << ")\n" << endl;

    cout.width(40); cout << left << "STANCES (Sig, Appr)";

    for (auto &issue: IssueType)
    {
        cout.width(20); cout << left << issue;
    }

    cout << endl;

    cout << "----------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (auto &cluster: clusters)
    {
        cluster.displayGroupStanceValues();
        cout << endl;
    }

    cout << endl;
}
