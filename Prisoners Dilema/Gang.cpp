#include "Gang.h"

Gang::Gang(vector<Prisoner> prs) {
	prisoners = prs;
}

Gang::Gang()
{
}

Gang::~Gang()
{
}

int Gang::run() {
	int silents = 0;

	//std::bind(&runP, this);
	vector<thread> threads;
	/*for (int i = 0; i < 5; i++) {
		//threads.push_back(thread(&runP, &(*prisoners.begin())));
		threads.push_back(std::thread([&](Gang* g) { g->runP(&(*(prisoners.begin() + i))); }, this));
	}*/

	threads.push_back(std::thread([&](Gang* g) { g->runP(&(*(prisoners.begin() + 0))); }, this));
	threads.push_back(std::thread([&](Gang* g) { g->runP(&(*(prisoners.begin() + 1))); }, this));
	threads.push_back(std::thread([&](Gang* g) { g->runP(&(*(prisoners.begin() + 2))); }, this));
	threads.push_back(std::thread([&](Gang* g) { g->runP(&(*(prisoners.begin() + 3))); }, this));
	threads.push_back(std::thread([&](Gang* g) { g->runP(&(*(prisoners.begin() + 4))); }, this));

	for (vector<thread>::iterator it = threads.begin(); it != threads.end(); it++) {
		it->join();
	}

	for (vector<Prisoner>::iterator it = prisoners.begin();it != prisoners.end(); it++) {
		//it->insert(lastO, w, x, y, z, a, b, c, iterations, score);
		//it->run();
		if (it->isSilent()) {
			silents++;
		}
	}
	return silents;
}

int Gang::runWithSpies() {
	int silents = 0;
	vector<Prisoner>::iterator spy;
	for (vector<Prisoner>::iterator it = prisoners.begin();it != prisoners.end(); it++) {
		if (!it->getSpy()) {
			it->insert(lastO, w, x, y, z, a, b, c, iterations, score);
			it->run();
			if (it->isSilent()) {
				silents++;
			}
		}
		else {
			spy = it;
		}
		if (silents < 2) {
			silents++;
		}
		else if (silents == 2) {
			silents += rand() % 2;
		}
	}
	return silents;
}

void Gang::addW() {
	w++;
	score += 2;
	lastO = W;
	iterations++;
}
void Gang::addX() {
	x++;
	score += 5;
	lastO = X;
	iterations++;
}
void Gang::addY() {
	y++;
	lastO = Y;
	iterations++;
}
void Gang::addZ() {
	z++;
	score += 4;
	lastO = Z;
	iterations++;
}
void Gang::addA() {
	a++;
	score += 2.5;
	lastO = A;
	iterations++;
}
void Gang::addB() {
	b++;
	score += 3;
	lastO = B;
	iterations++;
}
void Gang::addC() {
	c++;
	score += 2;
	lastO = C;
	iterations++;
}
string Gang::getPath() {
	string str = "";
	for (vector<Prisoner>::iterator it = prisoners.begin();it != prisoners.end() -1; it++) {
		str += it->getPath();
		str += ", ";
	}
	str += (prisoners.end() - 1)->getPath();
	return str;
}
bool Gang::huntSpy() {
	vector<Prisoner>::iterator pick;
	bool picked = false;
	while (!picked) {
		pick = prisoners.begin() + rand() % 5;
		if (!pick->getLeader()) {
			picked = true;
		}
	}
	if (pick->getSpy()) {
		prisonersCaught++;
	}
	return pick->getSpy();
}

void Gang::setYears(int i) {
	score += i;
	iterations++;
}

void Gang::flush() {
	permaW += w;
	permaX += x;
	permaY += y;
	permaZ += z;
	permaA += a;
	permaB += b;
	permaC += c;
	permaIterations += iterations;
	permaScore += score;
	permaPrisonersCaught += prisonersCaught;

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
	prisonersCaught = 0;
}

void Gang::runP(Prisoner* prisoner) {
	prisoner->insert(lastO, w, x, y, z, a, b, c, iterations, score);
	prisoner->run();
}

void Gang::flushSpies() {
	for (vector<Prisoner>::iterator it = prisoners.begin(); it != prisoners.end(); it++) {
		it->nutralise();
	}
}