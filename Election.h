#ifndef ELECTION_H_INCLUDED
#define ELECTION_H_INCLUDED

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

extern vector<string> IssueType;
extern vector<string> EventType;
extern vector<string> Characteristic;

void displayStrVec(vector<string>);
bool inVec(string, vector<string>);

int random(int, int);
double random(double, double);

string ltrim(const string &);
string rtrim(const string &);
string trim(const string &);

struct StanceRange{
    int s_min;
    int s_max;
    int a_min;
    int a_max;

    string toString(){
        return to_string(s_min) + "-" + to_string(s_max) + "/" + to_string(a_min) + "-" + to_string(a_max);
    }
};
typedef struct StanceRange STANCERANGE;

class Issue
{
    private:
        string issueCode;
        string issueName;
        string issueType;
        string issueStatement;

    public:
        Issue();
        Issue(string, string, string, string);

        string getIssueCode();
        string getIssueName();
        string getIssueType();
        string getIssueStatement();

        void setIssueCode(string);
        void setIssueName(string);
        void setIssueType(string);
        void setIssueStatement(string);

        string displayIssue();
        string displayEventRelatedIssue();
};

class Event
{
    private:
        string eventCode;
        string eventContent;
        string eventType;
        vector<string> impactChar;
        int eventImpactNo;
        Issue relatedIssue;

    public:
        Event();
        Event(string, string, string, vector<string>, int, Issue);

        string getEventCode();
        string getEventContent();
        string getEventType();
        vector<string> getImpactChar();
        int getEventImpactNo();
        Issue getRelatedIssue();

        void displayEvent();
};

class Stance
{
    private:
        string issueType;
        int stanceSignificance;
        int stanceApproach;

    public:
        Stance();
        Stance(string);
        Stance(string, STANCERANGE);
        Stance(string, int, int);

        int getStanceSignificance();
        int getStanceApproach();
        string getIssueType();

        void setStanceSignificance(int);
        void setStanceApproach(int);

        string displayPartialStance();

        double calculation(Stance &);

};

class Human
{
    protected:
        map<string, int> characteristics;

    public:
        Human();
        Human(map<string, int>);

        int getCharateristics(string);

        void updateCharacteristics(string, int);

        void displayCharacteristics();

        int totalCharacteristicsValue();
};

class Entity
{
    protected:
        string entityName;
        vector<Stance> stanceValues;

    public:
        string getEntityName();
        vector<Stance> getStanceValues();

        void setStance(vector<Stance>);
        void changeStance(string, int, int);

        void displayStance();
};

class Group: public Entity
{
    private:
        int population;

    public:
        Group(string, vector<Stance>, int);

        int getPopulation();

        void displayGroupStanceValues();
};

class Leader: public Human, public Entity
{
    private:
        string leaderID;

    public:
        Leader();
        Leader(string, string, vector<Stance>, map<string, int>);
        Leader(const Leader &);

        void displayLeader();
        void displayLeaderStances();
        void displayLeaderCharacteristics();
};

class Candidate: public Human, public Entity
{
    private:
        string candidateID;
        int totalCandidateVotes = 0;

    public:
        Candidate();
        Candidate(string, string, vector<Stance>, map<string, int>);
        Candidate(const Candidate &);

        string getCandidateID();
        int getCandidateVotes();

        void updateCandidateVotes(int);
        void displayCandidate();
        void displayCandidateStances();
        void displayCandidateCharacteristics();
};

class ManagerialTeam: public Entity
{
    private:
        int teamEventImpact;

    public:
        ManagerialTeam();
        ManagerialTeam(string, vector<Stance>, int);
        ManagerialTeam(const ManagerialTeam &);

        int getTeamEventImpact();

        void setEventImpact(int);
        void displayTeamEventImpact();
        void displayTeamStances();
};

class Electorate
{
    private:
        string areaName;
        vector<Group> clusters;
        int areaPopulation;

    public:
        Electorate(string, vector<Group>);

        bool operator < (const Electorate&) const;

        string getAreaName();
        vector<Group> getCluster();
        int getAreaPopulation();

        void changeAreaStanceValues(string, int, int);
        void displayArea();
};

class Party
{
    private:
        string partyName;

        Leader leader;
        map<Electorate, Candidate> candidates;
        ManagerialTeam partyTeam;

        vector<StanceRange> partyRange;

        double partyBudget;
        int partyTotalVotes = 0;
        int winningCount = 0;

    public:
        Party(string, Leader, map<Electorate, Candidate>, ManagerialTeam, vector<StanceRange>, double);

        string getPartyName();

        Leader& getPartyLeaderInfo();
        ManagerialTeam getPartyTeamInfo();
        Candidate& getCandidatesInfo(Electorate);
        vector<StanceRange> getPartyRange();

        double getPartyBudget();
        int getPartyTotalVotes();
        int getPartyWinningCount();

        void increaseWinningCount();
        void updatePartyTotalVotes();
        void changePartyBudget(double);
        void displayParty();
};

class Election
{
    private:
        int partyNum;
        int electorateNum;
        vector<Issue> electionIssues;
        vector<Event> electionEvents;
        vector<Electorate> electionElectorates;
        vector<Party> electionParties;

    public:
        Election();
        Election(int, int, vector<Issue>, vector<Event>, vector<Electorate>, vector<Party>);

        int getPartyNum();
        int getElectorateNum();
        vector<Issue>& getElectionIssues();
        vector<Event>& getElectionEvents();
        vector<Electorate>& getElectionElectorates();
        vector<Party>& getElectionParties();

        void electionReport();
        void budgetReport();
        void electionCandidates(int);
        void electionCandidateEvent(int, string);
        void voting();
        void votingOfElectorates(Electorate &);

        double numOfVotes(Electorate, Group, Party);

        Electorate& randElectorate();
        Leader& randLeader();
        Candidate& randCandidate();
};

class Campaign
{
    private:
        int duration;
        int currentDate;
        Election election;

    public:
        Campaign(int, Election);
        void run();
        void runLocal();
        void runNation();
};

class ElectionGenerator
{
    private:
        int partyNum = 3;
        int electorateNum;
        vector<Issue> issues;
        vector<Event> events;
        vector<Electorate> electorates;
        vector<Party> parties;

    public:
        ElectionGenerator(int);
        void report();
        Election generateElection();

        void OpenIssues();
        void OpenIssueType();
        void OpenEvents();
        void OpenEventType();
        void OpenCharacteristic();
        void OpenElectorates();
        void OpenParties();

        Issue generateRelatedIssue(string);
        Group generateGroup(string);
        Leader generateLeader(string, vector<STANCERANGE>);
        Candidate generateCandidate(string, vector<STANCERANGE>);
        ManagerialTeam generateManagerialTeam(string, vector<STANCERANGE>);
        vector<string> generateImpactCharacteristic(string);
        vector<STANCERANGE> generatePartyRange(string);
        vector<Stance> generateStanceByRange(vector<STANCERANGE>);
};

#endif // ELECTION_H_INCLUDED
