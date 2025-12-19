#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// load input file and populate the frequency map
void GroceryTracker::loadData(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Could not open input file " << filename << endl;
        return;
    }

    string item;
    while (inputFile >> item) {
        itemFrequency[item]++;
    }

    inputFile.close();
}

// save frequency data to backup file
void GroceryTracker::backupData(const string& backupFile) {
    ofstream outFile(backupFile);
    if (!outFile) {
        cerr << "Error: Could not create backup file " << backupFile << endl;
        return;
    }

    for (const auto& pair : itemFrequency) {
        outFile << pair.first << " " << pair.second << endl;
    }

    outFile.close();
}

// constructor
GroceryTracker::GroceryTracker(const string& inputFile, const string& backupFile) {
    loadData(inputFile);
    backupData(backupFile);
}

// menu option 1 - search for a specific item
void GroceryTracker::searchItem() {
    string searchWord;
    cout << "Enter item to search: ";
    cin >> searchWord;
    int frequency = itemFrequency[searchWord]; // Returns 0 if not found
    if (frequency == 1) {
        cout << searchWord << " appears " << frequency << " time." << endl;     //if there's only one occurence
        return;
    }
    else {
        cout << searchWord << " appears " << frequency << " times." << endl;    //if there's multiple occurences
    }
}


// menu option 2 - print all items with frequencies
void GroceryTracker::printFrequencies() {
    cout << "\nItem Frequency List:\n";
    for (const auto& pair : itemFrequency) {
        cout << left << setw(15) << pair.first 
             << pair.second << " " 
             << (pair.second == 1 ? "time" : "times") << endl;  //adjusts for singular or plural
    }
}


// menu option 3 - print histogram
void GroceryTracker::printHistogram() {
    cout << "\nItem Frequency Histogram:\n";
    for (const auto& pair : itemFrequency) {
        cout << left << setw(15) << pair.first;
        for (int i = 0; i < pair.second; i++) {
            cout << "*";
        }
        cout << endl;
    }
}
