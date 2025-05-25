#include "Election.h"

void displayStrVec(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if(i == vec.size() - 1)
        {
            cout << vec[i];
        }
        else
        {
            cout << vec[i] << endl;
        }
    }
    cout << endl;
}

bool inVec(string s, vector<string> vec)
{
    for(auto i: vec)
    {
        if(i == s)
        {
            return true;
        }
    }

    return false;
}

int random(int min, int max)
{
    static bool first = true;
    if (first)
    {
        srand( time(NULL) );
        first = false;
    }
    return min + rand() % (( max + 1 ) - min);
}

double random(double x, double y)
{
    return ((y - x) * ((double)rand() / RAND_MAX)) + x;
}

const std::string space = " \n\r\t\f\v";

string ltrim(const string &strin)
{
    size_t start = strin.find_first_not_of(space);
    return (start == std::string::npos) ? "" : strin.substr(start);
}

string rtrim(const string &strin){
    size_t end = strin.find_last_not_of(space);
    return (end == std::string::npos) ? "" : strin.substr(0, end + 1);
}

string trim(const string &strin) {
    return rtrim(ltrim(strin));
}
