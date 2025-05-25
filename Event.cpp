#include "Election.h"

Event::Event(){};

Event::Event(string _code, string _content, string _type, vector<string> _impactChar, int _impactNo, Issue _relatedIssue)
{
    eventCode = _code;
    eventContent = _content;
    eventType = _type;
    impactChar = _impactChar;
    eventImpactNo = _impactNo;
    relatedIssue = _relatedIssue;
}

string Event::getEventCode()
{
    return eventCode;
}

string Event::getEventContent()
{
    return eventContent;
}

string Event::getEventType()
{
    return eventType;
}

vector<string> Event::getImpactChar()
{
    return impactChar;
}

int Event::getEventImpactNo()
{
    return eventImpactNo;
}

Issue Event::getRelatedIssue()
{
    return relatedIssue;
}

void Event::displayEvent()
{
    cout << "Event Code: " << eventCode << endl;
    cout << "Event Content: " << eventContent << endl;
    cout << "Event Type: " << eventType << endl;
    cout << "Event Impact: " << eventImpactNo << endl;
    cout << "Event Impact Characteristic: ";
    displayStrVec(impactChar);
    cout << "Event Related Issue: " << relatedIssue.displayEventRelatedIssue();
}
