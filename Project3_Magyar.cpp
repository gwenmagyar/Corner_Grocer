#include <iostream>
#include <fstream>
#include <map>

using namespace std;

// Class Grocer used with Private and Public classes
class Grocer {
private:
    map<string, int> items;

public:

    // Used to open from a file
    void readFile(string fileName) {
        ifstream inputFile;
        inputFile.open(fileName);

        // If else to determine if the file is open
        if (inputFile.is_open()) {
            string item;

            // Closes the file after it has been used
            while (inputFile >> item) {
                items[item]++;
            }
            inputFile.close();
        }
        else {
            cout << "Unable to open file" << endl;
        }
    }

    // Used to write the information to a file
    void writeFile(string fileName) {
        ofstream outputFile;
        outputFile.open(fileName);

        // If else to determine if the file is open
        if (outputFile.is_open()) {

            // Closes the output file after it has been used
            for (auto const& item : items) {
                outputFile << item.first << " " << item.second << endl;
            }
            outputFile.close();
        }
        else {
            cout << "Unable to open file" << endl;
        }
    }

    // Looks at the file that is opened to get the counts
    int findItem(string item) {
        if (items.count(item) > 0) {
            return items[item];
        }
        else {
            return 0;
        }
    }

    // Prints out the frequency of an item
    void printFrequency() {
        for (auto const& item : items) {
            cout << item.first << " " << item.second << endl;
        }
    }

    // Prints out the histogram for the items using an *
    void printHistogram() {
        for (auto const& item : items) {
            cout << item.first << " ";
            for (int i = 0; i < item.second; i++) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

int main() {
    
    // Grocer class called to open and write information
    Grocer grocer;
    grocer.readFile("CS210_Project_Three_Input_File.txt");
    grocer.writeFile("frequency.dat");

    int choice;
    string item;

    // do while used for the different choices
    do {

        // Displays the menu
        cout << "1. Find item frequency" << endl;
        cout << "2. Print frequency of all items" << endl;
        cout << "3. Print histogram of all items" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;


        // Switch case used for the different choices
        switch (choice) {
        case 1:
            cout << "Enter item: ";
            cin >> item;
            cout << "Frequency: " << grocer.findItem(item) << endl;
            break;

        case 2:
            grocer.printFrequency();
            break;

        case 3:
            grocer.printHistogram();
            break;

        case 4:
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}