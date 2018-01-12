#include "Command.h"


void Command::run(int &location) {

	/*Switch statement to decide what to do based on the code*/

	switch (key) {
	case(IF):
		if (con == true) {
			nextCommand.begin()->run(location);
		};
		break;
	case(GOTO):
		location = target - 1;
		break;
	case(BETRAY):
		decision = BETRAY;
		break;
	case(SILENCE):
		decision = SILENCE;
		break;
	case(RANDOM):
		int state = rand() % 2;
		if (state) {
			decision = BETRAY;
		}
		else {
			decision = SILENCE;
		}
		break;
	}

}

Command::Command()
{
}

Command::Command(std::string com)
{
	//_ASSERT(_CrtCheckMemory());
	
	//parsing strings and setting keys based on the input

	char* context = NULL;

	Parse p = Parse(com, " ");
	string pch = p.next();
	if (!(strcmp(pch.c_str(), "IF") == 0 || strcmp(pch.c_str(), "GOTO") == 0 || strcmp(pch.c_str(), "BETRAY") == 0 || strcmp(pch.c_str(), "SILENCE") == 0) || strcmp(pch.c_str(), "RANDOM") == 0) {
		pch = p.next();
	}

	//_ASSERT(_CrtCheckMemory());

	if (strcmp(pch.c_str(), "IF") == 0) {
		std::string newCon, newCom = "";
		key = IF;
		pch = p.next();
		//_ASSERT(_CrtCheckMemory());
		newCon += pch;
		newCon += ' ';
		pch = p.next();
		//_ASSERT(_CrtCheckMemory());
		while (!(strcmp(pch.c_str(), "IF") == 0 || strcmp(pch.c_str(), "GOTO") == 0 || strcmp(pch.c_str(), "BETRAY") == 0 || strcmp(pch.c_str(), "SILENCE") == 0) || strcmp(pch.c_str(), "RANDOM") == 0) {
			newCon += pch;
			newCon += ' ';
			pch = p.next();
			//_ASSERT(_CrtCheckMemory());
		}
		con = Condition(newCon);
		while (pch != "") {
			newCom += pch;
			newCom += ' ';
			pch = p.next();
			//_ASSERT(_CrtCheckMemory());
		}

		nextCommand.push_back(Command(newCom));
		pch = "Nothing";
	}
	if (strcmp(pch.c_str(), "GOTO") == 0) {
		key = GOTO;
		pch = p.next();
		target = atoi(pch.c_str());
	}
	if (strcmp(pch.c_str(), "BETRAY") == 0) {
		key = BETRAY;
		pch = "Nothing";
	}
	if (strcmp(pch.c_str(), "SILENCE") == 0) {
		key = SILENCE;
		pch = "Nothing";
	}
	if (strcmp(pch.c_str(), "RANDOM") == 0) {
		key = RANDOM;
		pch = "Nothing";
	}
}

Command::~Command()
{
	/*if (nextCommand != nullptr) {
		delete nextCommand;
		nextCommand = nullptr;
	}*/
}

void Command::insert(Variable lastO, int allO_W, int allO_x, int allO_y, int allO_z, int allO_a, int allO_b, int allO_c, int iterations, float score) {
	//sending the values down to expressions
	if (key == IF) {
		con.insert(lastO, allO_W, allO_x, allO_y, allO_z, allO_a, allO_b, allO_c, iterations, score);
	}

}

keyword Command::getDecision() {
	//returns none if no decision set in this command, otherwise returning the decision
	return decision;
}