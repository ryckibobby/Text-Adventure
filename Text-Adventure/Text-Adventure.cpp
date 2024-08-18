

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
		cout << "Invalid choice. Please choose a number between 1 and 3: ";
		cin >> abilityChoice;

	}
	encounterChallenge(abilityChoice);

	return 0;

}
void displayAbilities() {
	cout << "\nAvailiable Abilities:" << endl;
	cout << "1. Strength - Overcome physical obstacles. " << endl;
	cout << "2. Intelligence - Solve complex problems" << endl;
	cout << "3. Agility - Evade traps and hazards" << endl;
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
		default:
			cout << "An error occurred. Please restart the game." << endl;
			break;
	}
}
