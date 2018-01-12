#include "UI.h"

UI::UI()
{
}

UI::~UI()
{
}

int UI::replyWithInt() {
	int i;
	bool good = false;
	if (cin >> i) {
		good = true;
	}
	else {
		cin.clear();
		cin.ignore();
	}
	//bool good = (cin >> i);
	while (!good) {
		cout << "answer is not an int, please enter again.\n";
		if (cin >> i) {
			good = true;
		}
		else {
			cin.clear();
			cin.ignore();
		}
	}
	return i;
}
string UI::replyWithString() {
	string str;
	bool good = false;
	if (cin >> str) {
		good = true;
	}
	else {
		cin.clear();
		cin.ignore();
	}
	while (!good) {
		cout << "answer is not an string, please enter again.\n";
		if (cin >> str) {
			good = true;
		}
		else {
			cin.clear();
			cin.ignore();
		}
	}
	return str;
}