#include "Election.h"

ElectionGenerator::ElectionGenerator(int _electorateNum)
{
    electorateNum = _electorateNum;
}

void ElectionGenerator::report()
{
    cout << "\n";
    cout.width(80); cout << left << "" << "=== ISSUE TYPE ==="  << endl;
    displayStrVec(IssueType);
    cout << "\n";

    cout.width(80); cout << left << "" << "=== EVENT TYPE ==="  << endl;
    displayStrVec(EventType);
    cout << "\n";

    cout.width(80); cout << left << "" << "=== CHARACTERISTICS ==="  << endl;
    displayStrVec(Characteristic);
    cout << "\n";

    cout.width(80); cout << left << "" << "=== ISSUES ==="  << endl;
    cout << "There are " << issues.size() << " main issues affecting the society:\n" << endl;

    for (auto &issue: issues)
    {
        cout << issue.displayIssue() << endl << endl;
    }

    cout.width(80); cout << left << "" << "=== EVENTS ===" << endl;
    cout << "There are " << events.size() << " events:\n" << endl;
    for (auto &event: events)
    {
        event.displayEvent();
        cout << endl << endl;
    }

    cout.width(80); cout << left << "" << "=== PARTIES ===" << endl;
    cout << "There are " << parties.size() << " parties: " << endl << endl;
    for (auto &party: parties)
    {
        party.displayParty();
        cout << endl << endl;
    }

    cout.width(80); cout << left << "" << "=== ELECTORATES ===" << endl;
    cout << "There are " << electorates.size() << " electorates:\n" << endl;
    for (auto &electorate: electorates)
    {
        electorate.displayArea();
        cout << endl << endl;
    }
}

Election ElectionGenerator::generateElection()
{
    Election election(partyNum, electorateNum, issues, events, electorates, parties);
    return election;
}

void ElectionGenerator::OpenIssues()
{
    string line, code, name, type, statement;
    string filename = "Issues.txt";

    ifstream inputFile(filename);

    if(inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            stringstream stream(line);

            getline(stream, code, ';');
            code = trim(code);

            getline(stream, name, ';');
            name = trim(name);

            getline(stream, statement, ';');
            statement = trim(statement);

            getline(stream, type);
            type= trim(type);
            if(inVec(type, IssueType) == false)
            {
                break;
            }

            Issue i(code, name, statement, type);

            issues.push_back(i);
        }
        inputFile.close();
    }
    else
    {
        cout << filename << " cannot be opened!" << endl;
        exit(EXIT_FAILURE);
    }
}

void ElectionGenerator::OpenIssueType()
{
    string line;
    string filename = "IssueType.txt";

    ifstream inputFile(filename);

    if(inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            IssueType.push_back(line);
        }
        inputFile.close();
    }
    else
    {
        cout << filename << " cannot be opened!" << endl;
        exit(EXIT_FAILURE);
    }
}

void ElectionGenerator::OpenEvents()
{
    string line, code, content, type, imp, impChara, relIssues;
    int impact;
    vector<string> impactCharacteristic;
    Issue relatedIssue;

    string filename = "Events.txt";

    ifstream inputFile(filename);

    if(inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            stringstream stream(line);

            getline(stream, relIssues, ';');
            relatedIssue = generateRelatedIssue(relIssues);

            getline(stream, code, ';');
            code = trim(code);

            getline(stream, content, ';');
            content = trim(content);

            getline(stream, type, ';');
            type = trim(type);
            if(inVec(type, EventType)==false)
            {
                break;
            }

            getline(stream, imp, ';');
            impact = stoi(imp);

            getline(stream, impChara);
            impactCharacteristic = generateImpactCharacteristic(impChara);

            Event event1(code, content, type, impactCharacteristic, impact, relatedIssue);

            events.push_back(event1);
        }
        inputFile.close();
    }
    else
    {
        cout << filename << " cannot be opened!" << endl;
        exit(EXIT_FAILURE);
    }
}

void ElectionGenerator::OpenEventType()
{
    string line;

    string filename = "EventType.txt";

    ifstream inputFile(filename);

    if(inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            EventType.push_back(line);
        }
        inputFile.close();
    }
    else
    {
        cout << filename << " cannot be opened!" << endl;
        exit(EXIT_FAILURE);
    }
}

void ElectionGenerator::OpenCharacteristic()
{
    string line;

    string filename = "Characteristic.txt";

    ifstream inputFile(filename);

    if(inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            Characteristic.push_back(line);
        }
        inputFile.close();
    }
    else
    {
        cout << filename << " cannot be opened!" << endl;
        exit(EXIT_FAILURE);
    }
}

void ElectionGenerator::OpenElectorates()
{
    string line, group, name;
    vector<Group> groups;

    string filename = "Electorates.txt";
    ifstream inputFile(filename);

    if(inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            stringstream stream(line);

            getline(stream, name, ':');
            name = trim(name);

            while(getline(stream, group, '|'))
            {
                Group g = generateGroup(group);
                groups.push_back(g);
            }

            Electorate electorate(name, groups);
            electorates.push_back(electorate);
            if(electorates.size() == electorateNum)
            {
                break;
            }
        }
        inputFile.close();
    }
    else
    {
        cout << filename << " cannot be opened!" << endl;
        exit(EXIT_FAILURE);
    }
}

void ElectionGenerator::OpenParties()
{
    for(int i = 1; i <= partyNum; i ++)
    {

        string filename = "Party" + to_string(i) + ".txt";

        string name, lead, candid, team, pRange, bud;
        map<Electorate,Candidate> candidates;
        vector<STANCERANGE> partyRange;
        double budget;

        ifstream inputFile(filename);

        if(inputFile.is_open())
        {
            getline(inputFile, name);

            getline(inputFile, pRange);
            partyRange = generatePartyRange(pRange);

            getline(inputFile, team);
            ManagerialTeam mngTeam = generateManagerialTeam(team, partyRange);

            getline(inputFile, bud);
            budget = stod(bud);

            getline(inputFile, lead);
            Leader leader = generateLeader(lead, partyRange);

            for (auto &i: electorates)
            {
                getline(inputFile, candid);
                Candidate candidate = generateCandidate(candid, partyRange);
                candidates.emplace(i, candidate);
            }

            Party party(name, leader, candidates, mngTeam, partyRange, budget);

            parties.push_back(party);

            inputFile.close();
        }
        else
        {
            cout << filename << " cannot be opened!" << endl;
            exit(EXIT_FAILURE);
        }
    }
}

Issue ElectionGenerator::generateRelatedIssue(string relatedIssue)
{
    relatedIssue = trim(relatedIssue);

    for(auto issue: issues)
    {
        if (issue.getIssueCode() == relatedIssue)
        {
            return issue;
        }
    }

    return Issue();
}

vector<string> ElectionGenerator::generateImpactCharacteristic(string impChar)
{
    impChar = trim(impChar);
    stringstream stream(impChar);

    vector<string> impactCharacteristic;

    string charac;

    while(getline(stream, charac, '|'))
    {
        charac = trim(charac);
        if(inVec(charac, Characteristic) == true)
        {
            impactCharacteristic.push_back(charac);
        }
    }
    return impactCharacteristic;
}

Group ElectionGenerator::generateGroup(string g)
{
    g = trim(g);

    string name, pop;
    int population;
    vector<Stance> stanceValue;

    stringstream stream(g);

    getline(stream, name, ',');
    name = trim(name);

    getline(stream, pop, ',');
    population = stoi(pop);

    for (auto &issue: IssueType)
    {
        Stance s(issue);
        stanceValue.push_back(issue);
    }

    Group group(name, stanceValue, population);

    return group;
}

Leader ElectionGenerator::generateLeader(string lead, vector<STANCERANGE> partyRange)
{
    lead = trim(lead);
    stringstream stream(lead);

    string id, name, values;
    vector<Stance> stanceValue = generateStanceByRange(partyRange);
    map<string, int> characteristicValue;
    int value;

    getline(stream, id, ',');
    id = trim(id);

    getline(stream, name, ',');
    name = trim(name);

    for (auto &i: Characteristic)
    {
        getline(stream, values, ',');
        value = stoi(values);
        characteristicValue[i] = value;
    }

    Leader leader(id, name, stanceValue, characteristicValue);
    return leader;
}

Candidate ElectionGenerator::generateCandidate(string candidateS, vector<STANCERANGE> partyRange)
{
    candidateS = trim(candidateS);
    stringstream stream(candidateS);

    string id, name;
    vector<Stance> stanceValue = generateStanceByRange(partyRange);
    map<string, int> characteristicValue;

    string charaS, valueS;
    int value;

    getline(stream, id, ',');
    id = trim(id);

    getline(stream, name, ',');
    name = trim(name);

    for (auto &i: Characteristic){
        getline(stream, valueS, ',');
        value = stoi(valueS);
        characteristicValue[i] = value;
    }

    Candidate c(id, name, stanceValue, characteristicValue);
    return c;
}

ManagerialTeam ElectionGenerator::generateManagerialTeam(string team, vector<STANCERANGE> partyRange)
{
    team = trim(team);
    stringstream stream(team);

    string name;
    vector<Stance> stanceValue = generateStanceByRange(partyRange);
    int skill;

    string skills;

    getline(stream, name, ',');
    name = trim(name);

    getline(stream, skills);
    skill = stoi(skills);

    ManagerialTeam team1(name, stanceValue, skill);
    return team1;
}

vector<STANCERANGE> ElectionGenerator::generatePartyRange(string rang)
{
    rang = trim(rang);
    stringstream stream(rang);

    vector<STANCERANGE> partyRange;

    string rang2;
    int s_min, s_max, a_min, a_max;
    string stance_min, stance_max, a_minS, a_maxS;

    while(getline(stream, rang2, '|'))
    {
        stringstream stream2(rang2);
        getline(stream2,stance_min,',');
        s_min = stoi(stance_min);
        getline(stream2,stance_max,';');
        s_max = stoi(stance_max);
        getline(stream2,a_minS,',');
        a_min = stoi(a_minS);
        getline(stream2,a_maxS);
        a_max = stoi(a_maxS);

        STANCERANGE stance;
        stance.s_min = s_min;
        stance.s_max = s_max;
        stance.a_min = a_min;
        stance.a_max = a_max;

        partyRange.push_back(stance);
    }

    return partyRange;
}

vector<Stance> ElectionGenerator::generateStanceByRange(vector<STANCERANGE> partyRange)
{
    vector<Stance> stanceValue;
    int issueCode = 0;
    for (auto &rang: partyRange)
    {
        Stance stance(IssueType[issueCode], rang);
        issueCode++;
        stanceValue.push_back(stance);
    }

    return stanceValue;
}
