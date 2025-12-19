#include <iostream>
#include <limits>
#include "GroceryTracker.h"

using namespace std;

// display menu options
void displayMenu() {
    cout << "\n====== Corner Grocer Menu ======\n";
    cout << "1. Search for an item\n";
    cout << "2. Print all items with frequencies\n";
    cout << "3. Print histogram\n";
    cout << "4. Exit\n";
    cout << "Enter your choice (1-4): ";
}

int main() {
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");

    int choice;

    do {
        displayMenu();
        cin >> choice;

        // input validation
        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Enter a number between 1 and 4: ";
            cin >> choice;
        }

        switch (choice) {
            case 1:
                tracker.searchItem();
                break;
            case 2:
                tracker.printFrequencies();
                break;
            case 3:
                tracker.printHistogram();
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
        }

    } while (choice != 4);

    return 0;
}
