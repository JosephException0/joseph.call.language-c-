#include "DynamicArrayList.h"
#include <iostream>
#include "struct.h"

int main() {
    DynamicArrayList* list = new DynamicArrayList();
    DynamicArrayList* list2 = new DynamicArrayList();
    char choice;
    int value, pos, start, end;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "a. Add an element\n";
        std::cout << "g. Get an element at position\n";
        std::cout << "r. Remove an element\n";
        std::cout << "t. Remove at position\n";
        std::cout << "i. Add at position\n";
        std::cout << "c. Combine with another list\n";
        std::cout << "n. Remove range\n";
        std::cout << "p. Print the list\n";
        std::cout << "x. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 'a':
                std::cout << "Enter value to add: ";
                std::cin >> value;
                list->add(value);
                break;
            case 'g':
                std::cout << "Enter position: ";
                std::cin >> pos;
                try {
                    std::cout << "Element at position " << pos << ": " << list->get(pos) << std::endl;
                } catch (const std::out_of_range& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            case 'r':
                std::cout << "Enter value to remove: ";
                std::cin >> value;
                if (list->remove(value) != -1) {
                    std::cout << "Value removed successfully.\n";
                } else {
                    std::cout << "Value not found.\n";
                }
                break;
            case 't':
                std::cout << "Enter position to remove: ";
                std::cin >> pos;
                try {
                    std::cout << "Removed value: " << list->removeAt(pos) << std::endl;
                } catch (const std::out_of_range& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            case 'i':
                std::cout << "Enter position: ";
                std::cin >> pos;
                std::cout << "Enter value: ";
                std::cin >> value;
                try {
                    list->addAt(pos, value);
                    std::cout << "Value added successfully.\n";
                } catch (const std::out_of_range& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            case 'c':
                std::cout << "Enter elements for the second list (enter -1 to stop):\n";
                while (true) {
                    std::cin >> value;
                    if (value == -1) break;
                    list2->add(value);
                }
                list->combine(list2);
                std::cout << "Lists combined.\n";
                break;
            case 'n':
                std::cout << "Enter start position: ";
                std::cin >> start;
                std::cout << "Enter end position: ";
                std::cin >> end;
                try {
                    list->removeRange(start, end);
                } catch (const std::out_of_range& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
                break;
            case 'p':
                list->print();
                break;
            case 'x':
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 'x');

    delete list;
    delete list2;
    return 0;
}
