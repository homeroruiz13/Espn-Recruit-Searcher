#include "recruitDB.h"
#include <fstream>

// Default constructor
RecruitDB::RecruitDB() {}

// Copy constructor
RecruitDB::RecruitDB(const RecruitDB &other) : recruits(other.recruits) {}

// Destructor
RecruitDB::~RecruitDB() {
    // No dynamic memory to clean up since vector handles its own memory
}

// Method to read recruits from a text file
void RecruitDB::read_txt(const string &filename) {
    ifstream inputFile(filename);

    // Check if the input file is open
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the input file." << endl;
        return;
    }

    // Clear the current recruits list
    recruits.clear();

    // Read recruits from the file
    while (inputFile) {
        Recruit recruit;

        // Skip the rank line (assuming it's a single line to skip)
        string rankLine;
        getline(inputFile, rankLine);

        // Read the recruit information
        recruit.read_txt(inputFile);

        // Check if the reading was successful before adding to the vector
        if (inputFile.fail()) {
            inputFile.clear(); // Clear the fail state
            continue; // Skip this recruit and move to the next
        }

        // Skip the blank line after recruit details
        string blankLine;
        getline(inputFile, blankLine);

        // Add the recruit to the vector
        recruits.push_back(recruit);
    }

    // Close the input file
    inputFile.close();
}

// Method to print recruits to a text file
void RecruitDB::print_txt(const string &filename) {
    ofstream outputFile(filename);

    // Check if the output file is open
    if (!outputFile.is_open()) {
        cerr << "Error: Could not open the output file." << endl;
        return;
    }

    // Write recruits to the output file
    for (size_t i = 0; i < recruits.size(); ++i) {
        // Print the rank
        outputFile << (i + 1) << endl;

        // Print the recruit's details
        recruits[i].print_txt(outputFile);

        // Print a blank line between recruits
        outputFile << endl;
    }

    // Close the output file
    outputFile.close();
}
// Search recruits by state
void RecruitDB::searchState(const string &state) {
    bool found = false;
    for (const Recruit &recruit : recruits) {
        if (recruit.getState() == state) {
            recruit.print_recruit();
            found = true;
        }
    }
    if (!found) {
        cout << "No recruits found from the state: " << state << endl;
    }
}

// Search recruits within a height range (in cm)
void RecruitDB::searchHeightRange(string minHeight, string maxHeight) {
    bool found = false;
    for (const Recruit &recruit : recruits) {
        float height = recruit.getHeight(); // Assuming height is stored as a float in cm
        if (height >= minHeight && height <= maxHeight) {
            recruit.print_recruit();
            found = true;
        }
    }
    if (!found) {
        cout << "No recruits found within the height range: " << minHeight << " - " << maxHeight << " cm" << endl;
    }
}

// Search recruits by name
void RecruitDB::searchByName(const string &name) {
    bool found = false;
    for (const Recruit &recruit : recruits) {
        if (recruit.getName() == name) {
            recruit.print_recruit();
            found = true;
        }
    }
    if (!found) {
        cout << "No recruits found with the name: " << name << endl;
    }
}

// Search recruits by multiple attributes (height and weight range)
void RecruitDB::searchByMultipleAttributes(string minHeight, string maxHeight, int minWeight, int maxWeight) {
    bool found = false;
    for (const Recruit &recruit : recruits) {
        string height = recruit.getHeight(); // Assuming height is stored as a float in cm
        int weight = recruit.getWeight(); // Assuming weight is stored as a float in kg
        if (height >= minHeight && height <= maxHeight && weight >= minWeight && weight <= maxWeight) {
            recruit.print_recruit();
            found = true;
        }
    }
    if (!found) {
        cout << "No recruits found within the specified height and weight ranges." << endl;
    }
}