#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <map>
#include "Prisoner.h"
#include "Command.h"
#include "Gang.h"
#include "UI.h"
#include <thread>

using namespace std;

class ReadSystem
{
public:
	ReadSystem();
	~ReadSystem();

	void read(int);
	int load(const char* path);

	void play();
	void playSingle();
	void testGangs();
	void testGangsSingle();
	void testGangsWithSpies();
	void testGangsWithSpiesSingle();

	void printResults();
	void printSingleResults();
	void printGangResults();
	void printGangSingleResults();
	void printSpyGangResults();
	void printSpyGangSingleResults();

	void assignGangs();
	void assignGangLeadersAndSpies();

	void matchPrisoners(Prisoner&, Prisoner&, int);
	void matchGangs(Gang&, Gang&, int);
	void matchGangsWithSpies(Gang&, Gang&, int);

	int askforNumberOfGames();

	void clear();
private:
	vector<Prisoner> prisoners;
	vector<Gang> gangs;
	UI u;
};