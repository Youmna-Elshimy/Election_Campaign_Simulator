#include "Election.h"

Human::Human() {};

Human::Human(map<string, int> _characteristics)
{
    characteristics = _characteristics;
}

int Human::getCharateristics(string character)
{
    return characteristics[character];
}

void Human::updateCharacteristics(string character, int value)
{
    characteristics[character] = value + characteristics[character];
}

void Human::displayCharacteristics()
{
    cout << "His/Her Characteristics with Values:" << endl;
    for (auto character = characteristics.begin(); character != characteristics.end(); character++)
    {
        cout << "\t\t\t" << character->first << ": " << character->second << endl;
    }
    cout << "\n";
}

int Human::totalCharacteristicsValue()
{
    int total;
    for (auto character = characteristics.begin(); character != characteristics.end(); character++)
    {
        if(character->first == "SCANDAL_EXP")
        {
            total = total - character->second;
        }
        else
        {
            total = total + character->second;
        }
    }
    return total;
}
