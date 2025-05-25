#include "Election.h"

vector<string> IssueType;
vector<string> EventType;
vector<string> Characteristic;

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
		cerr << "Please enter two number after the name of the executable file" << endl;
		return 1;
	}

	int electorates = atoi(argv[1]);
	int campDays = atoi(argv[2]);

	if ( electorates <= 0 || electorates > 10 )
	{
		cerr << "Please enter an electorate number that is from 1 to 10" << endl;
		return 1;
	}

	if ( campDays <= 0 || campDays > 30 )
	{
		cerr << "Please enter campaigning days number that is from 1 to 30" << endl;
		return 1;
	}

	cout.width(68); cout << left << " ";
	cout << left << "**********************************" << endl;

	cout.width(68); cout << left << " ";
	cout << "* An Election Campaign for Nosam *" << endl;

	cout.width(68); cout << left << " ";
	cout << left << "**********************************" << endl;

    ElectionGenerator gen(electorates);

    gen.OpenIssueType();
    gen.OpenEventType();
    gen.OpenCharacteristic();
    gen.OpenIssues();
    gen.OpenEvents();
    gen.OpenElectorates();
    gen.OpenParties();
    gen.report();

    Election election = gen.generateElection();

    Campaign campaign(campDays, election);

    campaign.run();

    return 0;
}
