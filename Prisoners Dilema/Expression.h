#pragma once
#include "Variable.h"
#include "Parse.h"
#include <string>
#include <vector>

using namespace std;
class Expression
{
public:
	Expression();
	//Expression(Variable, int, int, int, int, int, int);
	Expression(std::string exp);
	~Expression();

	

	int getValue() const; //get the value of all variable values operated on each other
	Variable getVariableValue() const; //get the variable stored in this expression
	void insert(Variable lastO, int allO_W, int allO_x, int allO_y, int allO_z, int allO_a, int allO_b, int allO_c, int iterations, float score); //update all variables

	bool operator<(const Expression &rhs) {
		return this->getValue() < rhs.getValue();
	}

	bool operator>(const Expression &rhs) {
		return this->getValue() > rhs.getValue();
	}

	bool operator==(const Expression &rhs) {
		if (isInt) {
			return this->getValue() == rhs.getValue();
		}
		else {
			return this->getVariableValue() == rhs.getVariableValue();
		}
	}

	Variable getVariable(const char*); //convert a string to it's variable

	bool isItint();//does the variable represent an int?

private:

	vector<Variable> vars;
	int varNumber;
	vector<char> ops;
	vector<int> ints;


	int allO_W, allO_x, allO_y, allO_z, allO_a, allO_b, allO_c, iterations, score;
	Variable  lastO;

	bool isInt;
};