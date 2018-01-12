#include "Expression.h"

Expression::Expression()
{
}

//Expression::Expression(Variable o, int w, int x, int y, int z, int i, int s) :
//	lastO(o), allO_W(w), allO_x(x), allO_y(y), allO_z(z), iterations(i), score(s)
//{
//
//}

Expression::~Expression()
{
}

Expression::Expression(std::string exp)
{
	//parse string and turn it into data
	Parse p = Parse(exp, " ");
	
	string pch = p.next();

	vars.push_back(getVariable(pch.c_str()));

	pch = p.next();

	for (int i = 0; pch != ""; i++) {
		char c = pch.at(0);
		ops.push_back(c);
		pch = p.next();
		vars.push_back(getVariable(pch.c_str()));
		pch = p.next();
	}
}

int Expression::getValue() const {
	//add all ints in variables togeather
	int *varValues = new int[vars.size()];
	int i = 0;
	int intsIterator = 0;

	vector<Variable> vars = this->vars;

	for (vector<Variable>::iterator it = vars.begin();it != vars.end(); it++) {
		switch (*it)
		{
		case ALLOUTCOMES_W:
			varValues[i] = allO_W;
			break;
		case ALLOUTCOMES_X:
			varValues[i] = allO_x;
			break;
		case ALLOUTCOMES_Y:
			varValues[i] = allO_y;
			break;
		case ALLOUTCOMES_Z:
			varValues[i] = allO_z;
			break;
		case ALLOUTCOMES_A:
			varValues[i] = allO_a;
			break;
		case ALLOUTCOMES_B:
			varValues[i] = allO_b;
			break;
		case ALLOUTCOMES_C:
			varValues[i] = allO_c;
			break;
		case ITERATIONS:
			varValues[i] = iterations;
			break;
		case MYSCORE:
			varValues[i] = score;
			break;
		case NO:
			varValues[i] = *(ints.begin() + intsIterator);
			break;
		default:
			break;
		}
		i++;
	}


	int value = varValues[0];

	vector<char> ops;

	int j = 1;
	for (std::vector<char>::iterator jt = ops.begin(); jt != ops.end(); ) {
		switch (*jt) {
		case '+':
			value += varValues[j];
			break;
		case '-':
			value -= varValues[j];
			break;
		}
		j++;
	}

	delete[] varValues;

	return value;
}

Variable Expression::getVariable(const char* input) {
	//convert string to key
	Variable key = NO;

	if (strcmp(input, "LASTOUTCOME") == 0) {
		key = LASTOUTCOME;
		isInt = false;
	}
	if (strcmp(input, "W") == 0) {
		key = W;
		isInt = false;
	}
	if (strcmp(input, "X") == 0) {
		key = X;
		isInt = false;
	}
	if (strcmp(input, "Y") == 0) {
		key = Y;
		isInt = false;
	}
	if (strcmp(input, "Z") == 0) {
		key = Z;
		isInt = false;
	}
	if (strcmp(input, "A") == 0) {
		key = A;
		isInt = false;
	}
	if (strcmp(input, "B") == 0) {
		key = B;
		isInt = false;
	}
	if (strcmp(input, "C") == 0) {
		key = C;
		isInt = false;
	}
	if (strcmp(input, "ALLOUTCOMES_W") == 0) {
		key = ALLOUTCOMES_W;
		isInt = true;
	}
	if (strcmp(input, "ALLOUTCOMES_X") == 0) {
		key = ALLOUTCOMES_X;
		isInt = true;
	}
	if (strcmp(input, "ALLOUTCOMES_Y") == 0) {
		key = ALLOUTCOMES_Y;
		isInt = true;
	}
	if (strcmp(input, "ALLOUTCOMES_Z") == 0) {
		key = ALLOUTCOMES_Z;
		isInt = true;
	}
	if (strcmp(input, "ITERATIONS") == 0) {
		key = ITERATIONS;
		isInt = true;
	}
	if (strcmp(input, "MYSCORE") == 0) {
		key = MYSCORE;
		isInt = true;
	}
	if (key == NO) {
		isInt = true;
		ints.push_back(stoi(input));
	}

	return key;
}

bool Expression::isItint() {
	return isInt;
}

Variable Expression::getVariableValue() const {
	//get the variable instead of int
	if (*vars.begin() == LASTOUTCOME) {
		return lastO;
	}
	else {
		return *vars.begin();
	}
}

void Expression::insert(Variable lastO, int allO_W, int allO_x, int allO_y, int allO_z, int allO_a, int allO_b, int allO_c, int iterations, float score) {
	//assign all values to variables
	this->lastO = lastO;
	this->allO_W = allO_W;
	this->allO_x = allO_x;
	this->allO_y = allO_y;
	this->allO_z = allO_z;
	this->allO_a = allO_a;
	this->allO_b = allO_b;
	this->allO_c = allO_c;
	this->iterations = iterations;
	this->score = score;
}