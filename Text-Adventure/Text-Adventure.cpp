

#include <iostream>
#include <string>

using namespace std;

//function declarations 
void exploreFireFaction1();
void exploreFireFaction2();
void exploreFireFaction3();
void exploreIceFaction1();
void exploreIceFaction2();
void exploreIceFaction3();
void exploreLifeFaction1();
void exploreLifeFaction2();
void exploreLifeFaction3();
void exploreDeathFaction1();
void exploreDeathFaction2();
void exploreDeathFaction3();
void exploreStormFaction1();
void exploreStormFaction2();
void exploreStormFaction3();
void exploreIllusionFaction1();
void exploreIllusionFaction2();
void exploreIllusionFaction3();


int main()
{

	string playerName;

	cout << "Welcome to the Wizard's Adventure!" << endl;
	cout << "What is your name, young wizard?" << endl;
	getline(cin, playerName);

	cout << "Hello, " << playerName << "! Let's begin your adventure." << endl;

	cout << "Choose your study of magic:" << endl;
	cout << "1. Fire" << endl;
	cout << "2. Ice" << endl;
	cout << "3. Life" << endl;
	cout << "4. Death" << endl;
	cout << "5. Storm" << endl;
	cout << "6. Illusion" << endl;

	int schoolChoice;
	cin >> schoolChoice;

	string school;
	switch (schoolChoice) {
		case 1:
			school = "Fire";
			cout << "Choose your faction within the School of Fire:" << endl;
			cout << "1. Inferno Knights" << endl;
			cout << "2. Pyro Scholars" << endl;
			cout << "3. Flameborn Order" << endl;
			break;
		case 2:
			school = "Ice";
			cout << "Choose your faction within the School of Ice:" << endl;
			cout << "1. Frost Guard" << endl;
			cout << "2. Ice Scholars" << endl;
			cout << "3. Glacial Sentinels" << endl;
			break;
		case 3:
			school = "Life";
			cout << "Choose your faction within the School of Life" << endl;
			cout << "1. Sylvan Scholars" << endl;
			cout << "2. Verdant Circle" << endl;
			cout << "3. Eternal Bloom Council" << endl;
			break;
		case 4:
			school = "Death";
			cout << "Choose your faction within the School of Death" << endl;
			cout << "1. Necrotic Enclave" << endl;
			cout << "2. Shadowveil Syndicate" << endl;
			cout << "3. Gravebound Cult" << endl;
			break;
		case 5:
			school = "Storm";
			cout << "Choose your faction within the School of Storm" << endl;
			cout << "1. Stormcaller Brotherhood" << endl;
			cout << "2. Thunderstrike Circle" << endl;
			cout << "3. Electroflare Consortium" << endl;
			break;
		case 6:
			school = "Illusion";
			cout << "Choose your faction within the School of Illusion" << endl;
			cout << "1. Veilweaver Guild" << endl;
			cout << "2. Mirage Conclave" << endl;
			cout << "3. Phantomveil Assembly" << endl;
			break;
		default:
			cout << "Invalid school choice. The adventure ends here." << endl;
			return 0;
	}
	
	int factionChoice;
	cin >> factionChoice;

	if (school == "Fire") {
		switch (factionChoice) {
			case 1:
				exploreFireFaction1();
				break;
			case 2:
				exploreFireFaction2();
				break;
			case 3:
				exploreFireFaction3();
				break;
			default:
				cout << "Invalid faction choice." << endl;
				break;
		}
	} else if (school == "Ice") {
		switch (factionChoice) {
			case 1:
				exploreIceFaction1();
				break;
			case 2:
				exploreIceFaction2();
				break;
			case 3:
				exploreIceFaction3();
				break;
			default:
				cout << "Invalid faction choice." << endl;
				break;
		}
	} else if (school == "Life") {
		switch (factionChoice) {
			case 1:
				exploreLifeFaction1();
				break;
			case 2:
				exploreLifeFaction2();
				break;
			case 3:	
				exploreLifeFaction3();
				break;
			default:
				cout << "Invalid faction choice." << endl;
				break;
		}
	} else if (school == "Death") {
		switch (factionChoice) {
			case 1:
				exploreDeathFaction1();
				break;
			case 2:
				exploreDeathFaction2();
				break;
			case 3:
				exploreDeathFaction3();
				break;
			default:
				cout << "Invalid faction choice." << endl;
				break;
		}
	} else if (school == "Storm") {
		switch (factionChoice) {
			case 1:
				exploreStormFaction1();
				break;
			case 2:
				exploreStormFaction2();
				break;
			case 3:
				exploreStormFaction3();
				break;
			default:
				cout << "Invalid faction choice." << endl;
				break;
		}
	} else if (school == "Illusion") {
		switch (factionChoice) {
			case 1:
				exploreIllusionFaction1();
				break;
			case 2:
				exploreIllusionFaction2();
				break;
			case 3:
				exploreIllusionFaction3();
				break;
			default:
				cout << "Invalid faction choice." << endl;
				break;
		}
	} else {
		cout << "Invalid school choice." << endl;
	}

}

