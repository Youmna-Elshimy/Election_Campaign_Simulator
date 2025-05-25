#include "Election.h"

Campaign::Campaign(int _time, Election _election)
{
    duration = _time;
    currentDate = _time;
    election = _election;
}

void Campaign::run()
{
    cout.width(80); cout << left << "" << "CAMPAIGN" << endl;
    cout.width(80); cout << left << "" << "********" << endl;

    for (; currentDate != 0; currentDate--)
    {
        cout.width(65); cout << left << "" << "=== NUMBER OF DAYS UNTIL ELECTION: " << currentDate << " ===\n" << endl;

        cout << "Budget Report:" << endl;
        election.budgetReport();

        int eventNumHeldToday = random(0,2);

        if(eventNumHeldToday == 0)
        {
            cout << "There will be no events held today" << endl << endl;
        }
        else
        {
            int eventNumber = random(1,2);

            if(eventNumber == 1)
            {
                runNation();
            }
            else if(eventNumber == 2)
            {
                runLocal();
            }
        }
    }

    cout << endl;

    election.electionReport();

    cout << endl;

    cout.width(80); cout << left << "" << "DAY OF THE ELECTIONS" << endl;
    cout.width(80); cout << left << "" << "********************" << endl;

    election.voting();
}

void Campaign::runLocal()
{
    int randomEvent = random(5, election.getElectionEvents().size() - 1);
    int randomElectorate = random(0, election.getElectionElectorates().size() - 1);

    election.getElectionEvents()[randomEvent].displayEvent();

    cout << "\n\nEvent Place: " << election.getElectionElectorates()[randomElectorate].getAreaName() << endl << endl;

    string issueType = election.getElectionEvents()[randomEvent].getRelatedIssue().getIssueType();
    election.getElectionElectorates()[randomElectorate].changeAreaStanceValues(issueType, 10, 10);
    election.electionCandidateEvent(randomElectorate, issueType);
}

void Campaign::runNation()
{
    int randomEvent = random(0, 4);

    Event event = election.getElectionEvents()[randomEvent];
    event.displayEvent();

    cout << endl;

    if(event.getEventType() == "DEBATE")
    {
        Party *debate = &(election.getElectionParties()[0]);
        int debateValue = debate->getPartyLeaderInfo().getCharateristics("DEBATE_EXP");

        for(auto &party: election.getElectionParties())
        {
            cout << party.getPartyLeaderInfo().getEntityName() << " has " << party.getPartyLeaderInfo().getCharateristics("DEBATE_EXP") << " DEBATE_EXP." << endl;
        }

        cout << endl << debate->getPartyLeaderInfo().getEntityName() << " has won the debate for " << debate->getPartyName() << endl;
        cout << "+30 DEBATE_EXP, +30 POPULARITY" << endl;

        debate->getPartyLeaderInfo().updateCharacteristics("DEBATE_EXP", 30);
        debate->getPartyLeaderInfo().updateCharacteristics("POPULARITY", 30);
        debate->getPartyLeaderInfo().displayCharacteristics();
    }

    else if(event.getEventType() == "CANDIDATE_RELATED")
    {
        if (event.getEventCode() == "CANDIDATE_RELATED_1")
        {
            cout << "CANDIDATE RELATED EVENT 1" << endl;
            cout << "+30 POPULARITY TO A RANDOM CANDIDATE" << endl;

            Candidate *candidate = &election.randCandidate();
            candidate->updateCharacteristics("POPULARITY", 30);
            candidate->displayCandidateCharacteristics();
        }

        else if(event.getEventCode() == "CANDIDATE_RELATED_2")
        {
            cout << "CANDIDATE RELATED EVENT 2" << endl;
            cout << "A RANDOM CANDIDATE HAS GAINED +30 SCANDAL" << endl;

            Candidate *candidate = &election.randCandidate();
            candidate->updateCharacteristics("SCANDAL_EXP", 30);
            candidate->displayCandidateCharacteristics();
        }
    }

    else if(event.getEventType() == "LEADER_RELATED")
    {
        if (event.getEventCode() == "LEADER_RELATED_1")
        {
            cout << "LEADER RELATED EVENT 1" << endl;
            cout << "LEADER HAS GAINED +30 CONNECTION" << endl;

            Leader *leader = &election.randLeader();
            leader->updateCharacteristics("CONNECTION", 30);
            leader->displayLeaderCharacteristics();
        }

        else if(event.getEventCode() == "LEADER_RELATED_2")
        {
            cout << "LEADER RELATED EVENT 2" << endl;
            cout << "LEADER HAS GAINED +30 SCANDAL" << endl;

            Leader *leader = &election.randLeader();
            leader->updateCharacteristics("SCANDAL_EXP", 30);
            leader->displayLeaderCharacteristics();
        }
    }
}
