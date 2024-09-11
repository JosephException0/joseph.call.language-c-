#include <iostream>
#include "imports.h"

using namespace std;

int main() {
    int testCase;
    cout << "Enter test case number: ";
    cin >> testCase;

    Character character(100, 20, 5);
    Swordsman swordsman;
    Paladin paladin;

    switch (testCase) {
        case 1:
            cout << "Testing Character class getters" << endl;
            cout << "Character - Health: " << character.getHealth() << endl;
            cout << "Character - Damage: " << character.getDamage() << endl;
            cout << "Character - Shield: " << character.getShield() << endl;
            break;

        case 2:
            cout << "Testing Swordsman class getters" << endl;
            cout << "Swordsman - Health: " << swordsman.getHealth() << endl;
            cout << "Swordsman - Damage: " << swordsman.getDamage() << endl;
            cout << "Swordsman - Shield: " << swordsman.getShield() << endl;
            break;

        case 3:
            cout << "Testing Paladin class getters" << endl;
            cout << "Paladin - Health: " << paladin.getHealth() << endl;
            cout << "Paladin - Damage: " << paladin.getDamage() << endl;
            cout << "Paladin - Shield: " << paladin.getShield() << endl;
            break;

        case 4:
            cout << "Testing damage received" << endl;
            character.receiveDamage(15);
            cout << "Character after receiving 15 damage - Health: " << character.getHealth() << endl;

            swordsman.receiveDamage(30);
            cout << "Swordsman after receiving 30 damage - Health: " << swordsman.getHealth() << endl;

            paladin.receiveDamage(40);
            cout << "Paladin after receiving 40 damage - Health: " << paladin.getHealth() << endl;
            break;

        case 5:
            cout << "Testing resurrection for Paladin" << endl;
            paladin.receiveDamage(40);
            cout << "Paladin after receiving 40 damage - Health: " << paladin.getHealth() << endl;
            paladin.resurrect();
            cout << "Paladin after resurrecting - Health: " << paladin.getHealth() << endl;
            paladin.resurrect(); // Attempt to resurrect again
            break;

        case 6:
            cout << "Testing if Swordsman is a child of Character" << endl;
            if (dynamic_cast<Character*>(&swordsman) != nullptr) {
                cout << "Swordsman is a child of Character" << endl;
            } else {
                cout << "Swordsman is not a child of Character" << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Testing if Paladin is a child of Character" << endl;
            if (dynamic_cast<Character*>(&paladin) != nullptr) {
                cout << "Paladin is a child of Character" << endl;
            } else {
                cout << "Paladin is not a child of Character" << endl;
            }
            break;

        default:
            cout << "Invalid test case number." << endl;
            break;
    }

    return 0;
}
