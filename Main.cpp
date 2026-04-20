/*
Name: Phil Wesley
Course: CS 210
Assignment: Project Final - Corner Grocer
Date: 4/19/2026

Description:
This program reads a list of grocery items from a file and tracks how often each item is purchased.
It allows the user to search for a specific item, display all item frequencies, and view a histogram
representation of the data. The program also creates a backup file (frequency.dat) that stores the
item frequencies.
*/

#include <iostream>   // for input/output (cout, cin)
#include <fstream>    // for file handling
#include <string>     // for string variables
#include <map>        // for storing item frequencies
using namespace std;

class GroceryTracker {
private:
    // Map to store item names and their frequencies
    map<string, int> itemFrequencies;

public:
    // Open input file containing grocery items
    void loadFile(string fileName) {
        ifstream inFile(fileName);
        string word; // stores each item read from file

        // Check if file opened successfully
        if (!inFile.is_open()) {
            cout << "Error opening file." << endl;
            return;
        }

        // Read each word from the file and count occurrences
        while (inFile >> word) {
            itemFrequencies[word]++;
        }

        inFile.close(); // close file after reading
    }

    // Create backup file (frequency.dat) automatically
    void createBackupFile(string fileName) {
        ofstream outFile(fileName);

        for (auto item : itemFrequencies) {
            outFile << item.first << " " << item.second << endl;
        }

        outFile.close();
    }

    // Searches for a specific item and returns how many times it appears
    int searchItemFrequency(string userItem) {
        // Checks if item exists in map
        if (itemFrequencies.count(userItem) > 0) {
            return itemFrequencies[userItem];
        }
        return 0;
    }

    // Prints all item frequencies
    void printAllFrequencies() {
        for (auto item : itemFrequencies) {
            cout << item.first << " " << item.second << endl;
        }
    }

    // Prints histogram of item frequencies using asterisks
    void printHistogram() {
        for (auto item : itemFrequencies) {
            cout << item.first << " ";
            for (int i = 0; i < item.second; i++) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

int main() {
    GroceryTracker tracker;
    int choice = 0; // stores user menu selection

    tracker.loadFile("CS210_Project_Three_Input_File.txt");
    tracker.createBackupFile("frequency.dat");

    // Menu loop runs until user chooses option 4 (exit)
    while (choice != 4) {

        cout << "\nMenu" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Print all item frequencies" << endl;
        cout << "3. Print histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        // Input validation to prevent crashes from invalid input
        // Learned the hard way after testing with invalid input like letters and symbols.
        if (cin.fail()) {
            cin.clear();              // reset error state
            cin.ignore(1000, '\n');   // discard bad input
            cout << "Invalid choice. Try again." << endl;
            continue;
        }

        // Option 1: Searches for a specific item
        if (choice == 1) {
            string userItem;
            cout << "Enter item name: ";
            cin >> userItem;

            cout << userItem << " was purchased "
                 << tracker.searchItemFrequency(userItem)
                 << " time(s)." << endl;
        }

        // Option 2: Prints all item frequencies
        else if (choice == 2) {
            tracker.printAllFrequencies();
        }

        // Option 3: Prints histogram of item frequencies using asterisks
        else if (choice == 3) {
            tracker.printHistogram();
        }

        // Option 4: Exit program
        else if (choice == 4) {
            cout << "Exiting program." << endl;
        }

        // Handles invalid number choices
        else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}