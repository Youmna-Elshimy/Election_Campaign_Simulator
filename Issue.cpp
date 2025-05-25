#include "Election.h"

Issue::Issue():
    issueCode("None"),
    issueName("None"),
    issueType("None"),
    issueStatement("None"){}

Issue::Issue(string _code, string _name, string _statement, string _type)
{
    issueCode = _code;
    issueName = _name;
    issueType = _type;
    issueStatement = _statement;
}

string Issue::getIssueCode()
{
    return issueCode;
}

string Issue::getIssueName()
{
    return issueName;
}

string Issue::getIssueType()
{
    return issueType;
}

string Issue::getIssueStatement()
{
    return issueStatement;
}

void Issue::setIssueCode(string _code)
{
    issueCode = _code;
}

void Issue::setIssueName(string _name)
{
    issueName = _name;
}

void Issue::setIssueType(string _type)
{
    issueType = _type;
}

void Issue::setIssueStatement(string _statement)
{
    issueStatement = _statement;
}

string Issue::displayIssue()
{
    string issue;
    issue = issue + "Issue Code: " + issueCode;
    issue = issue + "\nIssue Name: " + issueName;
    issue = issue + "\nIssue Type: " + issueType;
    issue = issue + "\nIssue Statement: " + issueStatement;
    return issue;
}

string Issue::displayEventRelatedIssue()
{
    if(issueCode == "None")
        return "None";
    string issue;
    issue = issue + "\n\tIssue Code: " + issueCode;
    issue = issue + "\n\tIssue Name: " + issueName;
    issue = issue + "\n\tIssue Type: " + issueType;
    issue = issue + "\n\tIssue Statement: " + issueStatement;
    return issue;
}
