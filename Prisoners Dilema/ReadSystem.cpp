#include "ReadSystem.h"


ReadSystem::ReadSystem()
{
}
ReadSystem::~ReadSystem()
{
}

void ReadSystem::read(int fileNumbers) {

	cout << "To automatically pick files press \"0\"...\nTo manually pick files press \"1\"\n";

	int reply = u.replyWithInt();

	for (int i = 0; i < fileNumbers; i++) {
		string fileNames;

		switch(reply) {
		case 0:
			fileNames = "../Strategies/Strategy_" + to_string(i) + ".txt";
			break;
		case 1:
			cout << "what is the address of the ";
			if (i % 10 == 0) {
				cout << i + 1 << "st file ?\n";
			}
			else if (i % 10 == 1) {
				cout << i + 1 << "nd file ?\n";
			}
			else if (i % 10 == 2) {
				cout << i + 1 << "rd file ?\n";
			}
			else if (i % 10 > 2) {
				cout << i + 1 << "th file ?\n";
			}

			fileNames = u.replyWithString();
			break;
		}

		i += load(fileNames.c_str());
	}
}
int ReadSystem::load(const char* path) {
	std::ifstream myfile(path);

	std::vector<std::string> fileData;
	std::vector<string> fileDataLines;
	//Command* coms = new Command();
	std::map<int, Command> coms;
	int noOfComs = 0;
	string combined;
	//string* lines = nullptr;

	if (!myfile) //Always test the file open.
	{
		std::cout << "Error opening strategy file" << std::endl;
		return -1;
	}
	else {
		std::cout << "Strategy file opened succesfully" << std::endl;
	}



	//lines = new string;
	for (int i = 0; !myfile.eof(); i++) {
		string newLine = string();
		std::getline(myfile, newLine);
		fileData.push_back(newLine);
	}

	/*for (std::vector<string>::iterator it = fileData.begin(); it != fileData.end(); it++) {
	noOfComs++;
	}*/

	//coms = new Command[noOfComs];



	for (std::vector<string>::iterator it = fileData.begin(); it != fileData.end(); it++) {
		if (*it != "") {
			//char* input = it->c_str();
			char* context = NULL;

			//char *input = new char[sizeof  *it * it->length()];
			//strcpy_s(input, sizeof input * it->length(), it->c_str());

			Parse p = Parse(*it, " ");

			string pch = p.next();


			coms[atoi(pch.c_str())] = Command(*it);
		}
	}

	Prisoner p = Prisoner(path, coms, noOfComs);

	prisoners.push_back(p);

	//*(prisoners.end() -1) = Prisoner(path, coms, noOfComs);

	return 0;
}

void ReadSystem::play() {
	int reply = askforNumberOfGames();
		for (std::vector<Prisoner>::iterator i = prisoners.begin(); i != prisoners.end() - 1; i++) {
			for (std::vector<Prisoner>::iterator j = i + 1; j != prisoners.end(); j++) {
				matchPrisoners(*i, *j, reply);
				i->flush();
				j->flush();
			}
		}
}
void ReadSystem::playSingle() {
	int reply = askforNumberOfGames();
		matchPrisoners(*prisoners.begin(), *(prisoners.begin() + 1), reply);
}
void ReadSystem::testGangs() {
	int reply = askforNumberOfGames();
		for (vector<Gang>::iterator it = gangs.begin(); it != gangs.end() - 1; it++) {
			for (vector<Gang>::iterator jt = it + 1; jt != gangs.end(); jt++) {
				matchGangs(*it, *jt, reply);
				it->flush();
				jt->flush();
			}
		}
}
void ReadSystem::testGangsSingle() {
	int reply = askforNumberOfGames();
		matchGangs(*gangs.begin(), *(gangs.begin() + 1), reply);
}
void ReadSystem::testGangsWithSpies() {
	int reply = askforNumberOfGames();
		for (vector<Gang>::iterator it = gangs.begin(); it != gangs.end(); it++) {
			for (vector<Gang>::iterator jt = it + 1; jt != gangs.end(); jt++) {
				matchGangsWithSpies(*it, *jt, reply);
				it->flush();
				jt->flush();
			}
		}
}
void ReadSystem::testGangsWithSpiesSingle() {
	int reply = askforNumberOfGames();
		matchGangsWithSpies(*gangs.begin(), *(gangs.begin() + 1), reply);
}

void ReadSystem::printResults() {
	Prisoner bestStrategy = *prisoners.begin();
	for (std::vector<Prisoner>::iterator i = prisoners.begin(); i != prisoners.end(); i++) {
		cout << "prisoner: " << i->getPath() << "\n" << "played " << i->getPermaIterations() << " times\n"
			<< "They Stayed Silent when the other Prisoner stayed Silent " << i->getPermaW() << " times\n"
			<< "They Stayed Silent when the other Prisoner Betrayed " << i->getPermaX() << " times\n"
			<< "They Betrayed when the other Prisoner stayed Silent " << i->getPermaY() << " times\n"
			<< "They Betrayed when the other Prisoner Betrayed " << i->getPermaZ() << " times\n"
			<< "They spent " << i->getPermaScore() << " years in prison\n";
		system("pause");
		if (i->getPermaScore() < bestStrategy.getPermaScore()) {
			bestStrategy = *i;
		}
	}
	cout << "strategy: " << bestStrategy.getPath() << "\n" << "is the best Strategy.\n";
}
void ReadSystem::printSingleResults() {
	Prisoner bestStrategy = *prisoners.begin();
	for (std::vector<Prisoner>::iterator i = prisoners.begin(); i != prisoners.begin() + 2; i++) {
		cout << "prisoner: " << i->getPath() << "\n" << "played " << i->getIterations() << " times\n"
			<< "They Stayed Silent when the other Prisoner stayed Silent " << i->getW() << " times\n"
			<< "They Stayed Silent when the other Prisoner Betrayed " << i->getX() << " times\n"
			<< "They Betrayed when the other Prisoner stayed Silent " << i->getY() << " times\n"
			<< "They Betrayed when the other Prisoner Betrayed " << i->getZ() << " times\n"
			<< "They spent " << i->getScore() << " years in prison\n";
		system("pause");
		if (i->getScore() < bestStrategy.getScore()) {
			bestStrategy = *i;
		}
	}
	cout << "strategy: " << bestStrategy.getPath() << "\n" << "is the best Strategy.\n";
}
void ReadSystem::printGangResults() {
	Gang bestStrategy = *gangs.begin();
	for (std::vector<Gang>::iterator i = gangs.begin(); i != gangs.end(); i++) {
		cout << "gang: " << i->getPath() << "\n"
			<< "played " << i->getPermaIterations() << " times\n"
			<< "They Stayed Silent when the other gang stayed Silent " << i->getPermaW() << " times\n"
			<< "They Stayed Silent when the other gang Betrayed " << i->getPermaX() << " times\n"
			<< "They Betrayed when the other gang stayed Silent " << i->getPermaY() << " times\n"
			<< "They Betrayed when the other gang Betrayed " << i->getPermaZ() << " times\n"
			<< "They had more members Betray than the other Gang " << i->getPermaA() << " times\n"
			<< "They had less members Betray than the other Gang " << i->getPermaB() << " times\n"
			<< "They had as many members Betray as the other Gang " << i->getPermaC() << " times\n"
			<< "They spent " << i->getPermaScore() << " years in prison\n";
		system("pause");
		if (i->getPermaScore() < bestStrategy.getPermaScore()) {
			bestStrategy = *i;
		}
	}
	cout << "strategy: " << bestStrategy.getPath() << "\n" << "is the best set of Strategy.\n";
}
void ReadSystem::printGangSingleResults() {
	Gang bestStrategy = *gangs.begin();
	for (std::vector<Gang>::iterator i = gangs.begin(); i != gangs.begin() + 2; i++) {
		cout << "gang: " << i->getPath() << "\n"
			<< "played " << i->getIterations() << " times\n"
			<< "They Stayed Silent when the other gang stayed Silent " << i->getW() << " times\n"
			<< "They Stayed Silent when the other gang Betrayed " << i->getX() << " times\n"
			<< "They Betrayed when the other gang stayed Silent " << i->getY() << " times\n"
			<< "They Betrayed when the other gang Betrayed " << i->getZ() << " times\n"
			<< "They had more members Betray than the other Gang " << i->getA() << " times\n"
			<< "They had less members Betray than the other Gang " << i->getB() << " times\n"
			<< "They had as many members Betray as the other Gang " << i->getC() << " times\n"
			<< "They spent " << i->getScore() << " years in prison\n";
		system("pause");
		if (i->getScore() < bestStrategy.getScore()) {
			bestStrategy = *i;
		}
	}
	cout << "strategy: " << bestStrategy.getPath() << "\n" << "is the best set of Strategy.\n";
}
void ReadSystem::printSpyGangResults() {
	Gang bestStrategy = *gangs.begin();
	for (std::vector<Gang>::iterator i = gangs.begin(); i != gangs.end(); i++) {
		assignGangLeadersAndSpies();
		cout << "gang: " << i->getPath() << "\n"
			<< "played " << i->getPermaIterations() << " times\n"
			<< "They Stayed Silent when the other gang stayed Silent " << i->getPermaW() << " times\n"
			<< "They Stayed Silent when the other gang Betrayed " << i->getPermaX() << " times\n"
			<< "They Betrayed when the other gang stayed Silent " << i->getPermaY() << " times\n"
			<< "They Betrayed when the other gang Betrayed " << i->getPermaZ() << " times\n"
			<< "They had more members Betray than the other Gang " << i->getPermaA() << " times\n"
			<< "They had less members Betray than the other Gang " << i->getPermaB() << " times\n"
			<< "They had as many members Betray as the other Gang " << i->getPermaC() << " times\n"
			<< "They caught the prisoner " << i->getPermaPrisonersCaught() << " times\n"
			<< "They spent " << i->getPermaScore() << " years in prison\n";
		system("pause");
		if (i->getPermaScore() < bestStrategy.getPermaScore()) {
			bestStrategy = *i;
		}
	}
	cout << "strategy: " << bestStrategy.getPath() << "\n" << "is the best set of Strategy.\n";
}
void ReadSystem::printSpyGangSingleResults() {
	Gang bestStrategy = *gangs.begin();
	for (std::vector<Gang>::iterator i = gangs.begin(); i != gangs.begin() + 2; i++) {
		assignGangLeadersAndSpies();
		cout << "gang: " << i->getPath() << "\n"
			<< "played " << i->getIterations() << " times\n"
			<< "They Stayed Silent when the other gang stayed Silent " << i->getW() << " times\n"
			<< "They Stayed Silent when the other gang Betrayed " << i->getX() << " times\n"
			<< "They Betrayed when the other gang stayed Silent " << i->getY() << " times\n"
			<< "They Betrayed when the other gang Betrayed " << i->getZ() << " times\n"
			<< "They had more members Betray than the other Gang " << i->getA() << " times\n"
			<< "They had less members Betray than the other Gang " << i->getB() << " times\n"
			<< "They had as many members Betray as the other Gang " << i->getC() << " times\n"
			<< "They caught the prisoner " << i->getPrisonersCaught() << " times\n"
			<< "They spent " << i->getScore() << " years in prison\n";
		system("pause");
		if (i->getScore() < bestStrategy.getScore()) {
			bestStrategy = *i;
		}
	}
	cout << "strategy: " << bestStrategy.getPath() << "\n" << "is the best set of Strategy.\n";
}

void  ReadSystem::assignGangs() {
	int gangNumber = prisoners.size() / 5;

	for (int i = 0; i < gangNumber; i++) {

		vector<Prisoner> prs;

		for (vector<Prisoner>::iterator it = prisoners.begin() + i * 5; it != prisoners.begin() + (i + 1) * 5; it++) {
			prs.push_back(*it);
		}
		Gang g = Gang(prs);
		gangs.push_back(g);
	}
}
void ReadSystem::assignGangLeadersAndSpies() {
	for (vector<Gang>::iterator it = gangs.begin(); it != gangs.end(); it++) {
		it->flushSpies();
		it->setSpy(rand() % 5);
		it->setLeader(rand() % 5);
	}
}

void ReadSystem::matchPrisoners(Prisoner &left, Prisoner &right, int iter) {
	for (int i = 0; i < iter; i++) {
		left.run();
		right.run();

		//left.getDecision();
		//right.getDecision();

		if (left.isSilent() && right.isSilent()) {
			left.addW();
			right.addW();
		}
		if (left.isSilent() && !right.isSilent()) {
			left.addX();
			right.addY();
		}
		if (!left.isSilent() && right.isSilent()) {
			left.addY();
			right.addX();
		}
		if (!left.isSilent() && !right.isSilent()) {
			left.addZ();
			right.addZ();
		}
	}

}
void ReadSystem::matchGangs(Gang& purple, Gang& megenta, int iter) {
	for (int i = 0; i < iter; i++) {

		//std::thread pThread(Gang::run, &purple);
		//std::thread mThread(Gang::run, &megenta);

		int purpleSilents = purple.run();
		int magentaSilents = megenta.run();

		if (magentaSilents == 5 && purpleSilents == 5) {
			purple.addW();
			megenta.addW();
		}
		if (magentaSilents == 0 && purpleSilents == 0) {
			purple.addZ();
			megenta.addZ();
		}
		if (magentaSilents == 5 && purpleSilents == 0) {
			purple.addY();
			megenta.addX();
		}
		if (magentaSilents == 0 && purpleSilents == 5) {
			purple.addX();
			megenta.addY();
		}
		if (magentaSilents != 0 && magentaSilents != 5 || purpleSilents != 0 && purpleSilents != 5) {
			if (magentaSilents == purpleSilents) {
				purple.addC();
				megenta.addC();
			}
			if (magentaSilents > purpleSilents) {
				purple.addA();
				megenta.addB();
			}
			if (magentaSilents < purpleSilents) {
				purple.addB();
				megenta.addA();
			}
		}
	}
}
void ReadSystem::matchGangsWithSpies(Gang& purple, Gang& megenta, int iter) {
	for (int i = 0; i < iter; i++) {
		int purpleSilents = purple.runWithSpies();
		int magentaSilents = megenta.runWithSpies();

		bool purpleSpyIsFound = purple.huntSpy();
		bool megentaSpyIsFound = megenta.huntSpy();

		if (!purpleSpyIsFound && !megentaSpyIsFound) {
			if (magentaSilents == 5 && purpleSilents == 5) {
				purple.addW();
				megenta.addW();
			}
			if (magentaSilents == 0 && purpleSilents == 0) {
				purple.addZ();
				megenta.addZ();
			}
			if (magentaSilents == 5 && purpleSilents == 0) {
				purple.addY();
				megenta.addX();
			}
			if (magentaSilents == 0 && purpleSilents == 5) {
				purple.addX();
				megenta.addY();
			}
			if (magentaSilents != 0 && magentaSilents != 5 || purpleSilents != 0 && purpleSilents != 5) {
				if (magentaSilents == purpleSilents) {
					purple.addC();
					megenta.addC();
				}
				if (magentaSilents > purpleSilents) {
					purple.addA();
					megenta.addB();
				}
				if (magentaSilents < purpleSilents) {
					purple.addB();
					megenta.addA();
				}
			}
		}
		else {
			if (purpleSpyIsFound && !megentaSpyIsFound) {
				purple.setYears(rand() % 2 * 2);
				megenta.setYears(5);
			}
			if (!purpleSpyIsFound && megentaSpyIsFound) {
				purple.setYears(5);
				megenta.setYears(rand() % 2 * 2);
			}
			if (purpleSpyIsFound && megentaSpyIsFound) {
				purple.setYears(6);
				megenta.setYears(6);
			}
		}
	}
}

int ReadSystem::askforNumberOfGames() {
	cout << "how many itteration do you want to play?\n";
	int reply = u.replyWithInt();
	return reply;
}

void ReadSystem::clear() {
	prisoners.clear();
	gangs.clear();
}