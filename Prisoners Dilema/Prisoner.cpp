#include "Prisoner.h"

Prisoner::Prisoner()
{
}

Prisoner::~Prisoner()
{
}

Prisoner::Prisoner(const Prisoner& p) {
	this->w = p.w;
	this->x = p.x;
	this->y = p.y;
	this->z = p.z;
	this->iterations = p.iterations;
	this->score = p.score;
	this->path = p.path;
	this->coms = p.coms;
	this->noOfComs = p.noOfComs;
	this->decision = p.decision;
	this->lastO = p.lastO;
}

Prisoner::Prisoner(const char* path, std::map<int, Command> coms, int noOfComs) {
	this->path = path;
	this->coms = coms;
	//this->noOfComs = noOfComs;

	insert();

}

void Prisoner::run() {

	insert();

	keyword decision = NONE;

	for (int i = 0; decision == NONE; i++) {
		if (coms.find(i) != coms.end()) {
			coms[i].run(i);
			decision = coms[i].getDecision();
		}
	}
	/*if (decision == IF) {
		int i = 0;
	}*/
	this->decision = decision;
}

bool Prisoner::isSilent() {
	if (decision == SILENCE) {
		return true;
	}
	else {
		return false;
	}
}


void Prisoner::addW() {
	w++;
	score += 2;
	lastO = W;
	iterations++;
}
void Prisoner::addX() {
	x++;
	score += 5;
	lastO = X;
	iterations++;
}
void Prisoner::addY() {
	y++;
	lastO = Y;
	iterations++;
}
void Prisoner::addZ() {
	z++;
	score += 4;
	lastO = Z;
	iterations++;
}

void Prisoner::insert() {
	for (std::map<int, Command>::iterator it = coms.begin(); it != coms.end(); ++it) {
		it->second.insert(lastO, w, x, y, z, a, b, c, iterations, score);
	}
}

void Prisoner::insert(Variable lastO, int w, int x, int y, int z, int a, int b, int c, int iterations, float score) {
	this->lastO = lastO;
	this->w = w;
	this->x = x;
	this->y = y;
	this->z = z;
	this->a = a;
	this->b = b;
	this->c = c;
	this->iterations = iterations;
	this->score = score;
	insert();
}

void Prisoner::flush() {
	permaW += w;
	permaX += x;
	permaY += y;
	permaZ += z;
	permaA += a;
	permaB += b;
	permaC += c;
	permaIterations += iterations;
	permaScore += score;

	lastO = NO;
	w = 0;
	x = 0;
	y = 0;
	z = 0;
	a = 0;
	b = 0;
	c = 0;
	iterations = 0;
	score = 0;
}

void Prisoner::nutralise() {
	spy = false, leader = false;
}