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

		Relationship() : friendName("Unknown"),affectionPoints(0) {}

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
				cout << i + 1 << ". " << rankings[i].first << " - " << rankings[i].second << " credits" << endl;
			}
		}

		string getName() const {
			return name;
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
	string schoolName;
public:
	Faction(const string& schoolName, const string& name) : schoolName(schoolName), factionName(name) {}

	void explore() {
		cout << "You are exploring the " << schoolName  << " Faction of the " << factionName << "." << endl;
		cout << "What would you like to study?: " << endl;

		if (schoolName == "Fire" && factionName == "Inferno Knights") {
			cout << "1. Spellcasting - train with molten magic." << endl;
			cout << "2. Magical Creatures - Interact with fire elemental beings." << endl;
			cout << "3. Enchantments - Craft magical weapons and artifacts." << endl;
		}
		else if (schoolName == "Fire" && factionName == "Pyro Scholars") {
			cout << "1. Spellcasting - Study ancient fire magic spells." << endl;
			cout << "2. Magical Creatures - Research fire crystals and their properties." << endl;
			cout << "3. Enchantments - Experiment with fire-related enchantments." << endl;
		}
		else if (schoolName == "Fire" && factionName == "Flameborn Order") {
			cout << "1. Spellcasting - Demonstrate your fire magic skills in a competition." << endl;
			cout << "2. Magical Creatures - Create enchanted clothing with fire properties." << endl;
			cout << "3. Enchantments - Brew a powerful fire-based potion." << endl;
		}
		else if (schoolName == "Ice" && factionName == "Frost Guard") {
			cout << "1. Spellcasting - Train with ice magic and beasts." << endl;
			cout << "2. Magical Creatures - Craft cold-infused weapons." << endl;
			cout << "3. Enchantments - Strategize and learn about ice magic combat." << endl;
		}
		else if (schoolName == "Ice" && factionName == "Ice Scholars") {
			cout << "1. Spellcasting - Study ancient ice magic scrolls." << endl;
			cout << "2. Magical Creatures - Brew potions with ice properties." << endl;
			cout << "3. Enchantments - Observe ice magic phenomena and learn new techniques." << endl;
		}
		else if (schoolName == "Ice" && factionName == "Glacial Sentinels") {
			cout << "1. Spellcasting - Learn defensive techniques against ice magic attacks." << endl;
			cout << "2. Magical Creatures - Participate in combat training exercises." << endl;
			cout << "3. Enchantments - Plan and coordinate strategies to defend against magical threats." << endl;
		}
		else if (schoolName == "Life" && factionName == "Sylvan Scholars") {
			cout << "1. Spellcasting - Cultivate magical plants and learn about nature magic." << endl;
			cout << "2. Magical Creatures - Participate in ceremonies to connect with nature's cycles." << endl;
			cout << "3. Enchantments - Study celestial events' impact on nature magic." << endl;
		}
		else if (schoolName == "Life" && factionName == "Verdant Circle") {
			cout << "1. Spellcasting - Learn methods for environmental repair and rejuvenation." << endl;
			cout << "2. Magical Creatures - Connect with other wizards to advocate for environmental causes." << endl;
			cout << "3. Enchantments - Nurture and magically enhance trees and plants." << endl;
		}
		else if (schoolName == "Life" && factionName == "Eternal Bloom Council") {
			cout << "1. Spellcasting - Align cosmic and natural rhythms in meditation." << endl;
			cout << "2. Magical Creatures - Reveal insights about your future self at the Sacred Reflection Pool." << endl;
			cout << "3. Enchantments - Learn the Council's philosophies of eternal growth." << endl;
		}
		else if (schoolName == "Death" && factionName == "Shadow Guardians") {
			cout << "1. Spellcasting - Master necromancy and dark magic." << endl;
			cout << "2. Magical Creatures - Summon and control undead minions." << endl;
			cout << "3. Enchantments - Craft powerful dark artifacts." << endl;
		}
		else if (schoolName == "Death" && factionName == "Ebon Enclave") {
			cout << "1. Spellcasting - Delve into ancient death rituals and spells." << endl;
			cout << "2. Magical Creatures - Study the nature and habits of dark creatures." << endl;
			cout << "3. Enchantments - Create enchantments that manipulate life forces." << endl;
		}
		else if (schoolName == "Death" && factionName == "Abyssal Sect") {
			cout << "1. Spellcasting - Engage in forbidden magic and rituals." << endl;
			cout << "2. Magical Creatures - Cultivate and harness powerful abyssal entities." << endl;
			cout << "3. Enchantments - Develop enchantments that control the flow of life and death." << endl;
		}
		else if (schoolName == "Storm" && factionName == "Tempest Wardens") {
			cout << "1. Spellcasting - Harness the power of storms in your spells." << endl;
			cout << "2. Magical Creatures - Command lightning elementals and storm spirits." << endl;
			cout << "3. Enchantments - Craft artifacts imbued with storm energy." << endl;
		}
		else if (schoolName == "Storm" && factionName == "Thunder Scholars") {
			cout << "1. Spellcasting - Study the ancient arts of thunder magic." << endl;
			cout << "2. Magical Creatures - Research and tame storm beasts." << endl;
			cout << "3. Enchantments - Experiment with lightning-infused enchantments." << endl;
		}
		else if (schoolName == "Storm" && factionName == "Cyclone Order") {
			cout << "1. Spellcasting - Master wind manipulation and storm control." << endl;
			cout << "2. Magical Creatures - Breed and control powerful storm creatures." << endl;
			cout << "3. Enchantments - Forge magical items that control weather patterns." << endl;
		}
		else if (schoolName == "Illusion" && factionName == "Veilkeepers") {
			cout << "1. Spellcasting - Create and maintain illusions to deceive and protect." << endl;
			cout << "2. Magical Creatures - Interact with illusionary beings and tricksters." << endl;
			cout << "3. Enchantments - Craft illusions that alter perception and reality." << endl;
		}
		else if (schoolName == "Illusion" && factionName == "Phantom Scholars") {
			cout << "1. Spellcasting - Study advanced illusion techniques and their applications." << endl;
			cout << "2. Magical Creatures - Analyze and communicate with phantasms." << endl;
			cout << "3. Enchantments - Develop enchantments that confuse and mislead." << endl;
		}
		else if (schoolName == "Illusion" && factionName == "Mirage Circle") {
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
	string getFactionName() const {
		return factionName;
	}
	string getSchoolName() const {
		return schoolName;
	}
	string getName()const {
		return factionName;
	}
};

class Credits {
	private:
		int totalCredits;
	public:

		Credits() : totalCredits(0) {}

		void addCredits(int credits) {
			totalCredits += credits;
		}

		bool canTakeClass(int classCost) const {
			return totalCredits >= classCost;
		}

		void deductCredits(int classCost) {
			if (canTakeClass(classCost)) {
				totalCredits -= classCost;
			}
			else {
				cout << "Not enough credits." << endl;
			}
		}

		int getTotalCredits() const {
			return totalCredits;
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
		vector<string> learnedClasses;

		
		Player(string playerName, School* playerSchool) : name(playerName), school(playerSchool), points(0) {
			school->addMember(name, 0);
		}
		Player(const string& playerName) : name(playerName) {
			//initialize default items
			inventory.push_back("Wand");
			inventory.push_back("Spellbook");
			inventory.push_back("Health Potion");

		}

		void learnSpell(const string& spell) {
			cout << "You have learned the spell: " << spell << "!" << endl;
		}

		void addLearnedClass(const string& className) {
			learnedClasses.push_back(className);
		}

		bool hasLearnedClass(const string& className) const {
			return find(learnedClasses.begin(), learnedClasses.end(), className) != learnedClasses.end();
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
	
	string getName() const { return name; }
};



class LearnMagic {
public:
	Player& player;
	Credits& credits;
	map<string, pair<int, vector<string>>> availableClasses;
	SpellList& spellList;
	School selectedSchool;
	Faction selectedFaction;

	LearnMagic(Player& p, SpellList& sl, Credits& c, School school, Faction faction) :
		player(p), spellList(sl), credits(c), selectedSchool(school), selectedFaction(faction) {}

	void initializeClasses(const string& school, const string& faction) {
		if (school == "Fire School") {
			availableClasses["Fireball Basics"] = { 2, { "Practice casting small fireballs."}};
			availableClasses["Advanced Pyromancy"] = { 2,{ "Successfully cast a fireball in combat." }};
			availableClasses["Inferno Mastery"] = { 2, {"Summon a controlled inferno in a safe environment.", "Use Inferno to defeat an enemy." }};
			availableClasses["Flame Shield"] = { 6, { "Create a protective shield of fire.", "Maintain the shield during combat." } };
			availableClasses["Phoenix Flame"] = { 10, { "Summon the flames of a Phoenix.", "Resurrect using Phoenix fire." } };
			availableClasses["Dragon's Breath"] = { 16, { "Summon the fiery breath of a dragon.", "Use Dragon's Breath to incinerate enemies." } };
			availableClasses["Firestorm"] = { 20, { "Create a devastating firestorm.", "Control the firestorm to avoid allies." }};
			availableClasses["Lava Manipulation"] = { 20,{ "Manipulate molten lava from a volcano.", "Use lava to create a barrier." }};
		}
		else if (school == "Ice School") {
			availableClasses["Water Manipulation"] = { 2, { "Gather water from the Mystic Lake.", "Demonstrate water shaping techniques." }};
			availableClasses["Ice Magic"] = { 2,{ "Collect ice shards from the Frozen Tundra.","Defeat an Ice Elemental." }};
			availableClasses["Blizzard Control"] = { 2, {"Summon a blizzard in the Ice Caves.", "Use the blizzard to defeat a foe." }};
			availableClasses["Ice Barrier"] = { 6, { "Create a barrier of solid ice.", "Use the barrier to block attacks." } };
			availableClasses["Frozen Armor"] = { 10, {"Create armor made of ice.", "Maintain the armor during combat." }};
			availableClasses["Glacial Prison"] = { 14, { "Trap an enemy in a block of ice.", "Keep the enemy imprisoned until surrender." }};
			availableClasses["Hailstorm"] = { 16, { "Summon a hailstorm to pelt enemies.", "Control the storm to target only foes." } };
			availableClasses["Frostbite"] = { 20, { "Inflict frostbite on an enemy.", "Use frostbite to weaken an opponent's defenses." }};
		}
		else if (school == "Life School") {
			availableClasses["Herbalism"] = { 2, { "Collect herbs from the Enchanted Forest.", "Create a healing potion." }};
			availableClasses["Nature's Touch"] = { 2, {"Heal a wounded creature.", "Grow a plant using magic." }};
			availableClasses["Forest Communion"] = { 2, { "Communicate with the forest spirits.", "Receive a blessing from the spirits." }};
			availableClasses["Vine Whip"] = { 6, { "Summon magical vines to ensnare enemies.", "Control the vines to avoid harming allies." } };
			availableClasses["Animal Bonding"] = { 10, { "Form a bond with a magical creature.", "Command the creature in battle." }};
			availableClasses["Life Drain"] = { 14, { "Drain life force from a plant to heal yourself.", "Use drained life force to empower spells." }};
			availableClasses["Healing Aura"] = { 16, { "Create an aura that heals nearby allies.", "Maintain the aura during battle." } };
			availableClasses["Rebirth"] = { 20,{ "Experience a ritual of rebirth.", "Return from the brink of death." }};
		}
		else if (school == "Death School") {
			availableClasses["Necromancy Basics"] = { 2, { "Raise a small skeleton from the grave.","Control the skeleton to perform tasks." } };
			availableClasses["Advanced Necromancy"] = { 2, {"Summon a wraith from the Shadow Realm.","Defeat a ghost using necromantic magic." }};
			availableClasses["Dark Pact"] = { 2, { "Make a pact with a dark entity.", "Use the pact to increase your power in combat." }};
			availableClasses["Curse of Weakness"] = { 6, { "Curse an enemy to reduce their strength.", "Maintain the curse during combat." } };
			availableClasses["Soul Harvest"] = { 10, { "Harvest the soul of a defeated enemy.", "Use the soul to power your necromantic spells." }};
			availableClasses["Shadow Walk"] = { 14, {"Move unseen through shadows.", "Avoid detection by enemies." }};
			availableClasses["Death's Embrace"] = { 16, { "Summon the chilling touch of death to weaken foes.", "Use Death's Embrace to drain life force." } };
			availableClasses["Reanimation"] = { 20, { "Reanimate a fallen ally for a short time.", "Command the reanimated ally in battle." }};
		}
		else if (school == "Storm School") {
			availableClasses["Lightning Mastery"] = {2, { "Summon a lightning bolt during a storm.", "Use lightning to power a machine." }};
			availableClasses["Storm's Fury"] = { 2,{ "Create a powerful storm.", "Use the storm to defeat an enemy." }};
			availableClasses["Thunder Call"] = { 2, {"Summon thunder to intimidate opponents.", "Use thunder to disrupt enemy spells." }};
			availableClasses["Chain Lightning"] = { 6, { "Summon lightning that strikes multiple targets.", "Control the lightning to avoid allies." } };
			availableClasses["Tornado Summoning"] = { 10,{ "Create a tornado to wreak havoc.", "Control the tornado to avoid allies." }};
			availableClasses["Static Shield"] = { 14, { "Create a shield of static electricity.", "Repel enemies using the shield." }};
			availableClasses["Storm Surge"] = { 16, { "Summon a surge of electrical energy to empower your spells.", "Maintain the surge during combat." } };
			availableClasses["Hurricane Command"] = { 20, { "Summon and control a hurricane.", "Use the hurricane to alter the battlefield." }};
		}
		else if (school == "Illusion School") {
			availableClasses["Basic Illusions"] = { 2, { "Create a simple illusion to trick the senses.", "Maintain the illusion for a set time." }};
			availableClasses["Advanced Illusions"] = { 2, { "Create a complex illusion to hide an object.", "Use illusion magic in combat." }};
			availableClasses["Mind Manipulation"] = { 2, { "Influence the thoughts of a target.", "Create a shared illusion for a group." }};
			availableClasses["False Vision"] = { 6, { "Create a false vision to mislead enemies.", "Maintain the illusion to deceive foes." } };
			availableClasses["Phantom Army"] = { 10,{ "Create an army of illusionary soldiers.", "Use the phantom army to deceive enemies." }};
			availableClasses["Mirror Image"] = { 14, { "Create duplicates of yourself.", "Confuse enemies with the duplicates." }};
			availableClasses["Dreamweaving"] = { 16, { "Enter the dreams of others to plant suggestions.", "Control the dream to achieve your goals." } };
			availableClasses["Reality Warp"] = { 20, { "Warp reality around you.", "Create a zone where nothing is as it seems." }};
		}

	}

	void attendClass(const string& className) {
		if (player.hasLearnedClass(className)) {
			cout << "You have already attended the " << className << " class." << endl;
			return;
		}
		auto it = availableClasses.find(className);
		if (it == availableClasses.end()) {
			cout << "Class not available." << endl;
			return;
		}

		int classCost = it->second.first;
		if (!credits.canTakeClass(classCost)) {
			cout << "You do not have enough credits to attend this class." << endl;
			return;
		}


		cout << "You have chosen to attend the " << className << " class." << endl;
		for (const auto& task : it->second.second) {
			cout << "Task: " << task << endl;
			//task here
			cout << "Task completed!" << endl;


		}

		cout << "Congratulations! You have completed the " << className << " class." << endl;
		player.learnSpell(className);
		player.addLearnedClass(className);
		credits.deductCredits(classCost);
		credits.addCredits(classCost/2);
	}

	void listAvailableClasses() const {
		cout << "Available classes:" << endl;
		cout << "Number of available classes: " << availableClasses.size() << endl; //map isnt populated
		for (const auto& classPair : availableClasses) {
			cout << "- " << classPair.first << "(Cost: " << classPair.second.first << " credits)" << endl;
		}
	}
};

class Dorm {
	private:
		Player& player;
		string faction;
		map<string, Relationship> relationships;
		SpellList spellList;
		LearnMagic learnMagic;
	public:
		School& school;
		vector<Member*> friends;
		Credits creditsObj;

		Dorm(Player& p, School& associatedSchool, const string& factionName) :
			player(p), school(associatedSchool),
			faction(factionName),
			creditsObj(),
			learnMagic(p, spellList, creditsObj, associatedSchool, Faction(associatedSchool.getName(), factionName)) {}

		
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
		// check if there are enough members to explore
		if (school.members.size() < 2) {
			cout << "Not enough members to explore the dorm halls." << endl;
			return;
		}

		srand(static_cast<unsigned int>(time(nullptr)));

		bool continueExploring = true;
		while (continueExploring) {
			// randomly select two members from the same school
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
			cout << "2. Offer to help " << member2.name << " with potion-making." << endl;
			cout << "3. Share your magical abilities with " << member1.name << " and " << member2.name << endl;
			cout << "4. Continue exploring the dorm halls." << endl;
			cout << "5. Return to your dorm room." << endl;

			int choice;
			cin >> choice;

			// declare and initialize outside the switch statement
			int newIndex1 = rand() % school.members.size();
			int newIndex2;
			do {
				newIndex2 = rand() % school.members.size();
			} while (newIndex1 == newIndex2);

			const Member& newMember1 = school.members[newIndex1];
			const Member& newMember2 = school.members[newIndex2];

			int scenario = rand() % 3;

			switch (choice) {
			case 1:
				cout << "You approach " << member1.name << " and ask about the new spell." << endl;
				cout << member1.name << " explains that it's a spell that can enhance magical abilities but requires special ingredients to cast." << endl;
				increaseAffection(member1.name, 10);
				break;

			case 2:
				cout << "You offer to help " << member2.name << " with potion-making." << endl;
				cout << member2.name << " gratefully accepts, and you spend some time working together, learning about potion recipes and brewing techniques." << endl;
				increaseAffection(member2.name, 15);
				break;

			case 3:
				cout << "You decide to share your own magical discoveries with " << member1.name << " and " << member2.name << "." << endl;
				if (creditsObj.getTotalCredits() >= 10) {
					cout << "You demonstrate a complex spell you recently mastered, combining elements of both fire and lightning to create a dazzling display of power." << endl;
					cout << member1.name << " and " << member2.name << " watch in awe, clearly impressed by your abilities." << endl;
					cout << member1.name << ": 'Incredible! I've never seen anything like that. You must teach me this spell!'" << endl;
					cout << member2.name << ": 'I think this could be the key to perfecting my potion-making as well. Your skills are truly remarkable.'" << endl;
					  increaseAffection(member1.name, 10);
					  increaseAffection(member2.name, 10);

				}
				else {
					cout << "You attempt to share a basic spell, but it doesn't quite have the impact you hoped for." << endl;
					cout << member1.name << " and " << member2.name << " exchange glances, their interest waning." << endl;
					cout << member1.name << ": 'Hmm, that's interesting, but I've seen better.'" << endl;
					cout << member2.name << ": 'Maybe you should focus on refining your skills before showing off next time.'" << endl;
				}
				break;

			case 4:
				cout << "You decide to continue exploring the dorm halls." << endl;
				cout << "You encounter " << newMember1.name << " and " << newMember2.name << " having a lively discussion." << endl;

				switch (scenario) {
				case 0:
					cout << newMember1.name << " is practicing a new spell and invites you to join in." << endl;
					cout << newMember2.name << " seems to be skeptical of the spell's effectiveness." << endl;
					cout << "Do you join in or express your doubts?" << endl;
					cout << "1. Join " << newMember1.name << " and practice the spell." << endl;
					cout << "2. Agree with " << newMember2.name << " and express your doubts." << endl;
					
					int scenarioChoice;
					cin >> scenarioChoice;

					if (scenarioChoice == 1) {
						cout << newMember1.name << " appreciates your willingness to experiment and you successfully practice the spell together." << endl; 
						// increase friendship with newMember1
						increaseAffection(newMember1.name, 10);

					}
					else {
						cout << newMember2.name << " nods in agreement, appreciating your critical thinking." << endl;
						// increase friendship with newMember2
						increaseAffection(newMember2.name, 10);

					}
					break;

				case 1:
					cout << newMember1.name << " is organizing a magical duel and asks if you'd like to participate." << endl;
					cout << newMember2.name << " is there to watch and cheer you on." << endl;
					cout << "Do you accept the challenge or politely decline?" << endl;
					cout << "1. Accept the duel challenge." << endl;
					cout << "2. Politely decline and cheer on the others." << endl;

					cin >> scenarioChoice;

					if (scenarioChoice == 1) {
						cout << "You accept the challenge and engage in a thrilling duel with " << newMember1.name << "." << endl;
						cout << "The duel is intense, but you manage to hold your own, earning respect from both members." << endl;
						// increase friendship with both members
						increaseAffection(newMember1.name, 10);
						increaseAffection(newMember2.name, 10);

					}
					else {
						cout << "You politely decline, preferring to observe the duel. " << newMember2.name << " appreciates your support from the sidelines." << endl;
						// increase friendship with newMember2
						increaseAffection(newMember2.name, 15);

					}
					break;

				case 2:
					cout << newMember1.name << " and " << newMember2.name << " are debating a magical theory." << endl;
					cout << "They invite you to share your opinion on the matter." << endl;
					cout << "Do you side with " << newMember1.name << " or " << newMember2.name << "?" << endl;
					cout << "1. Side with " << newMember1.name << " and support their argument." << endl;
					cout << "2. Side with " << newMember2.name << " and support their counterargument." << endl;

					cin >> scenarioChoice;

					if (scenarioChoice == 1) {
						cout << newMember1.name << " is pleased with your support and the debate continues with renewed vigor." << endl;
						// increase friendship with newMember1
						increaseAffection(newMember1.name, 10);

					}
					else {
						cout << newMember2.name << " smiles, happy to have someone who sees things from their perspective." << endl;
						// increase friendship with newMember2
						increaseAffection(newMember2.name, 10);
					}
					break;
				}
				break;

			case 5:
				cout << "You decide to return to your dorm room." << endl;
				continueExploring = false; // exit the loop
				break;

			default:
				cout << "Invalid choice. You decide to continue exploring the dorm halls." << endl;
				break;
			}
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
		Credits creditsObj;
		learnMagic.listAvailableClasses();

		string chosenClass; 
		cout << "Enter the class you want to attend: ";
		cin >> chosenClass;

		learnMagic.attendClass(chosenClass);
	}
	void initializeSpells() {
		spellList.addSpell(Spell("Fireball", "A powerful fire attack", 10));
		spellList.addSpell(Spell("Ice Shard", "A sharp ice projectile", 8));
		spellList.addSpell(Spell("Lightning Bolt", "A fast lightning strike", 12));
	}
	void spellInventory() {
		spellList.displaySpells();
	}

 private:
	 void increaseAffection(const string& memberName, int points) {
		if (relationships.find(memberName) == relationships.end()) {
			 relationships[memberName] = Relationship(memberName);
		 }
		 relationships[memberName].increaseAffection(points);
	 }
};

int main() {
	//school and members
	School fireSchool("Fire");
	fireSchool.addMember("Ignatius", 110);
	fireSchool.addMember("Ashen", 95);
	fireSchool.addMember("Scorcha", 85);
	fireSchool.addMember("Ember", 70);
	fireSchool.addMember("Scorch", 62);
	fireSchool.addMember("Blaze", 59);
	fireSchool.addMember("Pyro", 54);
	fireSchool.addMember("Pyra", 53);
	fireSchool.addMember("Emberis", 45);
	fireSchool.addMember("Inferna", 40);
	fireSchool.addMember("Blazewind", 37);
	fireSchool.addMember("Ignitia", 28);
	fireSchool.addMember("Searis", 22);
	fireSchool.addMember("Ignis", 20);
	fireSchool.addMember("Volcanor", 16);
	fireSchool.addMember("Volcanis", 13);

	School iceSchool("Ice");
	iceSchool.addMember("Frostine", 115);
	iceSchool.addMember("Glacia", 105);
	iceSchool.addMember("Tundra", 95);
	iceSchool.addMember("Icetide", 80);
	iceSchool.addMember("Cyros", 63);
	iceSchool.addMember("Frost", 52); 
	iceSchool.addMember("Snowlyn", 48);
	iceSchool.addMember("Crystal", 46); 
	iceSchool.addMember("Snow", 40); 
	iceSchool.addMember("Frost", 30);
	iceSchool.addMember("Glacier", 25);
	iceSchool.addMember("Frostella", 22);
	iceSchool.addMember("Snowbreeze", 19);
	iceSchool.addMember("Glaciana", 15);
	iceSchool.addMember("Icyra", 14);
	iceSchool.addMember("Cryosus", 10);
	

	School lifeSchool("Life");
	lifeSchool.addMember("Thorne", 155);
	lifeSchool.addMember("Ivyra", 101);
	lifeSchool.addMember("Briar", 97);
	lifeSchool.addMember("Thalia", 84);
	lifeSchool.addMember("Fern", 79); 
	lifeSchool.addMember("Sylva", 55); 
	lifeSchool.addMember("Nox", 45); 
	lifeSchool.addMember("Thornebark", 39);
	lifeSchool.addMember("Blossom", 33);
	lifeSchool.addMember("Eldara", 30);
	lifeSchool.addMember("Fayla", 28);
	lifeSchool.addMember("Greenleaf", 24);
	lifeSchool.addMember("Ivy", 20);
	lifeSchool.addMember("Willow", 18);
	lifeSchool.addMember("Aurelia", 12);
	lifeSchool.addMember("Liora", 10);

	School deathSchool("Death");
	deathSchool.addMember("Grimora", 115);
	deathSchool.addMember("Shade",105);
	deathSchool.addMember("Grim", 92);
	deathSchool.addMember("Raven", 85);
	deathSchool.addMember("Grave", 80);
	deathSchool.addMember("Shadow", 75);
	deathSchool.addMember("Nocturn", 69);
	deathSchool.addMember("Obsidian", 55);
	deathSchool.addMember("Vesper", 44);
	deathSchool.addMember("Dusk", 33);
	deathSchool.addMember("Noxis", 30);
	deathSchool.addMember("Moros", 27);
	deathSchool.addMember("Lamia", 21);
	deathSchool.addMember("Shadeveil", 18);
	deathSchool.addMember("Ravenor", 15);
	deathSchool.addMember("Ebonis", 12);

	School stormSchool("Storm");
	stormSchool.addMember("Zephyr", 114);
	stormSchool.addMember("Sky", 105);
	stormSchool.addMember("Cyclonis", 103);
	stormSchool.addMember("Voltus", 96);
	stormSchool.addMember("Gale", 93);
	stormSchool.addMember("Tempest", 81);
	stormSchool.addMember("Raiden", 75);
	stormSchool.addMember("Galea", 60);
	stormSchool.addMember("Typhos", 24);
	stormSchool.addMember("Stormclaw", 22);
	stormSchool.addMember("Zephyra", 21);
	stormSchool.addMember("Cyro", 20);
	stormSchool.addMember("Windrider", 19);
	stormSchool.addMember("Electra", 17);
	stormSchool.addMember("Thundersky", 14);
	stormSchool.addMember("Tempestra", 10);

	School illusionSchool("Illusion");
	illusionSchool.addMember("Mirage", 111);
	illusionSchool.addMember("Phantasma", 99);
	illusionSchool.addMember("Nebulyn", 98);
	illusionSchool.addMember("Haze", 93);
	illusionSchool.addMember("Spectra", 83);
	illusionSchool.addMember("Lucindra", 75);
	illusionSchool.addMember("Arcanis", 60);
	illusionSchool.addMember("Enigma", 44);
	illusionSchool.addMember("Sablemoon", 32);
	illusionSchool.addMember("Mistralyn", 27);
	illusionSchool.addMember("Dreamara", 25);
	illusionSchool.addMember("Mystara", 20);
	illusionSchool.addMember("Glimmer", 16);
	illusionSchool.addMember("Lucinda", 15);
	illusionSchool.addMember("Shadewyn", 12);
	illusionSchool.addMember("Mirabella", 10);


	string playerName;
	char playAgain;

	do {
		cout << "Welcome to the Wizard's Adventure!" << endl;
		cout << "What is your name, young wizard?" << endl;
		getline(cin, playerName);

		Player player(playerName);
		SpellList spellList;
		Credits credits(); 

		


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

		string schoolName = selectedSchool->getName();
		string factionName = selectedFaction.getName();

		selectedFaction.explore();
		
		// LearnMagic learnMagic(player, spellList, credits, *selectedSchool, selectedFaction);

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




