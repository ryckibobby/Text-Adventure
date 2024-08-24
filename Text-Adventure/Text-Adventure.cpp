#include <iostream>
#include <string>
#include <vector>

using namespace std;

//function faction declarations 
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

//learn and quest function
void learnMagic(const string& school);
void embarkQuest(const string& school, const Friend& friendChosen); 


class Player {
	public:
		string name;
		vector<Item> inventory; //store invetory
		vector<Skill> skills; //store skills

		Player(const string& n) : name(n) {}

		void addItem(const Item& item) {
			
			cout << "Item added: " << item.name << " - " << item.description << endl;
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
		void addSkill(const string& skillName) {
			//check if the skill exists
			for (const Skill& skill : skills) {
				if (skill.name == skillName) {
					cout << "You already have the skill: " << skillName << ".\n";
					return;
				}
			}
			//add skills
			string skillDescription; //description for skill
			if (skillName == "Fire Mastery") {
				skillDescription = "Enhances your control over fire magic.";
			}
			else if (skillName == "Cold Resistance") {
				skillDescription = "Increases your resistance to cold environments and ice magic.";
			}
			else if (skillName == "Phoenix's Blessing") {
				skillDescription = "Grants you the ability to regenerate health faster.";
			}
			else if (skillName == "Flame Burst") {
				skillDescription = "A powerful fire spire spell that creates an explosion of flames.";
			}
			else if (skillName == "Dragon's Protection") {
				skillDescription = "Grants increased defence and resistance to dragon-related attacks.";
			}
			skills.push_back(Skill(skillName, skillDescription));
			cout << "You have learned a new skill: " << skillName << ".\n";
		}
		void showSkills()const {
			cout << "Skills:\n";
			for (const Skill& skill : skills) {
				cout << "- " << skill.name << ": " << skill.description << endl;
			}
		}
};

class Skill {
	public:
		string name;
		string description;

		Skill(const string& name, const string& description) : name(name), description(description) {}
};
class Item {
	public:
		int id;
		string name;
		string description;

		Item(int itemId, string itemName, string itemDescription) : id(itemId), name(itemName), description(itemDescription) {}


};

class Friend {
	public:
		string name;
		string specialty;
};

void addItemToInventory(const Item& item) {
	cout << "Item" << item.name << "with ID" << item.id << " added to inventory." << endl;
	cout << "Description: " << item.description << endl;
}

int main()
{
	string playerName;
	char playAgain;

	do {
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
		}
		else if (school == "Ice") {
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
		}
		else if (school == "Life") {
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
		}
		else if (school == "Death") {
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
		}
		else if (school == "Storm") {
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
		}
		else if (school == "Illusion") {
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
		}
		else {
			cout << "Invalid school choice." << endl;
		}

		cout << "Would youl like to learn magic, " << playerName << "? (1 for Yes, 0 for No)" << endl;
		int learnChoice;
		cin >> learnChoice;
		cin.ignore();

		if (learnChoice == 1) {
			learnMagic(school, player);
		}

		cout << "Would you like to embark on a quest, " << playerName << "? (1 for Yes, 0 for No)" << endl;
		int questChoice;
		cin >> questChoice;
		cin.ignore();

		if (questChoice == 1) {
			Friend defaultFriend;
			defaultFriend.name = "Bob";
			defaultFriend.specialty = "None";
			embarkQuest(school, defaultFriend, player);
		}

		cout << "Would you like to view your inventory, " << playerName << "? (1 for Yes, 0 for No)" << endl;
		int inventoryChoice;
		cin >> inventoryChoice;
		if (inventoryChoice == 1) {
			player.showInventory();
		}

		cout << "Do you want to play again? (y/n): ";
		cin >> playAgain;
		cin.ignore();

		cout << endl;

	} while (playAgain == 'y' || playAgain == 'Y');

	cout << "Thanks for playing!" << endl;

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
void learnMagic(const string& school, Player& player) {
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
void embarkQuest(const string& school, const Friend& friendChosen, Player& player){
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

	// output specific quest details and how the friend will help
	int questDecision;
	if (questChoice == 1) {
		if (school == "Fire") {
			cout << "The Burning Mountain" << endl;
			cout << "	The ground trembles as you approach the awakening volcano. The air grows hotter with each step, and the roar of molten rock echoes in your ears."
				<< "You and	" << friendChosen.name << "must use your fire magic to prevent the impending disaster. With the power of the Inferno Knights at your side, "
				<< "you venture into the heart of the volcano, seeking to calm its fury." << endl;

			cout << "1. Use your fire magic to contain the lava flow.\n";
			cout << "2. Seek out the Fire Spirit for aid.\n";
			cout << "3. Retreat to the school dorm and prepare for another attempt. \n";
			cout << "What do you choose to do? (1, 2, or 3):";
			cin >> questDecision;
			cin.ignore();

			if (questDecision == 1) {
				cout << "You bravely channel your fire magic, directiong the lava away from the village. In the gratitude, the villagers reward you with a Phoenix Feather.\n";
				//creating the item object 
				Item phoenixFeather(1, "Phoenix Feather", "A feather from the legendary phoenix.");

				//adding item to inventory
				addItemToInventory(phoenixFeather);

				//continue quest
				cout << "As you leave, you notice the volcano rumbling again. Do you: \n";
				cout << "1. Investigate the cause.\n";
				cout << "2. Continue back to the village.\n";
				cin >> questDecision;
				cin.ignore();

				if (questDecision == 1) {
					cout << "You discover an ancient artifact at the volano's core, radianting immense power. Do you:\n";
					cout << "1. Attempt to harness its power.\n";
					cout << "2. Destroy it to prevent further eruptions.\n";
					cin >> questDecision;
					cin.ignore();

					if (questDecision == 1) {
						cout << "The artifact grants you the skill 'Volcanic Might,' emjamcomg your fire magic significantly.\n";
						player.addSkill("Spirit Bond");
					}
					else {
						cout << "Destroying the artifact stabilizes the volcano permanently. The villagers reward you with a Fireproof Cloak.\n ";
						Item fireproofCloak(1, "Fireproof Cloak", "A cloak that offers protection against extreme heat.");
						addItemToInventory(fireproofCloak);
					}
				}
				else {
					cout << "You return to the village safely, but the volcano remains unstable, posing a future threat.\n";
				}

			}
			else if (questDecision == 2) {
				cout << "The Fire Spirit grants you the skill 'Fire Mastery,' increasing your control over fire magic. Do you:\n";
				player.addSkill("Fire Mastery");
				cout << "1. Ask the spirit to join you on your quest.\n";
				cout << "2. Leave the spirit to guard the volcano.\n";
				cin >> questDecision;
				cin.ignore();

				if (questDecision == 1) {
					cout << "The Fire Spirit agrees to accompany you, granting you a permanent boost to your fire magic.\n";
					player.addSkill("Spirit Bond");
				}
				else {
					cout << "The spirit remains at the volcano, ensuring it stays dormant, The village is safe, and you gain the 'Guardian of Fire' title.\n";
					//add title class
					player.addTitle("Guardian of Fire");
				}
			}
			else {
				cout << "You decide to retreat and plan your next move. Back at the dorm, you prepare for another day. \n";
				return;
			}
		}
	}
		else if (school == "Ice") {
			cout << " The Frozen Tundra" << endl;
			cout << "	The once verdant forest now lies under a thick blanket of ice. The cold bires at your skin, and the trees stand as liefless statues. "
				<< "you can feel the dark magic sapping the life from everything around you. " << friendChosen.name << "uses their healing magic to bolster your strength, "
				<< "and together you work to cleanse the grove and uncover the dark force behind its demise." << endl;

			cout << "1. Use your ice magic to melt the ice and restore the forest.\n";
			cout << "2. Find the Ice Elemental causing the freeze and confront it. \n";
			cout << "3. Return to the school dorm to gather more supplies.\n";
			cout << "What do you choose to do? (1, 2, or 3): ";
			cin >> questDecision;
			cin.ignore();

			if (questDecision == 1) {
				cout << "You focus your energy and melt the ice, freezing the forest from its forzen state. The forest spirits thank you with an enchanted Frost Amulet.\n";
				Item frostAmulet(1, "Frost Amulet", "An amulet infused with the power of frost.");
				addItemToInventory(frostAmulet);

				cout << "However, you notice a lingering coldness in the air. Do you:\n";
				cout << "1. Investigate the source of the cold.\n";
				cout << "2. Ignore it and return to the village.\n";
				cin >> questDecision;
				cin.ignore();

				if (questDecision == 1) {
					cout << "You discover a diden cave, where a powerful Ice Golem lies dormant. Do you:\n";
					cout << "1. Attempt to awaken the golem as an ally.\n";
					cout << "2. Seal the cave to prevent the golem from causing harm.\n";
					cin >> questDecision;
					cin.ignore();

					if (questDecision == 1) {
						cout << "The golem awakens and, impressed by your strength, offers to serve as your protector. \n";
						//add companion class
						player.addCompanion("Ice Golem");
					}
					else {
						cout << "You seal the cave, ensuring the golem remains asleep, and gain the 'Protector of the Forest' title.\n";
						player.addTitle("Protector of the Forest");
					}
				}
				else {
					cout << "You return to the village but the forest's recovery is slow and uncertain.\n";
				}

			}
			else if (questDecision == 2) {
				cout << "The Ice Elemental reveals itself, but it is not the source of the curse. Aftera fierce battle, you gain the 'Ice Elemental's Blessing' skill.\n";
				player.addSkill("Ice Elemental's Blessing");

				cout << "Do you: \n";
				cout << "1. Ask the elemental for guidance on the true source.\n";
				cout << "2. Leave the elemntal in peace and return to the village.\n";
				cin >> questDecision;
				cin.ignore();

				if (questDecision == 1) {
					cout << "The elemental guides you to an ancient shrine, where you discover the true source of the dark magic. "
						<< "You cleanse the shrine, earning the respect of the forest spirits.\n";
					player.addTitle("Forest Spirits Ally");
				}
			}
			else {
				cout << "You return to the village, content with your victory, but the source of the dark magic remains hidden.\n";
			}
		}
		else if (questDecision == 3) {
			cout << "You decide to retreat and gather more supplies. Back at the dorm, you prepare for another day. \n";
			return;
		}
		else if (school == "Life") {
			cout << "The Enchanted Grove" << endl;
			cout << "   The once thriving grove is now a shadow of its former self. The trees wilt, and the flowers no longer bloom. As you step into the grove, "
				<< "you can feel the dark magic sapping the life from everything around you. " << friendChosen.name << " uses their healing magic to bolster your strength, "
				<< "and together you work to cleanse the grove and uncover the dark force behind its demise." << endl;

			cout << "1. Use your life magic to heal the land." << endl;
			cout << "2. Search for the source of the dark magic." << endl;
			cout << "3. Retreat to the school dorm and prepare for another attmept." << endl;
			cout << "What do you choose to do? (1, 2, or 3): " <<endl;

			int choice;
			cin >> choice;

			if (choice == 1) {
				cout << "You channel your life magic into the grove, reviving the plants and cleansing the soil. The forest spirits reward you with the 'Nature's Gift' skill.\n";
				player.addSkill("Nature's Embrace");

				cout << "However, you sense the curse is still present. Do you:\n";
				cout << "1. Investigate the deeper parts of the grove.\n";
				cout << "2. Return to the village and report your success.\n";
				cin >> questDecision;
				cin.ignore();

				if (questDecision == 1) {
					cout << "You discover the hidden altar, where a dark ritual is being peformed. Do you:\n";
					cout << "1. Disrupt the ritual and cleanse the altar.\n";
					cout << "2. Confront the dark sorcerer performing the ritual.\n";
					cin >> questDecision;
					cin.ignore();

					if (questDecision == 1) {
						cout << "You cleanse the altar, banishing the dark magic. The spirits grant tou the 'Grove Protector' title.\n";
						player.addTitle("Grove Protector");
					}
					else {
						cout << "You confront the sorcerer, and after a fierce battle, you defeat them, earning the 'Dark Magic Bane' title.\n";
						player.addTitle("Dark Magic Bane");
					}
				}
				else {
					cout << "You return to the village, bnut the grove remains vulnerable to future curses.\n";
				}
			}
			else if (choice == 2) {
				cout << "You search the grove and find the source of the dark magic: a cursed artifact. Do you:\n";
				cout << "1. Attempt to purifty the artifcat.\n";
				cout << "2. Destroy the artifact.\n";
				cin >> questDecision;
				cin.ignore();

				if (questDecision == 1) {
					cout << "Purifying the artifact cleanses the curse, but at the cost of your own life force. You gain the 'Cursed Purifier' skill.\n";
					player.addSkill("Cursed Purifier");
				}
				else {
					cout << "Destroying the artifact lifts the curse completely, and the grove flourishes once more. The spirits grant you the 'Life Guardian' title.\n";
					player.addTitle("Life Guardian");
				}
			}
			else {
				cout << "You decide to retreat and plan your next move. Back at the dorm, you prepare for another day.\n";
				return;
				}
			}
		}
	else if (school == "Death") {
		cout << "The Haunted Crypt" << endl;
		cout << "   The ancient crypt looms before you, its entrance guarded by restless spirits. The air is thick with the scent of decay, and the whispers of the dead "
			<< "fill your mind. With " << friendChosen.name << " by your side, you enter the crypt, ready to confront the tormented souls and lay them to rest." << endl;

		cout << "1. Use your necromancy to communicate with the spirits and calm them." << endl;
		cout << "2. 2. Search for the source of the unrest." << endl;
		cout << "3. Retreat to the school dorm and prepare for another attempt." << endl;
		cout << "What do you choose to do? (1, 2, or 3): ";
		cin >> questDecision;
		cin.ignore();

		if (questDecision == 1) {
			cout << "You succesfully communicate with the spirits and help them find peace. In gratitude, they grant you the 'Spirit Whisperer' skill.\n";
			player.addSkill("Spirit Whisperer");

			cout << "However, you sense a deeper unrest. Do you:\n";
			cout << "1. Investigate the lower levels of the crypt.\n";
			cout << "2. Leave the crypt and return to the village.\n";
			cin >> questDecision;
			cin.ignore();

			if (questDecision == 1) {
				cout << "You find a powerful spirit trapped by a curse. Do you:\n";
				cout << "1. Free the spirit from its torment.\n";
				cout << "2. Bind the spirit to your will.\n";
				cin >> questDecision;
				cin.ignore();

				if (questDecision == 1) {
					cout << "Freeing the spirit lifts the curse on the crypt, and the spirit grants you the 'Crypt Guardian' title.\n";
					player.addTitle("Crypt Guardian");
				}
				else {
					cout << "Binding the spirit to your will grants you immense power, but at a cost to your own soul. You gain the 'Soul Binder' skill.\n";
					player.addSkill("Soul Binder");
				}
			}
			else {
				cout << "You return to the village, but the crypt remains a place of unrest.\n";
			}
		} 
		else if (questDecision == 2) {
			cout << "You search the crypt and find the source of the unrest: a cursed relic. Do you:\n";
			cout << "1. Attempt to purify the relic.\n";
			cout << "2. Destroy the relic.\n";
			cin >> questDecision;
			cin.ignore();

			if (questDecision == 1) {
				cout << "Purifying the relic calms the spirits, but at the cost of some of your own vitality. You gain the 'Cursed Relic Purifier' skill.\n";
				player.addSkill("Cursed Relic Purifier");
			}
			else {
				cout << "Destroying the relic ends the unrest, and the crypt returns to peace. The spirits grant you the 'Relic Destroyer' title.\n";
				player.addTitle("Relic Destroyer");
			}
		}
		else {
			cout << "You decide to retreat and plan your next move. Back at the dorm, you prepare for another day.\n";
			return;
		}
	}
		else if (school == "Storm") {
			cout << "The Tempest Sea" << endl;
			cout << "The storm rages on, with waves crashing against the shore and lightning splitting the sky. You and " << friendChosen.name
				<< " must command the storm's power to calm the seas and save the coastal towns. The Thunder God himself watches over this trial, "
				<< "and only those with true mastery over the storm will prevail." << endl;

			cout << "1. Use your storm magic to calm the winds and waves.\n";
			cout << "2. Seek out the Thunder God's guidance.\n";
			cout << "3. Retreat to the school dorm and prepare for another attempt. \n";
			cout << "What do you choose to do? (1, 2, or 3): ";
			cin >> questDecision;
			cin.ignore();

			if (questDecision == 1) {
				cout << "You focus your storm magic, gradually calming the winds and waves. The Thunder God grants you the 'Stormbringer' title in recognition of your skill.\n";
				player.addTitle("Stormbringer");

				cout << "However, the storm's energy lingers in the air. Do you:\n";
				cout << "1. Investigate the source of the storm's power.\n";
				cout << "2. Return to the village and rest.\n";
				cin >> questDecision;
				cin.ignore();

				if (questDecision == 1) {
					cout << "You discover an ancient artifact generating the storm's power. Do you:\n";
					cout << "1. Harness its power to strengthen your storm magic.\n";
					cout << "2. Destroy the artifact to prevent future storms.\n";
					cin >> questDecision;
					cin.ignore();

					if (questDecision == 1) {
						cout << "Harnessing the artifact's power greatly enhances your storm magic, granting you the 'Tempest Master' skill.\n";
						player.addSkill("Tempest Master");
					}
					else {
						cout << "Destroying the artifact stabilizes the region's weather, and you are hailed as a hero by the coastal towns. "
							<< "The townspeople gift you a Storm Pendant as a token of their gratitude.\n";
						Item stormPendant(1, "Storm Pendant", "A pendant that enhances storm magic.");
						addItemToInventory(stormPendant);
					}
				}
				else {
					cout << "You return to the village, but the storm's power remains a lingering threat.\n";
				}
			}
	}
		else if (school == "Illusion") {
			cout << "The Maze of Mirrors" << endl;
			cout << "The labyrinth is a disorienting place of shifting reflections and illusions. You and " << friendChosen.name
				<< " must navigate its twists and turns to uncover the truth hidden within. Only by mastering the art of illusion can you find the way out." << endl;

			cout << "1. Use your illusion magic to reveal the true path.\n";
			cout << "2. Follow the echoes of your reflection.\n";
			cout << "3. Retreat to the school dorm and prepare for another attempt. \n";
			cout << "What do you choose to do? (1, 2, or 3): ";
			cin >> questDecision;
			cin.ignore();

		}
	else if (questChoice == 2) {
		if (school == "Fire") {
			cout << "The Phoenix's Rebirth" << endl;
			cout << "   Deep within the heart of a fiery canyon, the legendary phoenix is said to reside. The air is thick with the scent of sulfur, and the ground is scorched. "
				<< "You and " << friendChosen.name << " journey to find the phoenix, hoping to gain its trust and learn the secrets of eternal flame. "
				<< "The path is treacherous, but the rewards could be unimaginable." << endl;

			 cout << "1. Approach the Phoenix and attempt to bond with it.\n";
            cout << "2. Search the canyon for ancient scrolls containing fire magic secrets.\n";
            cout << "3. Return to the school dorm to rest and reconsider your strategy.\n";
            cout << "What do you choose to do? (1, 2, or 3): ";
            cin >> questDecision;
            cin.ignore();

            if (questDecision == 1) {
                cout << "The Phoenix accepts your bond, and in return, grants you the skill 'Phoenix's Blessing.'\n";
                player.addSkill("Phoenix's Blessing");
            } else if (questDecision == 2) {
                cout << "You find an ancient scroll and learn a new spell: 'Flame Burst.'\n";
                player.addSkill("Flame Burst");
            } else if (questDecision == 3) {
                cout << "You decide to retreat and rest. Back at the dorm, you prepare for another day.\n";
                return;
            }

		}
		else if (school == "Ice") {
			cout << "The Ice Dragon" << endl;
			cout << "   High in the frozen mountains, an ancient Ice dragon is said to sleep. The villagers speak of its power with both awe and fear. "
				<< "You and " << friendChosen.name << " set out to find the dragon, your every step crunching on the icy ground. Will you seek to ally with the dragon, "
				<< "or must you defeat it to protect your realm?" << endl;

			cout << "1. Attempt to communicate with the Ice Dragon and form an alliance.\n";
			cout << "2. Engage the Ice Dragon in battle to prove your strength.\n";
			cout << "3. Return to the school dorm to seek advice from your mentors.\n";
			cout << "What do you choose to do? (1, 2, or 3): ";
			cin >> questDecision;
			cin.ignore();

			if (questDecision == 1) {
				cout << "The Ice Dragon agrees to an alliance, bestowing upon you the skill 'Dragon's Protection.'\n";
				player.addSkill("Dragon's Protection");
			}
			else if (questDecision == 2) {
				cout << "You defeat the Ice Dragon in a fierce battle, earning a Dragon Scale Shield as a reward.\n";
				Item dragonScaleShield(1, "Dragon Scale Shield", "A shield made from the scales of an Ice Dragon.");
				addItemToInventory(dragonScaleShield);
			}
			else if (questDecision == 3) {
				cout << "You decide to retreat and seek advice. Back at the dorm, you prepare for another day.\n";
				return;
			}

		}
		else if (school == "Life") {
			cout << "The Great Forest Guardian" << endl;
			cout << "   The forest trembles under the footsteps of the corrupted guardian. Once a protector of nature, it now threatens the very land it once saved. "
				<< friendChosen.name << " aids you in purifying the guardian's spirit, hoping to restore its role as the forest's protector." << endl;

			cout << "You have purified the Great Forest Guardian. What would you like to do next?" << endl;
			cout << "1. Learn a new skill: 'Guardian's Blessing' - Grants increased protection from natural elements." << endl;
			cout << "2. Receive an item: 'Mystic Bark' - A piece of the Guardian's bark with magical properties." << endl;
			cout << "3. Return to your dorm." << endl;

			int choice;
			cin >> choice;

			if (choice == 1) {
				player.addSkill("Guardian's Blessing");
			}
			else if (choice == 2) {
				Item mysticBark(1, "Mystic Bark", "A piece of magical bark from the Great Forest Guardian.");
				addItemToInventory(mysticBark);
			}
			else if (choice == 3) {
				cout << "You return to your dorm to rest and reflect on your adventure." << endl;
			}
			else {
				cout << "Invalid choice. Returning to your dorm." << endl;
			}

		}
		else if (school == "Death") {
			cout << "The Reaper's Scythe" << endl;
			cout << "   The Reaper's Scythe, a powerful artifact capable of bringing death to all who oppose it, has been stolen. "
				<< "You and " << friendChosen.name << " track down the thief, knowing that the consequences of failure could be catastrophic. "
				<< "The journey will be perilous, but the fate of the world may rest on your success." << endl;

			cout << "You have recovered the Reaper's Scythe. What would you like to do next?" << endl;
			cout << "1. Learn a new skill: 'Death's Touch' - Enhances your necromantic powers." << endl;
			cout << "2. Receive an item: 'Grim Cloak' - A cloak that offers protection against dark magic." << endl;
			cout << "3. Return to your dorm." << endl;

			int choice;
			cin >> choice;

			if (choice == 1) {
				player.addSkill("Death's Touch");
			}
			else if (choice == 2) {
				Item grimCloak(1, "Grim Cloak", "A cloak that shields the wearer from dark forces.");
				addItemToInventory(grimCloak);
			}
			else if (choice == 3) {
				cout << "You return to your dorm to rest and reflect on your adventure." << endl;
			}
			else {
				cout << "Invalid choice. Returning to your dorm." << endl;
			}

		}
		else if (school == "Storm") {
			cout << "The Thunder God's Challenge" << endl;
			cout << "   On a mountaintop where the storm clouds gather, the Thunder God awaits those who would prove themselves worthy. "
				<< friendChosen.name << " stands beside you as you face the god's challenges, each one designed to test your mastery of storm magic. "
				<< "Only by overcoming these trials can you earn the Thunder God's favor." << endl;

			cout << "You have completed the Thunder God's Challenge. What would you like to do next?" << endl;
			cout << "1. Learn a new skill: 'Thunder Strike' - A powerful lightning attack spell." << endl;
			cout << "2. Receive an item: 'Storm Amulet' - An amulet that protects against electrical attacks." << endl;
			cout << "3. Return to your dorm." << endl;

			int choice;
			cin >> choice;

			if (choice == 1) {
				player.addSkill("Thunder Strike");
			}
			else if (choice == 2) {
				Item stormAmulet(1, "Storm Amulet", "An amulet that offers protection from lightning.");
				addItemToInventory(stormAmulet);
			}
			else if (choice == 3) {
				cout << "You return to your dorm to rest and reflect on your adventure." << endl;
			}
			else {
				cout << "Invalid choice. Returning to your dorm." << endl;
			}

		}
		else if (school == "Illusion") {
			cout << "The Phantom's Masquerade" << endl;
			cout << "   The grand ballroom is filled with masked figures, each one a mystery. The Phantom's Masquerade is known for its intrigue, "
				<< "and tonight you and " << friendChosen.name << " must uncover the true identities of the guests. "
				<< "But beware—nothing is as it seems, and the night holds many secrets." << endl;

			cout << "You have uncovered the plot at the Phantom's Masquerade. What would you like to do next?" << endl;
			cout << "1. Learn a new skill: 'Veil of Shadows' - A spell that makes you invisible for a short period." << endl;
			cout << "2. Receive an item: 'Mask of the Phantom' - A mask that enhances your illusion magic." << endl;
			cout << "3. Return to your dorm." << endl;

			int choice;
			cin >> choice;

			if (choice == 1) {
				player.addSkill("Veil of Shadows");
			}
			else if (choice == 2) {
				Item maskPhantom(1, "Mask of the Phantom", "A mask that boosts your illusionary abilities.");
				addItemToInventory(maskPhantom);
			}
			else if (choice == 3) {
				cout << "You return to your dorm to rest and reflect on your adventure." << endl;
			}
			else {
				cout << "Invalid choice. Returning to your dorm." << endl;
			}
		}
	}

	cout << "You and " << friendChosen.name << " complete the quest!" << endl;
}


