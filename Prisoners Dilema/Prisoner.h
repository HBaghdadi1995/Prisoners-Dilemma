#pragma once
#include <map>
#include "Command.h"

class Prisoner
{
public:
	Prisoner();
	Prisoner(const Prisoner&);
	Prisoner(const char*, std::map<int, Command> coms, int noOfComs);
	virtual ~Prisoner();

	void run();

	bool isSilent();

	void addW();
	void addX();
	void addY();
	void addZ();

	string getPath() { return path; }
	int getIterations() { return iterations; }
	int getW() { return w; }
	int getX() { return x; }
	int getY() { return y; }
	int getZ() { return z; }
	float getScore() { return score; }

	int getPermaIterations() { return permaIterations; }
	int getPermaW() { return permaW; }
	int getPermaX() { return permaX; }
	int getPermaY() { return permaY; }
	int getPermaZ() { return permaZ; }
	float getPermaScore() { return permaScore; }

	void insert();
	void insert(Variable lastO, int w, int x, int y, int z, int a, int b, int c, int iterations, float score);

	void setSpy() { spy = true; }
	void setLeader() { leader = true; }

	bool getSpy() { return spy; }
	bool getLeader() { return leader; }

	Prisoner& operator=(const Prisoner& other)
	{
		Prisoner p;
		p.w = other.w;
		p.x = other.x;
		p.y = other.y;
		p.z = other.z;
		p.a = other.a;
		p.b = other.b;
		p.c = other.c;
		p.iterations = other.iterations;
		p.score = other.score;
		p.path = other.path;
		p.coms = other.coms;
		p.noOfComs = other.noOfComs;
		p.decision = other.decision;
		p.lastO = other.lastO;

		for (std::map<int, Command>::iterator it = p.coms.begin(); it != p.coms.end(); ++it) {
			it->second.insert(lastO, w, x, y, z,a,b,c, iterations, score);
		}
		return p;
	}

	void flush();

	void nutralise();

private:
	int w = 0, x = 0, y = 0, z = 0, a = 0, b = 0, c = 0, iterations = 0;
	int permaW = 0, permaX = 0, permaY = 0, permaZ = 0, permaA = 0, permaB = 0, permaC = 0, permaIterations = 0;
	float score = 0, permaScore = 0;
	string path;
	std::map<int, Command> coms;
	int noOfComs;
	keyword decision;
	Variable lastO;
	bool spy = false, leader = false;
};