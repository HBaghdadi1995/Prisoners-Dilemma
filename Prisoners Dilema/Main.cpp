#include <iostream>
//#include "FileIO.h"
#include "ReadSystem.h"
#include "WriteSystem.h"
#include <time.h>
#include "UI.h"

using namespace std;

int main() {
	//_ASSERT(_CrtCheckMemory());
	srand(time(0));
	/*Variable Declerations*/
	bool exit = false;
	int reply = 0;
	int fileNumbers;
	ReadSystem r;
	WriteSystem w;
	UI u;

	while (!exit) {



		/*Main Part of Code*/
		std::cout << "To generate strategies press \"0\"...\nTo test strategies press \"1\"...\nTo test exit press \"2\"...\n";
		switch (u.replyWithInt()) {
		case 0:
			//FileIO::write();
			w = WriteSystem();
			int lines;
			cout << "How many files do you want to generate?\n";
			fileNumbers = u.replyWithInt();
			cout << "How many lines do you want to generate?\n";
			lines = u.replyWithInt();
			w.generate(fileNumbers,lines);
			cout << fileNumbers << " Strategies created\n";
			cout << "..........................................\n";
			break;
		case 1:
			r = ReadSystem();
			cout << "How many files do you want to read?\n";
			fileNumbers = u.replyWithInt();
			r.read(fileNumbers);
			cout << "All files read in...\nTo play a single game press \"0\"...\nTo play a tournament \"1\"...\n";
			reply = u.replyWithInt();
			switch (reply) {
			case 0:
				cout << "To test Individual strategies press \"0\"...\nTo test gang Strategies press \"1\"...\n";
				//cout << "To test gang strategies with spies and leader press \"2\"...\n";
				reply = u.replyWithInt();
				switch (reply) {
				case 0:
					r.playSingle();
					r.printSingleResults();
					break;
				case 1:
					r.assignGangs();
					r.testGangsSingle();
					r.printGangSingleResults();
					break;
				case 2:
					/*r.assignGangs();
					r.assignGangLeadersAndSpies();
					r.testGangsWithSpiesSingle();
					r.printSpyGangSingleResults();
					break;*/
				}
				break;
			case 1:
				cout << "To test Individual strategies press \"0\"...\nTo test gang Strategies press \"1\"...\n";
				//cout <<	"To test gang strategies with spies and leader press \"2\"...\n";
				reply = u.replyWithInt();
				switch (reply) {
				case 0:
					r.play();
					r.printResults();
					break;
				case 1:
					r.assignGangs();
					r.testGangs();
					r.printGangResults();
					break;
				case 2:
					/*r.assignGangs();
					r.assignGangLeadersAndSpies();
					r.testGangsWithSpies();
					r.printSpyGangResults();
					break;*/
				}
				break;
			}
			r.clear();
			//FileIO::read();
			break;
		case 2:
			exit = true;
			break;
		}
	}

	/*Destroying all pointers*/
}