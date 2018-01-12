#pragma once
#include "Prisoner.h"
#include <thread>

class Gang
{
public:
	Gang();
	Gang(vector<Prisoner> prs);
	~Gang();

	int run();
	int runWithSpies();
	
	void addW();
	void addX();
	void addY();
	void addZ();
	void addA();
	void addB();
	void addC();

	string getPath();
	int getIterations() { return iterations; }
	int getW() { return w; }
	int getX() { return x; }
	int getY() { return y; }
	int getZ() { return z; }
	int getA() { return a; }
	int getB() { return b; }
	int getC() { return c; }
	float getScore() { return score; }
	int getPrisonersCaught() { return prisonersCaught; }

	int getPermaIterations() { return permaIterations; }
	int getPermaW() { return permaW; }
	int getPermaX() { return permaX; }
	int getPermaY() { return permaY; }
	int getPermaZ() { return permaZ; }
	int getPermaA() { return permaA; }
	int getPermaB() { return permaB; }
	int getPermaC() { return permaC; }
	float getPermaScore() { return permaScore; }
	int getPermaPrisonersCaught() { return permaPrisonersCaught; }

	void setSpy(int i) { (prisoners.begin()+i)->setSpy(); }
	void setLeader(int i) { (prisoners.begin() + i)->setLeader(); }
	void flushSpies();

	bool huntSpy();

	void setYears(int);

	void flush();

	void runP(Prisoner* prisoner);

private:
	vector<Prisoner> prisoners;

	int w = 0, x = 0, y = 0, z = 0, a = 0, b = 0, c = 0, iterations = 0, prisonersCaught = 0;
	int permaW = 0,	permaX = 0,	permaY = 0,	permaZ = 0,	permaA = 0,	permaB = 0,	permaC = 0,	permaIterations = 0, permaPrisonersCaught = 0;
	float score = 0, permaScore = 0;
	Variable lastO;
};