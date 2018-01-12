#include "Condition.h"

Condition::Condition()
{
}

Condition::~Condition()
{
}

Condition::Condition(std::string con) {

	//parsing and assigning variables after reading in
	const char* str = con.c_str();
	bool opFound = false;
	int opLocation;
	std::string left, right = "";

	for (int i = 0; i < con.length() && !opFound; i++) {

		//if(str[i]=)

		switch (str[i]) {
		case '>':
		case '<':
		case '=':
			op = str[i];
			opFound = true;
			opLocation = i;
			break;
		}
	}

	for (int i = 0; i < opLocation; i++) {
		left += str[i];
	}
	for (int i = opLocation + 1; i < con.length(); i++) {
		right += str[i];
	}

	lhs = Expression(left);
	rhs = Expression(right);
}

bool Condition::operator ==(const bool & rhs) {

	//int left, right;
	bool value;


	switch (op) {
	case '>':
		value = this->lhs > this->rhs;
		break;
	case '<':
		value = this->lhs < this->rhs;
		break;
	case '=':
		value = this->lhs == this->rhs;
		break;
	}

	return value;
}

void Condition::insert(Variable lastO, int allO_W, int allO_x, int allO_y, int allO_z, int allO_a, int allO_b, int allO_c, int iterations, float score) {
	/*this->lastO = &lastO;
	this->allO_W = &allO_W;
	this->allO_x = &allO_x;
	this->allO_y = &allO_y;
	this->allO_z = &allO_z;
	this->iterations = &iterations;
	this->score = &score;*/
	lhs.insert(lastO, allO_W, allO_x, allO_y, allO_z, allO_a, allO_b, allO_c, iterations, score);
	rhs.insert(lastO, allO_W, allO_x, allO_y, allO_z, allO_a, allO_b, allO_c, iterations, score);
}

