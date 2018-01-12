#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
class WriteSystem
{
public:
	WriteSystem();
	~WriteSystem();

	void generate(int lines, int files);
	string getRandomString(int i, int lines);

	string generateGoto(int i, int lines);
	string generateIf(int i, int lines);
	string generateLastOutcome();
	string generateIntConditions();
	string generateExpression();
	string generateOp();
	string generateVariable();
	string generateAMOp();
	void printToFile(string fileName, string input);
private:

};