#pragma once
#include <string>
using namespace std;
class Parse
{
public:
	Parse();
	Parse(string,string);
	~Parse();

	string next();
private:
	string str = "";
	string delim = "";
	void erase();
};