#include "Election.h"

Stance::Stance(){}

Stance::Stance(string _type)
{
    issueType = _type;
    stanceSignificance = random(1, 10);
    stanceApproach = random(1, 10);
}

Stance::Stance(string _type, STANCERANGE range)
{
    issueType = _type;
    stanceSignificance = random(range.s_min, range.s_max);
    stanceApproach = random(range.a_min, range.a_max);
}

Stance::Stance(string _type, int _significance, int _approach)
{
    issueType = _type;
    stanceSignificance = _significance;
    stanceApproach = _approach;
}

string Stance::getIssueType()
{
    return issueType;
}

int Stance::getStanceSignificance()
{
    return stanceSignificance;
}

int Stance::getStanceApproach()
{
    return stanceApproach;
}

void Stance::setStanceSignificance(int _significant)
{
    stanceSignificance = _significant;
}

void Stance::setStanceApproach(int _approach)
{
    stanceApproach = _approach;
}

string Stance::displayPartialStance()
{
    string partialStance = to_string(stanceSignificance) + "/" + to_string(stanceApproach);
    return partialStance;
}

double Stance::calculation(Stance &stance)
{
    return sqrt(pow((stanceSignificance-stance.stanceSignificance),2.0) + pow((stanceApproach-stance.stanceApproach),2.0));;
}
