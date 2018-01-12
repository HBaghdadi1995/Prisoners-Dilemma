#include "WriteSystem.h"

WriteSystem::WriteSystem()
{
}

WriteSystem::~WriteSystem()
{
}

void WriteSystem::generate(int lines, int files) {

	string input;

	for (int i = 0; i < files; i++) {
		input = "";
		string fileName = "../Strategies/Strategy_" + to_string(i) + ".txt";
		for (int i = 0; i < lines; i++) {
			input += getRandomString(i, lines);
		}
		printToFile(fileName, input);
	}
}

string  WriteSystem::getRandomString(int i, int lines) {
	string output = std::to_string(i + 1) + "0 ";
	if (i < lines - 1) {
		switch (rand() % 15)
		{
		case(0):
			output += "BETRAY\n";
			break;
		case(1):
			output += "SILENCE\n";
			break;
		case(2):
			output += "RANDOM\n";
			break;
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			output += generateIf(i, lines);
			break;
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
			output += generateGoto(i, lines);
			break;

		default:
			break;
		}
	}
	else {
		switch (rand() % 3)
		{
		case(0):
			output += "BETRAY\n";
			break;
		case(1):
			output += "SILENCE\n";
			break;
		case(2):
			output += "RANDOM\n";
			break;
		default:
			break;
		}

	}
	return output;
}

string WriteSystem::generateGoto(int i, int lines) {
	string output = "GOTO ";
	output += std::to_string((rand() % (lines - 1 - i) + i + 2) * 10) + "\n";
	return output;
}

string WriteSystem::generateIf(int i, int lines) {
	string output = "IF ";
	switch (rand() % 2) {
	case 0:
		output += generateLastOutcome();
		break;
	case 1:
		output += generateIntConditions();
		break;
	}
	output += generateGoto(i, lines);
	return output;
}

string WriteSystem::generateLastOutcome() {
	string output = "LASTOUTCOME = ";
	switch (rand() % 4) {
	case 0:
		output += "W ";
		break;
	case 1:
		output += "X ";
		break;
	case 2:
		output += "Y ";
		break;
	case 3:
		output += "Z ";
		break;
	}
	return output;
}

string WriteSystem::generateIntConditions() {
	string output = generateExpression();
	output += generateOp();
	output += generateExpression();
	return output;
}

string WriteSystem::generateExpression() {
	string output = generateVariable();
	for (int i = 0; i < (rand() % 10); i++) {
		output += generateAMOp();
		output += generateVariable();
	}
	return output;
}

string WriteSystem::generateOp() {
	string output = "";

	switch (rand() % 3)
	{
	case 0:
		output += "< ";
		break;
	case 1:
		output += "= ";
		break;
	case 2:
		output += "> ";
		break;
	default:
		break;
	}
	return output;
}

string WriteSystem::generateVariable() {
	string output = "";
	switch (rand() % 6) {
	case 0:
		output = "ALLOUTCOMES_W ";
		break;
	case 1:
		output = "ALLOUTCOMES_X ";
		break;
	case 2:
		output = "ALLOUTCOMES_Y ";
		break;
	case 3:
		output = "ALLOUTCOMES_Z ";
		break;
	case 4:
		output = "ITERATIONS ";
		break;
	case 5:
		output = "MYSCORE ";
		break;
	}
	return output;
}

string WriteSystem::generateAMOp() {
	string output = "";
	switch (rand() % 2) {
	case 0:
		output = "+ ";
		break;
	case 1:
		output = "- ";
		break;
	}
	return output;
}

void WriteSystem::printToFile(string fileName, string input) {
	ofstream myfile;
	myfile.open(fileName);
	myfile << input;
	myfile.close();
}