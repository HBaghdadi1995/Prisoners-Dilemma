
#pragma once
#include "KeyWord.h"
#include "Condition.h"
#include <random>
#include <string>
#include "Parse.h"
class Command
{
public:
	Command();
	Command(std::string);
	~Command();

	void run(int &location);  //executes the command

	void insert(Variable lastO, int allO_W, int allO_x, int allO_y, int allO_z, int allO_a, int allO_b, int allO_c, int iterations, float score); //sends the variables down so that they can reach the expression

	keyword getDecision();
private:
	//int line = 0;
	keyword key; //The very first word in the command line that decides what this line does
	Condition con; //only applies with "if" statements
	vector<Command> nextCommand; //If more than one command exists on a line, applicable with "if" statements
	int target; //only aplies with the "GOTO" keyword, and tells the compiler which command to visit next
	keyword decision = NONE; //the decision, should be left at none, unless a decision has been come to and the code execution ends


};