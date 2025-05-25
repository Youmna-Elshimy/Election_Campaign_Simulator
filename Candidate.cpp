#include "Election.h"

Candidate::Candidate(string _ID, string _name, vector<Stance> _stanceValues,  map<string, int> _characteristicValues):
    Human(_characteristicValues)
{
    candidateID = _ID;
    entityName = _name;
    stanceValues = _stanceValues;
}

Candidate::Candidate(const Candidate &candidate):
    Human(candidate.characteristics)
{
    candidateID = candidate.candidateID;
    entityName = candidate.entityName;
    stanceValues = candidate.stanceValues;
}

string Candidate::getCandidateID()
{
    return candidateID;
}

int Candidate::getCandidateVotes()
{
    return totalCandidateVotes;
}

void Candidate::updateCandidateVotes(int newVote)
{
    totalCandidateVotes = totalCandidateVotes + newVote;
}

void Candidate::displayCandidate()
{
    cout << entityName << " (" << candidateID << ")";
}

void Candidate::displayCandidateStances()
{
    cout << entityName << " (" << candidateID << ")";
    cout.width(20); cout << left << "";
    Entity::displayStance();
}

void Candidate::displayCandidateCharacteristics()
{
    cout << entityName << " (" << candidateID << ")" << endl;
    Human::displayCharacteristics();
}
