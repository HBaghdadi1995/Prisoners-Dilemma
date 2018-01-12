#pragma once
#include "Expression.h"
#include <string>

class Condition
{
public:
	Condition();
	Condition(std::string);
	~Condition();

	bool operator ==(const bool & rhs);

	//int allO_W, allO_x, allO_y, allO_z, iterations, score;
	Variable *lastO;

	void insert(Variable lastO, int allO_W, int allO_x, int allO_y, int allO_z, int allO_a, int allO_b, int allO_c, int iterations, float score); //sends the variables down so that they can reach the expression

private:
	Expression lhs, rhs; //The expressions left and right of the comparator
	char op; //The comparator in the middle
};