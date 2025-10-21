#include <iostream>
#include <limits>
#include "Wizard.h"
#include "Tank.h"
using namespace std;


int getChoice() {
int c;
while (!(cin >> c)) {
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout << "Invalid input. Try again: ";
}
return c;
}


Player* choosePlayer(const string& playerLabel) {
cout << "\n--- " << playerLabel << " Choose Your Class ---\n";
cout << "1) Wizard\n2) Tank\n> ";


int choice = getChoice();
string name;
cout << "Enter your character name: ";
cin >> name;


switch (choice) {
case 1:
cout << name << " has chosen Wizard!\n";
return new Wizard(name);
case 2:
cout << name << " has chosen Tank!\n";
return new Tank(name);
default:
cout << "Invalid choice. Defaulting to Wizard.\n";
return new Wizard(name);
}
}