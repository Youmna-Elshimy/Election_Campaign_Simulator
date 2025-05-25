#include "Election.h"

Election::Election() {}

Election::Election(int _partyNum, int _electorateNum, vector<Issue> _issues, vector<Event> _events, vector<Electorate> _electorates, vector<Party> _parties)
{
    partyNum = _partyNum;
    electorateNum = _electorateNum;
    electionIssues = _issues;
    electionEvents = _events;
    electionElectorates = _electorates;
    electionParties = _parties;
}

int Election::getPartyNum()
{
    return partyNum;
}

int Election::getElectorateNum()
{
    return electorateNum;
}

vector<Issue>& Election::getElectionIssues()
{
    return electionIssues;
}

vector<Event>& Election::getElectionEvents()
{
    return electionEvents;
}

vector<Electorate>& Election::getElectionElectorates()
{
    return electionElectorates;
}

vector<Party>& Election::getElectionParties()
{
    return electionParties;
}

void Election::electionReport()
{
    cout.width(80); cout << left << "" << "ELECTION REPORT" << endl;
    cout.width(80); cout << left << "" << "***************" << endl;

    cout.width(80); cout << left << "" << "=== PARTIES ===" << endl;
    cout << "There are " << electionParties.size() << " parties:\n" << endl;
    for (auto &party: electionParties)
    {
        party.displayParty();
    }

    cout.width(80); cout << left << "" << "=== ELECTORATES ===" << endl;
    for(int i = 0; i < electionElectorates.size(); i++)
    {
        electionCandidates(i);
    }
}

void Election::electionCandidates(int electionC)
{
    electionElectorates[electionC].displayArea();
    cout << "Candidates: " << endl;

    for(auto party : electionParties)
    {
        party.getCandidatesInfo(electionElectorates[electionC]).displayCandidateCharacteristics();
    }
}

void Election::budgetReport()
{
    cout.width(20); cout << left << "Party Name";
    cout.width(20); cout << left << "Initial funds";
    cout.width(20); cout << left << "Expenditure";
    cout.width(20); cout << left << "After Expenditure";
    cout.width(20); cout << left << "After Daily Intake" << endl;

    cout << "--------------------------------------------------------------------------------------------------" << endl;

    for(auto &parties: electionParties)
    {
        cout.width(20); cout << left << parties.getPartyName();
        cout.width(20); cout << left << parties.getPartyBudget();
        cout.width(20); cout << left << parties.getPartyBudget()/2;
        parties.changePartyBudget(-parties.getPartyBudget()/2);
        cout.width(20); cout << left << parties.getPartyBudget();
        cout.width(20); cout << left << parties.getPartyBudget();
        cout << "\n";
    }

    cout << "\n";
}

void Election::electionCandidateEvent(int e, string character)
{
    electionElectorates[e].displayArea();

    cout << "Candidates: " << endl;

    for(auto candidate: electionParties)
    {
        candidate.getCandidatesInfo(electionElectorates[e]).displayCandidateCharacteristics();
    }

    Candidate *highestPerformanceCandidate = &electionParties[0].getCandidatesInfo(electionElectorates[e]);
    int characteristicsValues = highestPerformanceCandidate->getCharateristics(character);

    for(auto &characteristics : electionParties)
    {
        if(characteristicsValues < characteristics.getCandidatesInfo(electionElectorates[e]).getCharateristics(character))
        {
            highestPerformanceCandidate = &characteristics.getCandidatesInfo(electionElectorates[e]);
            characteristicsValues = characteristics.getCandidatesInfo(electionElectorates[e]).getCharateristics(character);
        }
    }

    cout << "Best Performance: " << highestPerformanceCandidate->getEntityName() << " - " << character << ": " << characteristicsValues << endl;
    cout << highestPerformanceCandidate->getEntityName() << " has gained +30 POPULARITY" << endl;
    highestPerformanceCandidate->updateCharacteristics("POPULARITY", 30);
    highestPerformanceCandidate->displayCandidateCharacteristics();
    cout << endl;
}

void Election::voting()
{
    cout.width(78); cout << left << "" << "=== VOTING HAS BEGUN ===" << endl;

    for(auto i: electionElectorates)
    {
        votingOfElectorates(i);
    }

    cout << "All electorates have voted!\n" << endl;

    Party *winnerParty = &electionParties[0];
    int winningCount = electionParties[0].getPartyWinningCount();

    for (auto &party: electionParties)
    {
        cout << party.getPartyName() << " has won " << party.getPartyWinningCount() << " times." << endl;
    }
    cout << "\n";

    cout.width(80); cout << left << "" << "=== PARTIES' TOTAL VOTES ===" << endl;
    cout.width(20); cout << left << "Party";
    cout.width(20); cout << left << "Total Number of Votes" << endl;

    cout << "-----------------------------------------" << endl;

    int nosamTotalVotes = 0;
    for (auto &votes: electionParties)
    {
        nosamTotalVotes = nosamTotalVotes + votes.getPartyTotalVotes();
    }

    for (auto &votes: electionParties)
    {
        double percentage = (double) votes.getPartyTotalVotes() * 100 / nosamTotalVotes;
        cout.width(0); cout << left << "" << votes.getPartyName();
        cout.width(20); cout << left << "" << votes.getPartyTotalVotes();
        cout << endl;
    }

    cout << "\n";

    cout.width(80); cout << left << "" << "=== NEW GOVERNMENT ===" << endl;
    cout << "The party that represents the new government is: " << winnerParty->getPartyName() << endl;
    cout << winnerParty->getPartyLeaderInfo().getEntityName() << " is the new president" << endl;
}

void Election::votingOfElectorates(Electorate &elec)
{
    cout << elec.getAreaName() << "' votes:" << endl;

    cout.width(40); cout << left << "Cluster";
    cout.width(20); cout << left << "Vote For";
    cout.width(20); cout << left << "Vote Value";
    cout.width(20); cout << left << "Votes" << endl;

    cout << "-------------------------------------------------------------------------------------" << endl;

    double holder = numOfVotes(elec, elec.getCluster()[0], electionParties[0]);
    Party *party = &electionParties[0];

    for (auto &i: elec.getCluster())
    {
        cout.width(20); cout << left << i.getEntityName() + " (Population: " + to_string(i.getPopulation()) + ")";
        for(auto &j: electionParties)
        {
            if(holder < numOfVotes(elec, i, j))
            {
                holder = numOfVotes(elec, i, j);
                party = &j;
            }
        }

        cout.width(12); cout << left << "" << party->getCandidatesInfo(elec).getEntityName();
        party->getCandidatesInfo(elec).updateCandidateVotes(i.getPopulation());
        cout.width(17); cout << left << "" << holder;
        cout.width(12); cout << left << "" << i.getPopulation() << endl;

    }
    cout << "\n";

    cout << "Total votes: " << endl;

    int winnerVote = electionParties[0].getCandidatesInfo(elec).getCandidateVotes();
    Candidate winner = electionParties[0].getCandidatesInfo(elec);
    Party *winnerParty = &electionParties[0];
    for(auto &i: electionParties){
        cout << i.getCandidatesInfo(elec).getEntityName() << ": " << i.getCandidatesInfo(elec).getCandidateVotes();
        if(winnerVote < i.getCandidatesInfo(elec).getCandidateVotes()){
            winnerVote = i.getCandidatesInfo(elec).getCandidateVotes();
            winner = i.getCandidatesInfo(elec);
            winnerParty = &i;
        }
        cout << endl;
    }

    cout << "\n";

    winnerParty->increaseWinningCount();
    cout << winner.getEntityName() + " has won the election in " + elec.getAreaName() + " scoring " + to_string(winnerVote) + " votes ";
    cout << "making " + winnerParty->getPartyName() + " win the election in " + elec.getAreaName() << ".\n" << endl;
}

double Election::numOfVotes(Electorate electorate, Group group, Party party)
{
    vector<Stance> groupStance = group.getStanceValues();
    vector<Stance> candidateStance = party.getCandidatesInfo(electorate).getStanceValues();

    double numOfVotes = 0;

    for(int i = 0; i < IssueType.size(); i++)
    {
        numOfVotes = numOfVotes - groupStance[i].calculation(candidateStance[i]);
    }

    numOfVotes = numOfVotes + (party.getCandidatesInfo(electorate).totalCharacteristicsValue() / 100);
    numOfVotes = numOfVotes + (party.getPartyLeaderInfo().totalCharacteristicsValue() / 100);

    return numOfVotes;
}

Electorate& Election::randElectorate()
{
    int electorate = random(0, electionElectorates.size() - 1);
    return electionElectorates[electorate];
}

Leader& Election::randLeader()
{
    int party = random(0, electionParties.size() - 1);
    return electionParties[party].getPartyLeaderInfo();
}

Candidate& Election::randCandidate()
{
    int party = random(0, electionParties.size() - 1);
    int electorate = random(0, electionElectorates.size() - 1);

    return electionParties[party].getCandidatesInfo(electionElectorates[electorate]);
}
