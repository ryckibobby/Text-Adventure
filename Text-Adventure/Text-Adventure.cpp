

#include <iostream>
#include <string>

using namespace std;

void displayAbilities();
void encounterChallenge(int abilityChoice);

int main()
{
   
	int abilityChoice;

	//introduction
	cout << "Welcome, brave hero! Your quest is to overcome challenges by choosing the right abilities" << endl;
	cout << "You will be presented with a series of challenges. Choose your abilities wisely!" << endl;

	//display the abilities menu
	displayAbilities();

	cout << "Enter the number of the ability you choose (1-3): ";
	cin >> abilityChoice;

	while (abilityChoice < 1 || abilityChoice > 3) {
		cout << "Invalid choice. Please choose a number between 1 and 6: ";
		cin >> abilityChoice;

	}
	encounterChallenge(abilityChoice);

	return 0;

}
void displayAbilities() {
	cout << "\nAvailiable Abilities:" << endl;
	cout << "1. Strength - Overcome physical obstacles. " << endl;
	cout << "2. Intelligence - Solve complex problems." << endl;
	cout << "3. Agility - Evade traps and hazards." << endl;
	cout << "4. Charisma - Persuade others and gain abilites." << endl;
	cout << "5. Stealth - sneak past enemies unnoticed." << endl;
	cout << "6. Magic - Use spells to alter reality." << endl;
}

void encounterChallenge(int abilityChoice) {
	switch (abilityChoice) {
		case 1:
			cout << "\nYou chose Strength!" << endl;
			cout << "You face a giant boulder blocking your path" << endl;
			cout << "With your immense strength, you push the boulder aside and continue on your way." << endl;
			break;
		case 2:
			cout << "You chose Intelligence!" << endl;
			cout << "You encounter a locked door with a complex puzzle." << endl;
			cout << "Using your sharp mind, you solve the puzzle amd the door opens, allowing you to proceed." << endl;
			break;
		case 3:
			cout << "\nYou chose Agility!" << endl;
			cout << "You come across a series of dangerous traps on the ground." << endl;
			cout << "With your quick reflexes, you dodge and leap over the traps, safely making it through." << endl;
			break;
		case 4:
			cout << "\nYou chose Charisma!" << endl;
			cout << "You encounter a group of bandits blocking your path." << endl;
			cout << "With your charm and persuasive skills, you convince them to let you pass without a fight." << endl;
			break;
		case 5:
			cout << "\nYou chose Stealth!" << endl;
			cout << "You need to infiltrate an enemy camp to retreive a stolen item." << endl;
			cout << "By using your stealth abilites, you sneak past the guards and retreive the item without being detected." << endl;
			break;
		case 6:
			cout << "\You chose Magic" << endl;
			cout << "You are faced with a fiery chasm that is too wide to cross." << endl;
			cout << "Using your magical powers, you cast a spell to create a bridge over the chasm, allowing you to cross safely." << endl;
			break;
		default:
			cout << "An error occurred. Please restart the game." << endl;
			break;
	}

}
