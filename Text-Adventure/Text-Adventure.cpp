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

		Member(const string& memberName, int memberPoints) : name(memberName), affectionPoints(0) {}

		void adjustAffection(int points) {
			affectionPoints += points;
		}
};

class School {
	public:
		string name;
		vector<Member> members;
		map<string, int> memberPoints;

		School(const string& schoolName) : name(schoolName) {}

		void addMember(const string& memberName, int points) {
			members.push_back(Member(memberName, points)); 
			//members.emplace_back(memberName);
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
		//random encounter with a school member
		void randomChanceEncounter() {
			if (members.empty()) {
				cout << "No members in this school to encounter." << endl;
				return;
			}

			srand(time(0));
			int randomIndex = rand() % members.size();
			Member& encounteredMember = members[randomIndex];

			cout << "You encountered " << encounteredMember.name << " from the " << name << " school!" << endl;

			if (name == "Fire") {
				cout << encounteredMember.name << " challenges you to a fiery duel. Do you accept? (y/n): ";
			}
			else if (name == "Ice") {
				cout << encounteredMember.name << " offers wisdom on controlling ice magic. Do you listen? (y/n): ";
			}
			else if (name == "Life") {
				cout << encounteredMember.name << " invites you to help grow a magical plant. Do you help? (y/n): ";
			}
			else if (name == "Death") {
				cout << encounteredMember.name << " asks you if you're ready to face death. Do you accept their test? (y/n): ";
			}
			else if (name == "Storm") {
				cout << encounteredMember.name << " tests your ability to control the wind. Do you try? (y/n): ";
			}
			else if (name == "Illusion") {
				cout << encounteredMember.name << " challenges your sense of reality. Do you believe their illusion? (y/n): ";
			}

			char choice;
			cin >> choice;

			//affect affection points based on player's choice
			if (choice == 'y' || choice == 'Y') {
				cout << "You gained " << encounteredMember.name << "'s favor!" << endl;
				encounteredMember.adjustAffection(10); //increase affection
			}
			else {
				cout << "You lost " << encounteredMember.name << "'s favor." << endl;
				encounteredMember.adjustAffection(-10); //decrease affection
			}

			//show current affection points
			cout << encounteredMember.name << " now has " << encounteredMember.affectionPoints << " affection points." << endl;
		}

		string getName() const {
			return name;
		}
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
		Credits credits; // manage credits
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
	void earnCredits(int amount) {
		credits.addCredits(amount);
	}
	void spendCredits(int amount) {
		credits.deductCredits(amount);
	}
	
	string getName() const { return name; }

	Credits& getCredits() { return credits; } // access credits
	const Credits& getCredits() const { return credits; }
};



class LearnMagic {
private:
	map<string, pair<int, vector<string>>> availableClasses; 
public:
	Player& player;
	Credits& credits;
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

	bool attendClass(const string& className) {
		if (player.hasLearnedClass(className)) {
			cout << "You have already attended the " << className << " class." << endl;
			return false;
		}
		auto it = availableClasses.find(className);
		if (it == availableClasses.end()) {
			cout << "Class not available." << endl;
			return false;
		}

		int classCost = it->second.first;
		if (!credits.canTakeClass(classCost)) {
			cout << "You do not have enough credits to attend this class." << endl;
			return false;
		}

		cout << "You have chosen to attend the " << className << " class." << endl;
		for (const auto& task : it->second.second) {
			cout << "Task: " << task << endl;
			// simulate task completion
			cout << "Task completed!" << endl;
		}

		cout << "Congratulations! You have completed the " << className << " class." << endl;
		player.learnSpell(className);
		player.addLearnedClass(className);
		credits.deductCredits(classCost);
		credits.addCredits(classCost / 2);

		return true;
	}

	void listAffordableClasses() const {
		cout << "Affordable classes:" << endl;
		bool hasAffordableClasses = false;

		for (const auto& classPair : availableClasses) {
			const string& className = classPair.first;
			int classCost = classPair.second.first;

			if (player.getCredits().canTakeClass(classCost)) {
				cout << "- " << className << " (Cost: " << classCost << " credits)" << endl;
				hasAffordableClasses = true;
			}
		}

		if (!hasAffordableClasses) {
			cout << "You cannot afford any classes at the moment." << endl;
		}
	}
};

class Dorm {
	private:
		Player& player;
		Faction faction;
		map<string, Relationship> relationships;
		School& school;
		SpellList spellList;
		LearnMagic learnMagic;
		Credits creditsObj;
		vector<Member*> friends;
	public:
		Dorm(Player& p, School school, Faction f) :
			player(p), learnMagic(p, spellList, creditsObj, school, f), school(school), faction(f) {
			learnMagic.initializeClasses(school.getName(), f.getName());
		}

		
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
				int timeUnits;
				cout << "How many time units do you want to spend exploring? ";
				cin >> timeUnits;
				exploreDormHalls(timeUnits);
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
	void increaseAffection(const string& memberName, int points) {
		if (relationships.find(memberName) != relationships.end()) {
			relationships[memberName].increaseAffection(points);
		}
		else {
			cout << "Relationship with " << memberName << " not found." << endl;
		}
	}
	void exploreDormHalls(int timeUnits) {
		int encounters = 0;
		srand(time(0)); // random seed

		for (int i = 0; i < timeUnits; ++i) {
			if (rand() % 2 == 0) { // 50% chance of an encounter each time unit
				school.randomChanceEncounter(); // call the school's encounter function
				encounters++;
			}
		}
		cout << "You encountered " << encounters << " events during your exploration." << endl;
	}

	void checkRankings() const {
		school.showRankings();
	}

	void quitSchool() const {
		cout << "You have chosen to quit the school. Your journey ends here." << endl;
		exit(0);
	}
	void learn() {
		learnMagic.listAffordableClasses(); // list affordable classes before attending
		string chosenClass;
		cout << "Enter the class you want to attend: ";
		cin >> chosenClass;

		//attempt to attend the chosen class
		bool success = learnMagic.attendClass(chosenClass);

		// if attending the class was unsuccessful due to lack of credits, return to the dorm
		if (!success) {
			cout << "Returning to the dorm." << endl;
			enter();
		}
	}
	void initializeSpells() {
		spellList.addSpell(Spell("Fireball", "A powerful fire attack", 10));
		spellList.addSpell(Spell("Ice Shard", "A sharp ice projectile", 8));
		spellList.addSpell(Spell("Lightning Bolt", "A fast lightning strike", 12));
		spellList.addSpell(Spell("Fireball", "A basic fireball spell", 5));
		spellList.addSpell(Spell("Ice Lance", "A lance of ice to pierce enemies", 3)); 
		spellList.addSpell(Spell("Healing Light", "A spell to heal wounds", 4));
	}
	void spellInventory() {
		spellList.displaySpells();
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
		
		player.earnCredits(10); 

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
		

		Dorm dorm(player, *selectedSchool, selectedFaction);
		dorm.enter();
		

		cout << "Do you want to play again? (y/n): ";
		cin >> playAgain;
		cin.ignore();

		cout << endl;

	} while (playAgain == 'y' || playAgain == 'Y');

	cout << "Thanks for playing!" << endl;

	return 0;

}




