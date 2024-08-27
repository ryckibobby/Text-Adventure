#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Spell {
	public:
		string name;
		string description;
		int powerLevel;

		Spell(string n, string d, int p) : name(n), description(d), powerLevel(p) {}
};

class SpellList {
	private:
		vector<Spell> spells;

	public:
		void addSpell(const Spell& spell) {
			spells.push_back(spell);
		}
		void removeSpell(const string& spellName) {
			spells.erase(remove_if(spells.begin(), spells.end(),
				[&spellName](const Spell& spell) { return spell.name == spellName; }),
				spells.end());
		}
		void displaySpells() const {
			cout << "Available Spells: " << endl;
			for (const auto& spell : spells) {
				cout << "Name: " << spell.name << ", Description: " << spell.description << ", Power Level: " << spell.powerLevel << "\n";
			}
		}
		Spell* getSpell(const string& spellName) {
			for (auto& spell : spells) {
				if (spell.name == spellName) {
					return &spell;
				}
			}
			return nullptr;
		}
};

class Relationship {
	public:
		string friendName;
		mutable int affectionPoints; //determines how strong the relationship is

		Relationship(const string& name, int affection = 0) : friendName(name) , affectionPoints(affection) {}

		void increaseAffection(int points) {
			affectionPoints += points;
			cout << friendName << "'s affection increased by " << points << " points." << endl;
		}
		void decreaseAffection(int points) {
			affectionPoints -= points;
			cout << friendName << "'s affection decreased by " << points << " points." << endl;
		}
		
		int getAffectionLevel() const {
			return affectionPoints;
		}
};

class Member {
	public:
		string name;
		int affectionPoints;

		Member(const string& memberName) : name(memberName), affectionPoints(0) {}
		Member(string n) : name(n) {}
};

class School {
	
	public:
		string name;
		vector<Member> members;
		map<string, int> memberPoints;

		
		// School(string schoolName) : name(schoolName) {} 
		School(const string& schoolName) : name(schoolName) {}

		void addMember(const string& memberName, int points) {
			members.emplace_back(memberName);
			memberPoints[memberName] = points;
		}
		void updatePoints(const string& memberName, int points) {
			if (memberPoints.find(memberName) != memberPoints.end()) {
				memberPoints[memberName] += points;
			}
		}

		void showRankings() const {
			vector<pair<string, int>> rankings(memberPoints.begin(), memberPoints.end());
			sort(rankings.begin(), rankings.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
				return b.second < a.second; // Sort by points in descending order

				});

			cout << "Rankings for the " << name << " School: " << endl;
			for (size_t i = 0; i < rankings.size(); ++i) {
				cout << i + 1 << ". " << rankings[i].first << " - " << rankings[i].second << " points" << endl;
			}
		}
};

class Title {
private:
	string name;
	string description;
	vector<string> bonuses;  //a list of bonuses or effects associated with the title

public:
	Title(string name, string description, vector<string> bonuses = {})
		: name(name), description(description), bonuses(bonuses) {}

	//getters
	string getName() const {
		return name;
	}
	string getDescription() const {
		return description;
	}
	vector<string> getBonuses() const {
		return bonuses;
	}

	// method to display title information
	void displayTitleInfo() const {
		cout << "Title: " << name << endl;
		cout << "Description: " << description << endl;
		cout << "Bonuses: " << endl;
		for (const auto& bonus : bonuses) {
			cout << " - " << bonus << endl;
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

class Faction {
private:
	string factionName;
	string school;
public:
	Faction(const string& schoolName, const string& name) : school(schoolName), factionName(name) {}

	void explore() {
		cout << "You are exploring the " << school  << " Faction of the " << factionName << "." << endl;
		cout << "What would you like to study?: " << endl;

		if (school == "Fire" && factionName == "Inferno Knights") {
			cout << "1. Spellcasting - train with molten magic." << endl;
			cout << "2. Magical Creatures - Interact with fire elemental beings." << endl;
			cout << "3. Enchantments - Craft magical weapons and artifacts." << endl;
		}
		else if (school == "Fire" && factionName == "Pyro Scholars") {
			cout << "1. Spellcasting - Study ancient fire magic spells." << endl;
			cout << "2. Magical Creatures - Research fire crystals and their properties." << endl;
			cout << "3. Enchantments - Experiment with fire-related enchantments." << endl;
		}
		else if (school == "Fire" && factionName == "Flameborn Order") {
			cout << "1. Spellcasting - Demonstrate your fire magic skills in a competition." << endl;
			cout << "2. Magical Creatures - Create enchanted clothing with fire properties." << endl;
			cout << "3. Enchantments - Brew a powerful fire-based potion." << endl;
		}
		else if (school == "Ice" && factionName == "Frost Guard") {
			cout << "1. Spellcasting - Train with ice magic and beasts." << endl;
			cout << "2. Magical Creatures - Craft cold-infused weapons." << endl;
			cout << "3. Enchantments - Strategize and learn about ice magic combat." << endl;
		}
		else if (school == "Ice" && factionName == "Ice Scholars") {
			cout << "1. Spellcasting - Study ancient ice magic scrolls." << endl;
			cout << "2. Magical Creatures - Brew potions with ice properties." << endl;
			cout << "3. Enchantments - Observe ice magic phenomena and learn new techniques." << endl;
		}
		else if (school == "Ice" && factionName == "Glacial Sentinels") {
			cout << "1. Spellcasting - Learn defensive techniques against ice magic attacks." << endl;
			cout << "2. Magical Creatures - Participate in combat training exercises." << endl;
			cout << "3. Enchantments - Plan and coordinate strategies to defend against magical threats." << endl;
		}
		else if (school == "Life" && factionName == "Sylvan Scholars") {
			cout << "1. Spellcasting - Cultivate magical plants and learn about nature magic." << endl;
			cout << "2. Magical Creatures - Participate in ceremonies to connect with nature's cycles." << endl;
			cout << "3. Enchantments - Study celestial events' impact on nature magic." << endl;
		}
		else if (school == "Life" && factionName == "Verdant Circle") {
			cout << "1. Spellcasting - Learn methods for environmental repair and rejuvenation." << endl;
			cout << "2. Magical Creatures - Connect with other wizards to advocate for environmental causes." << endl;
			cout << "3. Enchantments - Nurture and magically enhance trees and plants." << endl;
		}
		else if (school == "Life" && factionName == "Eternal Bloom Council") {
			cout << "1. Spellcasting - Align cosmic and natural rhythms in meditation." << endl;
			cout << "2. Magical Creatures - Reveal insights about your future self at the Sacred Reflection Pool." << endl;
			cout << "3. Enchantments - Learn the Council's philosophies of eternal growth." << endl;
		}
		else if (school == "Death" && factionName == "Shadow Guardians") {
			cout << "1. Spellcasting - Master necromancy and dark magic." << endl;
			cout << "2. Magical Creatures - Summon and control undead minions." << endl;
			cout << "3. Enchantments - Craft powerful dark artifacts." << endl;
		}
		else if (school == "Death" && factionName == "Ebon Enclave") {
			cout << "1. Spellcasting - Delve into ancient death rituals and spells." << endl;
			cout << "2. Magical Creatures - Study the nature and habits of dark creatures." << endl;
			cout << "3. Enchantments - Create enchantments that manipulate life forces." << endl;
		}
		else if (school == "Death" && factionName == "Abyssal Sect") {
			cout << "1. Spellcasting - Engage in forbidden magic and rituals." << endl;
			cout << "2. Magical Creatures - Cultivate and harness powerful abyssal entities." << endl;
			cout << "3. Enchantments - Develop enchantments that control the flow of life and death." << endl;
		}
		else if (school == "Storm" && factionName == "Tempest Wardens") {
			cout << "1. Spellcasting - Harness the power of storms in your spells." << endl;
			cout << "2. Magical Creatures - Command lightning elementals and storm spirits." << endl;
			cout << "3. Enchantments - Craft artifacts imbued with storm energy." << endl;
		}
		else if (school == "Storm" && factionName == "Thunder Scholars") {
			cout << "1. Spellcasting - Study the ancient arts of thunder magic." << endl;
			cout << "2. Magical Creatures - Research and tame storm beasts." << endl;
			cout << "3. Enchantments - Experiment with lightning-infused enchantments." << endl;
		}
		else if (school == "Storm" && factionName == "Cyclone Order") {
			cout << "1. Spellcasting - Master wind manipulation and storm control." << endl;
			cout << "2. Magical Creatures - Breed and control powerful storm creatures." << endl;
			cout << "3. Enchantments - Forge magical items that control weather patterns." << endl;
		}
		else if (school == "Illusion" && factionName == "Veilkeepers") {
			cout << "1. Spellcasting - Create and maintain illusions to deceive and protect." << endl;
			cout << "2. Magical Creatures - Interact with illusionary beings and tricksters." << endl;
			cout << "3. Enchantments - Craft illusions that alter perception and reality." << endl;
		}
		else if (school == "Illusion" && factionName == "Phantom Scholars") {
			cout << "1. Spellcasting - Study advanced illusion techniques and their applications." << endl;
			cout << "2. Magical Creatures - Analyze and communicate with phantasms." << endl;
			cout << "3. Enchantments - Develop enchantments that confuse and mislead." << endl;
		}
		else if (school == "Illusion" && factionName == "Mirage Circle") {
			cout << "1. Spellcasting - Engage in illusionary duels and contests." << endl;
			cout << "2. Magical Creatures - Use illusions to train and tame mythical creatures." << endl;
			cout << "3. Enchantments - Create complex illusions for entertainment and strategic purposes." << endl;
		}
		
		int choice;
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "You engage in spellcasting activities related to the " << factionName << "!" << endl;
				break;
			case 2:
				cout << "You interact with magical creatures related to the " << factionName << "!" << endl;
				break;
			case 3:
				cout << "You work on enchantments related to the " << factionName << "!" << endl;
				break;
			default:
				cout << "You wander around and find yourself back at the starting point." << endl;
				break;
		}
	}
};



class Player {
	private:
		vector<Title> titles; //titles earned by player
	public:
		string name; 
		School* school;
		int points;
		vector<Relationship>relationships;
		vector<string> inventory; //store invetory
		vector<Skill> skills; //store skills

		
		Player(string playerName, School* playerSchool) : name(playerName), school(playerSchool), points(0) {
			school->addMember(name, 0);
		}
		Player(const string& playerName) : name(playerName) {
			//initialize default items
			inventory.push_back("Wand");
			inventory.push_back("Spellbook");
			inventory.push_back("Health Potion");

		}
		void completeQuest(int questPoints) {
			points += questPoints;
			school->updatePoints(name, questPoints);
			cout << name << " has completed a quest and earned " << questPoints << " points!" << endl;
		}

		void addRelationship(const string& friendName) {
			relationships.emplace_back(friendName);
			cout << "You have befriended " << friendName << "!" << endl;
		}

		Relationship* getRelationship(const string& friendName) {
			for (auto& rel : relationships) {
				if (rel.friendName == friendName) {
					return &rel;
				}
			}
			return nullptr;
		}

		void interactWithFriend(const string& friendName, const string& choice) {
			Relationship* rel = getRelationship(friendName);
			if (rel) {
				if (choice == "compliment") {
					rel->increaseAffection(10);
				}
				else if (choice == "argue") {
					rel->decreaseAffection(10);
				}
				else {
					cout << "Invalid interaction choice." << endl;
				}
			}
			else {
				cout << "You don't have a friend named " << friendName << "." << endl;
			}
		}

		void showRelationships() const {
			cout << "Relationships." << endl;
			for (const auto& rel : relationships) {
				cout << rel.friendName << " - Affection: " << rel.affectionPoints << endl;
			}
		}

	void addTitle(const Title& newTitle) {
		titles.push_back(newTitle);
		cout << "You have earned the title: " << newTitle.getName() << endl;

	}

	void displayTitle() const {
		if (titles.empty()) {
			cout << "No titles earned" << endl;
		}
		else {
			cout << "Titles earned: " << endl;
			for (const auto& title : titles) {
				title.displayTitleInfo();
			}
		}
	}

	void addItem(const string& item) {
		inventory.push_back(item);
		cout << item << " added to your inventory." << endl;
	}

	void checkInventory() const {
		if (inventory.empty()) {
			cout << "Your inventory is empty." << endl;
			return;
		}
		cout << "Your inventory:" << endl;
		for (const string& item : inventory) {
			cout << "- " << item << endl;
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
	string getName() const { return name; }
};

class Dorm {
	private:
		Player& player;
		string faction;
		map<string, Relationship> relationships;
		SpellList spellList;
	public:
		School& school;
		vector<Member*> friends;

		Dorm(Player& p, School& associatedSchool, const string& factionName) : player(p), school(associatedSchool), faction(factionName) {}
	
	void enter() {
		int choice;
		do {
			cout << "Welcome to your dorm, " << player.getName() << "." << endl;
			cout << "What would you like to do?" << endl;
			cout << "1. Check Inventory" << endl;
			cout << "2. Explore the Dorm Halls" << endl;
			cout << "3. Check School/ Faction Rankings" << endl;
			cout << "4. Learn (Gain new spells or knowledge)" << endl;
			cout << "5. Check Spell List" << endl;
			cout << "6. Quit School" << endl;

			cin >> choice;

			switch (choice) {
			case 1:
				player.checkInventory();
				break;
			case 2:
				exploreDormHalls();
				break;
			case 3:
				checkRankings();
				break;
			case 4:
				learn();
				break;
			case 5:
				spellInventory();
				return;
			case 6:
				quitSchool();
				break;
			default:
				cout << "Invalid choice. Please choose again." << endl;
				break;
			}
		} while (choice != 6 && choice != 4);
	}
	void exploreDormHalls() {
		//implement talk to dorm mates 

		if (school.members.size() < 2) {
			cout << "Not enough members to explore the dorm halls." << endl;
			return;
		}

		//randomly select two members from the same school
		srand(static_cast<unsigned int>(time(nullptr)));
		int index1 = rand() % school.members.size();
		int index2;
		do {
			index2 = rand() % school.members.size();
		} while (index1 == index2);

		const Member& member1 = school.members[index1];
		const Member& member2 = school.members[index2];

		cout << "As you wander through the dorm halls, you come across " << member1.name << " and " << member2.name << " having a conversation: " << endl;

		cout << member1.name << ": 'I heard there's a new spell that's incredibly powerful. Have you tried it?'" << endl;
		cout << member2.name << ": 'Not yet. I've been focused on perfecting my potion-making skills. But maybe I should give it a try.'" << endl;
		cout << member1.name << ": 'You should! It could really boost your abilities.'" << endl;

		cout << "What would you like to do?" << endl;
		cout << "1. Ask " << member1.name << " about the new spell." << endl;
		cout << "2. Offer to help " << member2.name << "with potion-making." << endl;
		cout << "3. Continue exploring the dorm halls." << endl;

		int choice;
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "You approach " << member1.name << " and ask about the new spell." << endl;
				cout << member1.name << " explains that its a spell that can enhance magical abilities but requires special ingredients to cast." << endl;
				// increaseAffection(member1.name, 10); 
				break;
			case 2:
				cout << "You offer to help " << member2.name << "with potion-making." << endl;
				cout << member2.name << "gratefully accepts and you spend some time working together, learning about potion recipes and brewing techniques." << endl;
				// increaseAffection(member2.name, 15);
				break;
			case 3:
				cout << "You decide to continue exploring the dorm halls." << endl;
				//continueExploreDormHalls
				break;
			default:
				cout << "Invalid choice. You decide to continue exploring the dorm halls." << endl;
				break;
		}
	}
	void checkRankings() const {
		school.showRankings();
	}

	void quitSchool() const {
		cout << "You have chosen to quit the school. Your journey ends here." << endl;
		exit(0);
	}
	void learn() {
		// new learn class will be here
	}
	void initializeSpells() {
		spellList.addSpell(Spell("Fireball", "A powerful fire attack", 10));
		spellList.addSpell(Spell("Ice Shard", "A sharp ice projectile", 8));
		spellList.addSpell(Spell("Lightning Bolt", "A fast lightning strike", 12));
	}
	void spellInventory() {
		spellList.displaySpells();
	}

// private:
	// void increaseAffection(const string& memberName, int points) {
		// if (relationships.find(memberName) == relationships.end()) {
			// relationships[memberName] = Relationship(memberName);
		// }
		// relationships[memberName].increaseAffection(points);
	// }
};

int main() {
	//school and members
	School fireSchool("Fire");
	fireSchool.addMember("Ignatius", 110);
	fireSchool.addMember("Ashen", 95);
	fireSchool.addMember("Ember", 70);
	fireSchool.addMember("Scorch", 62);
	fireSchool.addMember("Blaze", 59);
	fireSchool.addMember("Pyro", 54);
	fireSchool.addMember("Pyra", 53);

	School iceSchool("Ice");
	iceSchool.addMember("Frostine", 115);
	iceSchool.addMember("Glacia", 105);
	iceSchool.addMember("Tundra", 95);
	iceSchool.addMember("Cyros", 63);
	iceSchool.addMember("Frost", 52);
	iceSchool.addMember("Crystal", 46);
	iceSchool.addMember("Snow", 40);

	School lifeSchool("Life");
	lifeSchool.addMember("Thorne", 155);
	lifeSchool.addMember("Briar", 97);
	lifeSchool.addMember("Fern", 79); 
	lifeSchool.addMember("Sylva", 55); 
	lifeSchool.addMember("Nox", 45); 
	lifeSchool.addMember("Blossom", 33);
	lifeSchool.addMember("Ivy", 20);

	School deathSchool("Death");
	deathSchool.addMember("Shade",105);
	deathSchool.addMember("Grim", 92);
	deathSchool.addMember("Raven", 85);
	deathSchool.addMember("Grave", 80);
	deathSchool.addMember("Shadow", 75);
	deathSchool.addMember("Vesper", 44);
	deathSchool.addMember("Dusk", 33);

	School stormSchool("Storm");
	stormSchool.addMember("Zephyr", 114);
	stormSchool.addMember("Voltus", 96);
	stormSchool.addMember("Gale", 93);
	stormSchool.addMember("Tempest", 81);
	stormSchool.addMember("Raiden", 75);
	stormSchool.addMember("Galea", 60);
	stormSchool.addMember("Typhos", 24);

	School illusionSchool("Illusion");
	illusionSchool.addMember("Mirage", 111);
	illusionSchool.addMember("Haze", 93);
	illusionSchool.addMember("Spectra", 83);
	illusionSchool.addMember("Enigma", 44);
	illusionSchool.addMember("Sablemoon", 32);
	illusionSchool.addMember("Mistralyn", 27);
	illusionSchool.addMember("Lucinda", 15);

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
			cout << "1. Shadow Guardians" << endl;
			cout << "2. Ebon Enclave" << endl;
			cout << "3. Abyssal Sect" << endl;
			break;
		case 5:
			school = "Storm";
			cout << "Choose your faction within the School of Storm" << endl;
			cout << "1. Tempest Wardens" << endl;
			cout << "2. Thunder Scholars" << endl;
			cout << "3. Cyclone Order" << endl;
			break;
		case 6:
			school = "Illusion";
			cout << "Choose your faction within the School of Illusion" << endl;
			cout << "1. Veilkeepers" << endl;
			cout << "2. Phantom Scholars" << endl;
			cout << "3. Mirage Circle" << endl;
			break;
		default:
			cout << "Invalid school choice. The adventure ends here." << endl;
			return 0;
		}

		School* selectedSchool = nullptr;
		if (school == "Fire") {
			selectedSchool = &fireSchool;
		}
		else if (school == "Ice") {
			selectedSchool = &iceSchool;
		}
		else if (school == "Life") {
			selectedSchool = &lifeSchool;
		}
		else if (school == "Death") {
			selectedSchool = &deathSchool;
		}
		else if (school == "Storm") {
			selectedSchool = &stormSchool;
		}
		else if (school == "Illusion") {
			selectedSchool = &illusionSchool;
		}


		int factionChoice;
		cin >> factionChoice;
		cin.ignore();
		
		string faction;
		switch (factionChoice) {
			case 1:
				faction = (school == "Fire") ? "Inferno Knights" :
					(school == "Ice") ? "Frost Guard" :
					(school == "Life") ? "Sylvan Scholars" :
					(school == "Death") ? "Shadow Guardians" :
					(school == "Storm") ? "Tempest Wardens" :
					(school == "Illusion") ? "Veilkeepers" : "";
				break;
			case 2:
				faction = (school == "Fire") ? "Pyro Scholars" :
					(school == "Ice") ? "Ice Scholars" :
					(school == "Life") ? "Verdant Circle" :
					(school == "Death") ? "Ebon Enclave" :
					(school == "Storm") ? "Thunder Scholars" :
					(school == "Illusion") ? "Phantom Scholars" : "";
				break;
			case 3:
				faction = (school == "Fire") ? "Flameborn Order" :
					(school == "Ice") ? "Glacial Sentinels" :
					(school == "Life") ? "Eternal Bloom Council" :
					(school == "Death") ? "Abyssal Sect" :
					(school == "Storm") ? "Cyclone Order" :
					(school == "Illusion") ? "Mirage Circle" : "";
				break;
			default:
				cout << "Invalid faction choice." << endl;
				return 0;
		}

		Faction selectedFaction(school, faction);
		selectedFaction.explore();

		Dorm dorm(player, *selectedSchool, faction);
		dorm.enter();

		cout << "Do you want to play again? (y/n): ";
		cin >> playAgain;
		cin.ignore();

		cout << endl;

	} while (playAgain == 'y' || playAgain == 'Y');

	cout << "Thanks for playing!" << endl;

	return 0;

}




