#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <string>
#include <map>

using namespace std;

class GroceryTracker {
private:
    map<string, int> itemFrequency; // stores each item and its frequency

    // private helpers
    void loadData(const string& filename);       // load data from input file
    void backupData(const string& backupFile);   // backup frequency to a file

public:
    // constructor
    GroceryTracker(const string& inputFile, const string& backupFile);

    // menu options
    void searchItem();        // option 1
    void printFrequencies();  // option 2
    void printHistogram();    // option 3
};

#endif
