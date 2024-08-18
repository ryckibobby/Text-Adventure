

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

void learnMagic(const string& school);
void embarkQuest(const string& school);


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


	//school choices
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


	//explore options
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

	cout << "Would youl like to learn magic, " << playerName << "? (1 for Yes, 0 for No)" << endl;
	int learnChoice;
	cin >> learnChoice;

	if (learnChoice == 1) {
		learnMagic(school);
	}

	cout << "Would you like to embark on a quest, " << playerName << "? (1 for Yes, 0 for No)" << endl;
	int questChoice;
	cin >> questChoice;

	if (questChoice == 1) {
		embarkQuest(school);
	}

	cout << "The adventure ends here. Thank you for playing, " << playerName << "!" << endl;

	return 0;
}

void exploreFireFaction1() {
	cout << "You are exploring the School of Fire, FAction of the Inferno Knights." << endl;
	cout << "1. The Lava Pits - Where you train with molten magic." << endl;
	cout << "2. The Flame Forge - Where magical weapons and artifacts are crafted." << endl;
	cout << "3. The Ember Hall - A place for meetings and strategy sessions." << endl;

	int choice;
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "You train with molten magic in the Lava Pits, enhancing your fire spells!." << endl;
			break;
		case 2:
			cout << "At the Flame Forge, you learn the art of crafting magical weapons. You create a new fire infused sword!." << endl;
			break;
		case 3:
			cout << "In the Ember Hall, you discuss strategies with fellow knights, gaining valuable tactical knowledge." << endl;
			break;
		default:
			cout << "You wander around and find yourself back at the starting point." << endl;
			break;
	}
}

void exploreFireFaction2() {
	cout << "You are exploring the School of Fire, Faction of the Pyro Scholars." << endl;
	cout << "1. The Arcane Library - Home to ancient texts on fire magic." << endl;
	cout << "2. The Crystal Chamber - Where you study magical crystals with fire properties." << endl;
	cout << "3. The Study Dome - A place for research and experimentation." << endl;

	int choice;
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "In the Arcane Library, you find a lost spell manuscript that boosts you fire magic knowledge." << endl;
			break;
		case 2:
			cout << "At the Crystal Chamber, you study a powerful fire crystal and enhance your magical abilities." << endl;
			break;
		case 3:
			cout << "In the Study Dome, you conduct experiments and discover a new fire magic technique." << endl;
			break;
		default:
			cout << "You wander around and find yourself back at the starting point." << endl;
			break;
	}
}
void exploreFireFaction3() {
	cout << "You are exploring the School of Fire, Faction of the Flameborn Order" << endl;
	cout << "1. The Inferno Arena - A place to test and showcase fire magic prowess." << endl;
	cout << "2. The Emver Weave - Where magical fabrics imbued with fire are created." << endl;
	cout << "3. The Pyro Alchemy Lab - Where you mix fire-related magical ingredients." << endl;

	int choice;
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "At the Inferno Arena, you demonstrate your fire magic skills in a thrilling competition!" << endl;
			break;
		case 2:
			cout << "In the Ember Weave, you create enchanted clothing that enhances your fire magic!" << endl;
			break;
		case 3:
			cout << "In the Pyro Alchemy Lab, you concoct a powerful fire-based potion!" << endl;
			break;
		default:
			cout << "You wander around and find yourself back at the starting point." << endl;
			break;
	}
}

void exploreIceFaction1() {
	cout << "You are exploring the School of Ice, Faction of the Frost Guard." << endl;
	cout << "1. The Glacier Caves - A place to train with ice beasts and magical cold." << endl;
	cout << "2. The Ice Forge - Where cold-infused weapons and artifacts are made." << endl;
	cout << "3. The Crystal Hall - Where the Frost Guard plans their strategies." << endl;

	int choice;
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "You train with ice beasts in the Glacier Caves, enhancing your ice magic skills!" << endl;
			break;
		case 2:
			cout << "At the Ice Forge, you craft a new cold-infused weapon, increasing your combat effectiveness." << endl;
			break;
		case 3:
			cout << "In the Crystal Hall, you strategize with fellow wizards, gaining insights into ice magic combat tactics." << endl;
			break;
		default:
			cout << "You wander around and find yourself back at the starting point." << endl;
			break;
	}
}

void exploreIceFaction2() {
	cout << "You are exploring the School of Ice, Faction of the Ice Scholars." << endl;
	cout << "1. The Frozen Library - A vast repository of ice magic scrolls." << endl;
	cout << "2. The Ice Alchemy Lab - Where magical potions with ice properties are brewed" << endl;
	cout << "3. The Glacial Oberservatory - A place for studying ice magic phenomena." << endl;

	int choice;
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "In the Frozen Library, you uncover ancient texts that deepen your understanding of ice magic." << endl;
			break;
		case 2:
			cout << "At the Alchemy Lab, you create a new potion that enhances your ice spells. " << endl;
			break;
		case 3:
			cout << "In the Glacial Oberservatory, you observe rare ice phenomena and learn new ice magic techniques." << endl;
			break;
		default:
			cout << "You wander around and find yourself back at the starting point." << endl;
			break;
	}
}

void exploreIceFaction3() {
	cout << "You are exploring the School of Ice, Faction of the Glacial Sentinels." << endl;
	cout << "1. The Icebound Fortress - Where the Sentinels defend against ice threats." << endl;
	cout << "2. The Frozen Tundra - A training ground for combat with ice magic." << endl;
	cout << "3. The Sentinel's Keep - A place for planning and coordinating ice magic strategies." << endl;

	int choice;
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "In the Icebound Fortress, you learn advanced defensive techniques against ice magic attacks." << endl;
			break;
		case 2:
			cout << "At the Frozen Tundra, you participate in intense training exercises to sharpen your combat skills." << endl;
			break;
		case 3:
			cout << "In the Sentinel's Keep, you coordinate with other Sentinels and prepare to defend against magical threats." << endl;
			break;
		default:
			cout << "You wander around and find yourself back at the starting point." << endl;
			break;
	}
}

void exploreLifeFaction1() {
	cout << "You are exploring the School of Life, Faction of the Sylvan Scholars." << endl;
	cout << "1. The Celestial Conservatory - A enchanted greenhouse where rare and magical plants are cultivated." << endl;
	cout << "2. The Arcane Grove - A tranquil outdoor space surrounded by ancient trees." << endl;
	cout << "3. The Sylvan Observatory - A specialized tower for studying natural phenomena and magical energies." << endl;

	int choice;
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "In the Celestial Conservatory, you learn practical skills in growing and enchanting magical flora!" << endl;
			break;
		case 2:
			cout << "At the Arcane Grove, you participate in ceremonies to connect with nature's cycles." << endl;
			break;
		case 3:
			cout << "In the Sylvan Observatory, you study the impact of celestial events on nature magic." << endl;
			break;
		default:
			cout << "You wander around and find yourself back at the starting point." << endl;
			break;
	}
}

void exploreLifeFaction2() {
	cout << "You are exploring the School of Life, Faction of the Verdant Circle." << endl;
	cout << "1. The Restoration Hall - A workshop equipped with magical tools for environmental repair and rejuvenation." << endl;
	cout << "2. The Community Pavilion - A vibrant gathering space designed for fellow wizards to connect with each other." << endl;
	cout << "3. The Arborist's Workshop - Training area for working directly with living trees and plants." << endl;

	int choice;
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "In the Restoration Hall, you learn methods for healing and restoring damaged ecosystems!" << endl;
			break;
		case 2:
			cout << "At the Community Pavilion, you use life magic to advocate for environmental causes!" << endl;
			break;
		case 3:
			cout << "In the Arborist's Workshop, you learn techniques for nurturing and magically enhancing trees!" << endl;
			break;
		default:
			cout << "You wander around and find yourself back at the starting point." << endl;
			break;
	}
}

void exploreLifeFaction3() {
	cout << "You are exploring the School of Life, Faction of the Eternal Bloom Council." << endl;
	cout << "1. The Eternal Sanctum - A tranquil, sacred space adorned with serene gardens for meditation." << endl;
	cout << "2. The Sacred Reflection Pool - A enchanted pool used for reflection." << endl;
	cout << "3. The Celestial Dome - The central gathering place of the Eternal Bloom Council." << endl;

	int choice;
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "At the Eternal Sanctum, you learn techniques for aligning cosmic and natural rhythms!" << endl;
			break;
		case 2:
			cout << "At the Sacred Reflection Pool, you reveal insights and visions about your future self!" << endl;
			break;
		case 3:
			cout << "In the Celestial Dome, you learn the Council's philosphies of eternal growth." << endl;
			break;
		default:
			cout << "You wander around and find yourself back at the starting point." << endl;
			break;
	}
}
