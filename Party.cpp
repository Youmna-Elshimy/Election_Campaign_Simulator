#include "Election.h"

Party::Party(string _partyName, Leader _leader, map<Electorate, Candidate> _candidates, ManagerialTeam _team, vector<StanceRange> _partyRange, double _partyBudget)
{
    partyName = _partyName;
    leader = _leader;
    candidates = _candidates;
    partyTeam = _team;
    partyRange = _partyRange;
    partyBudget = _partyBudget;
}

string Party::getPartyName()
{
    return partyName;
}

Leader& Party::getPartyLeaderInfo()
{
    return leader;
}

double Party::getPartyBudget()
{
    return partyBudget;
}

int Party::getPartyWinningCount()
{
    return winningCount;
}

Candidate& Party::getCandidatesInfo(Electorate electorate)
{
    return candidates.find(electorate)->second;
}

int Party::getPartyTotalVotes()
{
    updatePartyTotalVotes();
    return partyTotalVotes;
}

void Party::increaseWinningCount()
{
    winningCount++;
}

void Party::updatePartyTotalVotes()
{
    partyTotalVotes = 0;
    for (auto candidate = candidates.begin(); candidate != candidates.end(); candidate++)
    {
        partyTotalVotes = partyTotalVotes + candidate->second.getCandidateVotes();
    }
}

void Party::changePartyBudget(double funds)
{
    partyBudget = partyBudget + funds;
}

void Party::displayParty()
{
    cout << partyName << endl;

    cout << "Party Leader: ";
    leader.displayLeaderCharacteristics();

    cout << "Party Managerial Team: ";
    partyTeam.displayTeamEventImpact();

    for (auto candidate = candidates.begin(); candidate != candidates.end(); candidate++)
    {
        cout << "Party Candidate: ";
        candidate->second.displayCandidateCharacteristics();
    }

    cout.width(30); cout << left << "STANCES (Sig, Appr)";

    for (auto &issue: IssueType)
    {
        cout.width(20); cout << left << issue;
    }

    cout << endl;

    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    cout.width(30); cout << left << "Range ";

    for(auto range: partyRange)
    {
        cout.width(20); cout << left << range.toString();
    }
    cout << endl;

    leader.displayLeaderStances();
    cout << endl;

    partyTeam.displayTeamStances();
    cout << endl;

    for (auto candidate = candidates.begin(); candidate != candidates.end(); candidate++)
    {
        candidate->second.displayCandidateStances();
        cout << endl;
    }

    cout << endl;
}
