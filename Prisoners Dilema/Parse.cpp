#include "parse.h"

Parse::Parse() {

}
Parse::Parse(string str, string delim) {
	this->str = str;
	this->delim = delim;
}
Parse::~Parse() {

}
string Parse::next() {
	string token = str.substr(0, str.find(delim));
	erase();
	if (token== "") {
				token = str.substr(0, str.find(delim));
		erase();
	}
	return token;
}

void Parse::erase() {
	if (str.find(delim) != string::npos) {
		str.erase(0, str.find(delim) + delim.length());
	}
	else {
		str = "";
	}
}