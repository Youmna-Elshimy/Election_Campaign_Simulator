# **Election Campaign Simulator**

## **Overview:**
The nation Nosam is on edge ahead of the upcoming election campaign. The leaders have presented their candidates and published manifestos detailing their plans for the country. You need to design and build a simulation of the campaign and subsequent election. The code compiles according to instructions provided in "Makefile,txt". Once the program is compiled into the executable APE, it runs as follows:
<br />
./APE n m
<br />
where n is the number of electorates in the nation, and m is the number of campaigning days before the election. The value of n should be in the range 1 to 10 inclusive. The value of m should be in the range 1 to 30 inclusive. On running, APE reports on each party (recall that there are three political parties). The report includes their stance values, the relevant details of their candidates, leader, and other significant figures. APE also reports on the state of the nation by giving details on the electorates including the stance distribution for each of the five issues.
- There are five issues of relevance, for the nation.
- Each party and electorate have different stances on each issue. The leaders and candidates share the same stance with their parties. Events may change stance values.
- Each political party has the following officials:
  1. One leader, not themselves a candidate for an electorate.
  2. One candidate for each electorate.
  3. One centralised campaign managerial team.
- Each political party has a range across each stance. Initial stance values is randomly generated and lie somewhere in that range.
- Both the leader and the candidates have popularity and at least one other characteristic. Both of them also have some impact.
- Each electorate has a political stance distribution rather than a specific stance.
- Each day of the campaign involves the candidates and leaders attempting to convince the electorates to support them.
- On every day of the campaign, for each electorate, there is a 40% chance of a local event:
  1. Debate.
  2. Candidate-related event. There are two different types of these events.
  3. Leader-related event. There are two different types of these events.
  4. Issues-related event. There are two different types of these events.
- Leaders, candidates, and the campaign managerial team have some impact on the outcomes.
- For each campaign day, APE reports the day, what has happened in each electorate, and the significant impacts that have occurred.
- Immediately before election day, a report is given on each party, including their stance values, the relevant details of their candidates and leaders. The state of the nation, including details on the electorates, population and stance distribution, is also reported on.
- For each candidate, the breakdown of votes is given and the winner is identified (the candidate with the most votes wins).
- Finally, a national summary, showing the number of electorates won by each party is given. If a party has won more than 50% of the electorates, they will form a government, and the party leader is assigned as the new leader for the country. If no party has won more than 50% of the electorates, APE declares a hung parliament.

## **UML Class Diagram:**
Please access the jpg file called “UML Diagram” for better visualization of the diagram.
<br />
![UML Diagram](https://github.com/user-attachments/assets/7d093f97-3961-4d02-a60b-cf9925d5f104)

## **Issues:**
There are 5 different issue types that have been identified. They are mentioned in a text file called “IssueType”. The issue types are:
<br />
![image](https://github.com/user-attachments/assets/f945db74-4430-4f12-a7bb-9273c2c611e7)
<br /><br />

There have also been 5 different issues that have been identified. They are mentioned in the UML class diagram in a class called “Issue” and in a text file called “Issues”. The issues are:
<br />
![image](https://github.com/user-attachments/assets/0f0d4432-e0ee-47b5-a51d-3edfb18c3913)
<br /><br />

In the text file, each attribute (the attributes in class Issue) for each issue is separated by a semicolon and the attributed represent the same order of attributes stated in the class Issue. For example:, the first line in the text file “Issues” is: 
<br />
*Issue 1; Poverty; ECONOMIC; Increase in the number of people suffering from poverty*
<br />
The line indicates the following:
- Code: Issue 1
- Name: Poverty
- Type: ECONOMIC
- Statement: Increase in the number of people suffering from poverty
The rest of the lines are ordered in the same way.

## **Political Parties:**
Three parties have been specified in 3 different text files: "Party1", "Party2" & "Party3". These text files contain the parties’ names, stances, managerial team’s name and teamEventImpact, leader’s name and id, and candidates’ names and ids as shown below:
<br />
![image](https://github.com/user-attachments/assets/5370148d-f8a0-43d0-8937-ecdb2b741f06)
![image](https://github.com/user-attachments/assets/59d96cf4-5032-473f-bd7e-5ab9e23967f6)
![image](https://github.com/user-attachments/assets/6c339f6a-594b-432d-b92a-558dad78ea38)

## **Electorates and Stances:**
There are 5 different stances as 5 different issues have been specified. The stances are described using significance and approach and are generated using random class according to the stance ranges that have been stated in the text file "Electorates":
<br />
![image](https://github.com/user-attachments/assets/fc50545f-90a4-4fb3-974d-a56a3e60cf41)

## **Calculating the Number of Votes for Candidate:**
- A formula has been used to calculate the votes of each candidate.
- The formula first starts by adding the values of each characteristic that the candidate and the leader have. Then it divides the outcome by 100.
- It moves on to calculate the difference between the candidate and electorate stances then it divides the outcome by 100.
- The final score is the sum of the outcomes in bullets 2&3.
- The candidate that has the highest score is the winner and its party is automatically becomes the winning party too.

## **Candidates’ Characteristics and their Qualitative Impacts:**
10 characteristics for each candidate have been identified in a text file called "Characteristic" as shown below:
<br />
![image](https://github.com/user-attachments/assets/ecf3861b-a8c8-4bac-bcd0-a9d2640c7894)

## **Characteristics of Other People Associated with the Political Parties and their Qualitative Impacts:**
The characteristics shown in the picture below that have the names of issue types in their names, represent the experience that the people need to deal with the issue. The other characteristics can bring in extra points for candidates and leaders that can help them increase their score and their possibilities to win.
<br />
![image](https://github.com/user-attachments/assets/48daf478-7619-4fea-87f1-7692b04b66dc)

## **Events and How They Qualitatively Depend on the Characteristics of Candidates and People Associated with the Political Parties:**
10 different events have been identified in a text file called Events. They are DEBATE, CANDIDATE_RELATED_1, CANDIDATE_RELATED_2, ISSUE_RELATED_I1, ISSUE_RELATED_I2, ISSUE_RELATED_I3, ISSUE_RELATED_I4 & ISSUE_RELATED_I5 as shown below: 
<br />
![image](https://github.com/user-attachments/assets/38453e8a-c6aa-4f5e-8fd6-2492d12fa862)
<br /><br />
The events have impact characteristics. These are the characteristics related to the events. Some of them allow the candidate to gain extra points as shown below: 
<br />
![image](https://github.com/user-attachments/assets/9cbce318-3e27-40b2-966a-da1d6c0e413f)






