#include <iostream>
#include <string>
#include <vector>

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
void embarkQuest(const string& school, const Friend& friendChosen); 

class Player {
	public:
		string name;
		vector<Item> inventory;

		Player(const string& n) : name(n) {}

		void addItem(const Item& item) {
			inventory.push_back(item);
			cout << item.name << "has been added to your inventory." << endl;
		}

		void showInventory() const {
			if (inventory.empty()) {
				cout << "your inventory is empty." << endl;
				return;
			}
			cout << "Your inventory:" << endl;
			for (const auto& item : inventory) {
				cout << "- " << item.name << ": " << item.description << endl;
			}
		}
};

class Item {
	public:
		string name;
		string description;

		Item(const string& n, const string& d) : name(n), description(d) {}


};

class Friend {
	public:
		string name;
		string specialty;
};

int main()
{
	string playerName;

	cout << "Welcome to the Wizard's Adventure!" << endl;
	cout << "What is your name, young wizard?" << endl;
	getline(cin, playerName);

	Player player(playerName);

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
	cin.ignore();


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
	cin.ignore();


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
	cin.ignore();

	if (learnChoice == 1) {
		learnMagic(school);
	}

	cout << "Would you like to embark on a quest, " << playerName << "? (1 for Yes, 0 for No)" << endl;
	int questChoice;
	cin >> questChoice;
	cin.ignore();

	if (questChoice == 1) {
		Friend defaultFriend;
		defaultFriend.name = "Bob";
		defaultFriend.specialty = "None";
		embarkQuest(school, defaultFriend);
	}

	cout << "Would you like to view your inventory, " << playerName << "? (1 for Yes, 0 for No)" << endl;
	int inventoryChoice;
	cin >> inventoryChoice;
	if (inventoryChoice == 1) {
		player.showInventory();
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
void exploreDeathFaction1() {
	cout << "You are exploring the School of Death, Faction of the Necrotic Enclave." << endl;
	cout << "1. The Mortuary Sanctum - A chamber where the most profound necromantic rituals are performed." << endl;
	cout << "2. The Soulforge - A alchemical and magical workshop where necromancers create and enhance dark artifacts." << endl;
	cout << "3. The Hall of Wraiths - A arena dedicated to practicing and perfecting the control of wraiths." << endl;

	int choice;
	cin  >> choice;

	switch (choice) {
		case 1:
			cout << "At the Mortuary Sanctum, you learn techniques for performing high-level necromatic rituals!" << endl;
			break;
		case 2:
			cout << "In the Soulforge, you learn skills for crafting and imbuing necromantic artifacts with powerful enchantments!" << endl;
			break;
		case 3:
			cout << "In the Hall of Wraiths, you learn methods for engaging in and winning battles against ghostly adversaries." << endl;
			break;
		default:
			cout << "You wander around and find yourself back at the starting point." << endl;
			break;
	}
}

void exploreDeathFaction2() {
	cout << "You are exploring the School of Death, Faction of the Shadowveil Syndicate." << endl;
	cout << "1. The Twilight Spire - A shadowy tower where members of the Syndicate practice dark magic." << endl;
	cout << "2. The Obsidian Vault - A secure location where the Syndicate store important artifacts." << endl;
	cout << "3. The Shadowveil Garden - A concealed garden where shadow magic flourishes and dark plants are cultivated." << endl;

	int choice;
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "At the Twilight Spire, you learn spells that manipulate darkness and shadows." << endl;
			break;
		case 2:
			cout << "In the Obsidian Vault, you learn techniques for maintaining powerful magical artifacts." << endl;
			break;
		case 3:
			cout << "In the Shadowveil Garden, you practice enhancing one's connection to shadow magic" << endl;
			break;
		default:
			cout << "You wander around and find yourself back at the starting point." << endl;
			break;
	}
}

void exploreDeathFaction3() {
	cout << "You are exploring the School of Death, Faction of the Gravebound Cult." << endl;
	cout << "1. The Catacomb Arena - A underground combat training area designed to simulate necromantic duels." << endl;
	cout << "2. The Eternal Vigil - A reflective space where Cult members meditate on death and afterlife." << endl;
	cout << "3. The Gravebound Forge - A specialized workshop where members craft and enchant weapon." << endl;

	int choice;
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "At the Catacomb Arena. you train your necromantic powers and summon undead allies to assist you." << endl;
			break;
		case 2:
			cout << "In the Eternal Vigil, you gain a in-depth exploration on how to harness, the nature of death and the afterlife, for magical purposes." << endl;
			break;
		case 3:
			cout << "In the Gravebound Forge, you learn skills for crafting and enchanting items with necromantic properties." << endl;
			break;
		default:
			cout << "You wander around and find yourself back at the starting point." << endl;
			break;
	}
}

void exploreStormFaction1() {
	cout << "You are exploring the School of Storm, Faction of the StormCaller Brotherhood." << endl;
	cout << "1. The Thunderbolt Arena - An open air combat training ground where your storm magic is put to the test." << endl;
	cout << "2. The Eye of the Storm - A central observatory and training area designed to simulate the heart of a storm." << endl;
	cout << "3. The Stormcaller's Archive - An expansive, dimly lit library filled with ancient tomes, scrolls, and artifacts." << endl;

	int choice;
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "At the Thunderbolt Arena, you learn combat techniques incorporating lightning and storm magic!" << endl;
			break;
		case 2:
			cout << "In the Eye of the Storm, you learn how to harness and focus storm energies!" << endl;
			break;
		case 3:
			cout << "In the Stormcaller's Archive, you gain knowledge of storm magic, including the study of legendary and ancient stormcallers" << endl;
			break;
		default:
			cout << "You wander around and find yourself back at the starting point." << endl;
			break;
	}
}
void exploreStormFaction2() {
	cout << "You are exploring the School of Storm, Faction of the Thunderstrike Circle." << endl;
	cout << "1. The Lighning Nexus - A high energy chamber with conductive pathways that channel and amplify electrical energy." << endl;
	cout << "2. The Volt Forge - A specialized forge where electrical energy is used to enchant and craft items." << endl;
	cout << "3. The Electromancer's Den - A secluded, heavily warded room designed for practicing and amplifying electrical energies." << endl;

	int choice;
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "In the Lightning Nexus, you gain a new mastery of electrical energy creating electric fields, bolts, and discharges." << endl;
			break;
		case 2:
			cout << "In the Volt Forge, you learn about the creation of electrical artifacts." << endl;
			break;
		case 3:
			cout << "In the Electromancer's Den, you train with fellow wizards while also amplifying your electrical energy." << endl;
			break;
		default:
			cout << "You wander around and find yourself back at the starting point." << endl;
			break;
	}
}

void exploreStormFaction3() {
	cout << "You are exploring the School of Storm, Faction of the Electroflare Consortium." << endl;
	cout << "1. The Electroflare Lab - A laboratory filled with magical devices and experimental apparatus for studying and harnessing electrical magic." << endl;
	cout << "2. The Lightning Hall - A grand hall where various applications of electrical magic are demonstrated." << endl;
	cout << "3. The Electroflare Archives - A comprehensive repository of magical texts, research papers, and historical records about electrical and arcane magic." << endl;

	int choice;
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "In the Electroflare Lab, you conduct experiments to seek improvements in electrical magic!" << endl;
			break;
		case 2:
			cout << "At the Lightning Hall, you gain a deeper knowledge of electrical mage from fellow wizards who demonstrated!" << endl;
			break;
		case 3:
			cout << "In the Electroflare Archives, you learn about the previous Electroflare Consortium." << endl;
			break;
		default:
			cout << "You wander around and find yourself back at the starting point." << endl;
			break;
	}
}

void exploreIllusionFaction1() {
	cout << "You are exploring the School of Illusion, Faction of the Veilweaver Guild." << endl;
	cout << "1. Mirrorfall Cavern - A cavern filled with reflective surfacts, where every step leads to a new reflection." << endl;
	cout << "2. Labyrinth of Veils - A twister, ever-changing labyrinth that tests a wizard's skill to new reflections." << endl;
	cout << "3. Hall of Shifting Realms - A grand hall that is filled with floating orbs that represent different realities." << endl;

	int choice;
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "In the Mirrorfall Cavern, you practice creating mirror images!" << endl;
			break;
		case 2:
			cout << "In the Labyrinth of Veils, you master the art of disorienting foes, trapping them in intricate mazes!" << endl;
			break;
		case 3:
			cout << "At the Hall of Shifting Realms, you learn to manipulate space, folding and weaving dimensions to create illusions!" << endl;
			break;
		default:
			cout << "You wander around and find yourself back at the starting point." << endl;
			break;
	}
}

void exploreIllusionFaction2() {
	cout << "You are exploring the School of Illusion, Faction of the Mirrage Conclave." << endl;
	cout << "1. The Desert of Fading Echoes - A vast, sandy expanse where the heat distorts reality." << endl;
	cout << "2. Oasis of Shattered Reflections - A tranquil oasis where the water itself is an illusion." << endl;
	cout << "3. The Hall of Receding Horizons - A seemingly infinite hall where the horizon is always just out." << endl;

	int choice;
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "At the Desert of Fading Echoes, you train in crafting mirages, using the environment's natural illusions to deceive." << endl;
			break;
		case 2:
			cout << "At the Oasis of Shattered Reflections, you learn to manipulate water and reflections, creating illusions that confuse." << endl;
			break;
		case 3:
			cout << "In the Hall of Receding Horizons, you study the manipulation of perspective and distance, creating illusions that stretch." << endl;
			break;
		default:
			cout << "You wander around and find yourself back at the starting point." << endl;
			break;
	}
}

void exploreIllusionFaction3() {
	cout << "You are exploring the School of Illusion, Faction of the Phantomveil Assembly." << endl;
	cout << "1. The Phantom's Mask - A secluded chamber filled with masks, each represening a different identity." << endl;
	cout << "2. Whispering Woods - A dense forest where the trees themselves seem to move and whisper." << endl;
	cout << "3. Ethereal Theater - A grand theater where wizards perform illusions that affect large audiences." << endl;

	int choice;
	cin >> choice;

	switch (choice) {
		case 1:
			cout << "In the Phantom's Mask, you practive the art of disguise, creating illusions that completely alter your appearance." << endl;
			break;
		case 2:
			cout << "At the Whispering Woods, you study the creation of natural illusions, blending magic with the environment to confuse." << endl;
			break;
		case 3:
			cout << "In the Ethereal Theater, you learn to craft elaborate, multilayered illusions that captivate and deceive large crowds!" << endl;
			break;
		default:
			cout << "You wander around and find yourself back at the starting point." << endl;
			break;
	}
}

//function to learn magic
void learnMagic(const string& school) {
	cout << "Welcome to the " << school << "School of Magic!" << endl;

	vector<string> classes;
	if (school == "Fire") {
		classes = { "Advanced Pyromancy", "Flame Conjuration", "Inferno Mastery" };
	} else if (school == "Ice") {
		classes = { "Cyromancy Basics", "Glacial Defense", "Inferno Mastery" };
	} else if (school == "Life") {
		classes = { "Herbal Healing", "Nature's Fury", "Restorative Magic" };
	} else if (school == "Death") {
		classes = { "Necromantic Rituals", "Soul Binding", "Dark Resurrection" };
	} else if (school == "Storm") {
		classes = { "Lightning Manipulation", "Thunder Calling", "Storm Summoning" };
	} else if (school == "Illusion") {
		classes = { "Mirage Crafting", "Mind Manipulation", "Phantom Projection" };
	}
	cout << "Choose a class to study:" << endl;
	for (int i = 0; i < classes.size(); ++i) {
		cout << i + 1 << ". " << classes[i] << endl;
	}

	int classChoice;
	cin >> classChoice;

	if (classChoice < 1 || classChoice > classes.size()) {
		cout << "Invalid class choice." << endl;
		return;
	}

	string chosenClass = classes[classChoice - 1];
	cout << "You have chosen to study " << chosenClass << "." << endl;

	//making friends process
	vector<Friend> potentialFriends;
	if (school == "Fire") {
		potentialFriends = { {"Blaze, Pyromancer"}, {"Ember", "Fire Dancer"}, {"Flare", "Inferno Specialist"}};
	} else if (school == "Ice") {
		potentialFriends = { {"Frost", "Cyromancer"}, {"Glaze","Ice Sculptor"},{"Chill","Blizzard Conjurer"}};
	} else if (school == "Life") {
		potentialFriends = { {"Willow","Herbalist"},{"Fern","Healer"},{"Briar","Nature Protector"} };
	} else if (school == "Death") {
		potentialFriends = { {"Shade","Necromancer"},{"Gloom","Soul Binder"},{"Relevant","Dark Alchemist"} };
	} else if (school == "Storm") {
		potentialFriends = { {"Bolt","Stormcaller"},{"Zephyr","Wind Rider"},{"Tempest","Lightning Conduction"} };
	} else if (school == "Illusion") {
		potentialFriends = { {"Shade","Illusionist"},{"Glimer","Mind Bender"},{"Mirage","Phantom Weaver"}};
	}

	cout << "During your studies, you met some fellow wizards. Who would you like to befriend?" << endl;
	for (int i = 0; i < potentialFriends.size(); ++i) {
		cout << i + 1 << ". " << potentialFriends[i].name << " - " << potentialFriends[i].specialty << endl;
	}

	int friendChoice;
	cin >> friendChoice;

	if (friendChoice < 1 || friendChoice > potentialFriends.size()) {
		cout << "You couldn't decide who to befriend, so you continue your studies alone." << endl;
	} else {
		Friend newFriend = potentialFriends[friendChoice - 1];
		cout << "You have befriended " << newFriend.name << "who specializes in " << newFriend.specialty << "." << endl;
		//store friend in friends list
	}
	cout << "You continue to learn and grow in the art of " << school << "magic." << endl;
}


//function to embark on a quest
void embarkQuest(const string& school, const Friend& friendChosen){
	cout << "You and " << friendChosen.name << "are about to embark on an exciting quest!" << endl;

	if (school == "Fire") {
		cout << "1. Quest: The Burning Mountain\n"
			<< "A dormant volcano has started to awaken, threatening the nearby villages. You must harness the power of fire to contain the eruption and save the people." << endl;

		cout << "2. Quest: The Phoenix's Rebirth\n"
			<< "A legendary phoenix has been sighted. It's your chance to gain the creature's trust and learn the secrets of eternal flame." << endl;
	}
	else if (school == "Ice") {
		cout << "1. Quest: The Frozen Tundra\n"
			<< "A once lush forest has turned into a frozen wasteland. Uncover the source of the unnatural cold and restore the balance of nature." << endl;

		cout << "2. Quest: The Ice Dragon\n"
			<< "Rumors of an ancient Ice dragon have surfaced. You must find and either subdue or ally with this powerful creature." << endl;
	}
	else if (school == "Life") {
		cout << "1. Quest: The Enchanted Grove\n"
			<< "A sacred grove is dying, its life force being drained by a mysterious dark magic. You must heal the land and uncover the culprit behind the curse." << endl;

		cout << "2. Quest: The Great Forest Guardian\n"
			<< "A gigantic creature that protects the forest that was corrupted. Purifty its spirit and restore its role as the guardian of nature." << endl;
	}
	else if (school == "Death") {
		cout << "1. Quest: The Haunted Crypt\n"
			<< "An ancient crypt is stirringwith restless spirits. Enter the crypt, communicate with the dead, and put their souls to rest." << endl;

		cout << "2. Quest: The Reaper's Scythe\n"
			<< "A powerful artifcat, the Reaper's Scythe, has been stolen. Recover it before it falls into the wrong hands and unleashes chaos on the world." << endl;
	}
	else if (school == "Storm") {
		cout << "1. Quest: The Tempest Sea\n"
			<< "   A massive storm is brewing over the ocean, endangering countless lives. Command the storm's power to calm the seas and save the coastal towns." << endl;

		cout << "2. Quest: The Thunder God's Challenge\n"
			<< "   Prove your worth to the Thunder God by completing a series of challenges that test your control over lightning and wind." << endl;

	}
	else if (school == "Illusion") {
		cout << "1. Quest: The Maze of Mirrors\n"
			<< "   An ancient labyrinth of illusions has reappeared, trapping those who enter. Navigate the maze and reveal the truth hidden within the reflections." << endl;

		cout << "2. Quest: The Phantom's Masquerade\n"
			<< "   Attend a mysterious masquerade ball where nothing is as it seems. Uncover the identities of the guests and prevent a hidden plot from coming to fruition." << endl;
	}

	int questChoice;
	cout << "Choose a quest to embark on (1 or 2): ";
	cin >> questChoice;
	cin.ignore();

	if (questChoice < 1 || questChoice > 2) {
		cout << "Invalid choice. The quest cannot proceed." << endl;
		return;
	}

	// Output specific quest details and how the friend will help
	if (questChoice == 1) {
		if (school == "Fire") {
			cout << "You and " << friendChosen.name << " travel to the Burning Mountain. "
				<< friendChosen.name << " uses their pyromancy to guide you through the scorching heat, and together you find a way to calm the volcano." << endl;

		}
		else if (school == "Ice") {
			cout << "You and " << friendChosen.name << " journey to the Frozen Tundra. "
				<< friendChosen.name << "'s mastery of ice helps you withstand the extreme cold as you work together to restore the forest's natural climate." << endl;

		}
		else if (school == "Life") {
			cout << "You and " << friendChosen.name << " venture into the Enchanted Grove. "
				<< friendChosen.name << "'s knowledge of healing magic aids you in curing the grove and lifting the dark magic curse." << endl;

		}
		else if (school == "Death") {
			cout << "You and " << friendChosen.name << " descend into the Haunted Crypt. "
				<< friendChosen.name << "'s necromantic powers allow you to communicate with the spirits, easing their unrest and solving the mystery of the crypt." << endl;

		}
		else if (school == "Storm") {
			cout << "You and " << friendChosen.name << " sail to the eye of the Tempest Sea. "
				<< friendChosen.name << "'s storm magic helps you navigate the treacherous waters and calm the raging storm." << endl;

		}
		else if (school == "Illusion") {
			cout << "You and " << friendChosen.name << " enter the Maze of Mirrors. "
				<< friendChosen.name << "'s illusionary expertise helps you distinguish reality from illusion, allowing you to uncover the maze's secrets." << endl;
		}

	}
	else if (questChoice == 2) {
		if (school == "Fire") {
			cout << "You and " << friendChosen.name << " seek out the Phoenix's Rebirth. "
				<< friendChosen.name << "'s deep connection with fire creatures aids you in gaining the phoenix's trust, and you learn the secrets of eternal flame together." << endl;

		}
		else if (school == "Ice") {
			cout << "You and " << friendChosen.name << " search for the Ice Dragon. "
				<< friendChosen.name << "'s icy skills help you track down the dragon, and together you either ally with it or defeat it to protect your realm." << endl;

		}
		else if (school == "Life") {
			cout << "You and " << friendChosen.name << " confront the Great Forest Guardian. "
				<< friendChosen.name << "'s healing magic helps purify the corrupted creature, restoring its role as protector of the forest." << endl;

		}
		else if (school == "Death") {
			cout << "You and " << friendChosen.name << " hunt for the Reaper's Scythe. "
				<< friendChosen.name << "'s knowledge of dark artifacts is crucial in tracking down the scythe before it falls into the wrong hands." << endl;

		}
		else if (school == "Storm") {
			cout << "You and " << friendChosen.name << " face the Thunder God's Challenge. "
				<< friendChosen.name << "'s mastery of lightning magic aids you in overcoming the challenges and proving your worth to the Thunder God." << endl;

		}
		else if (school == "Illusion") {
			cout << "You and " << friendChosen.name << " attend the Phantom's Masquerade. "
				<< friendChosen.name << "'s illusionary tricks help you see through the deceptions and thwart the hidden plot at the ball." << endl;
		}
	}

	cout << "Your quest was a success! You and " << friendChosen.name << " return stronger and wiser from your adventure." << endl;
}


