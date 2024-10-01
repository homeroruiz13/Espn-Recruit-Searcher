#ifndef RECRUITDB_H
#define RECRUITDB_H

#include <iostream>
#include <vector>
#include <string>
#include "recruit.h"

using namespace std;

class RecruitDB {
private:
    vector<Recruit> recruits;  // Vector of Recruit objects

public:
    // Default constructor
    RecruitDB();

    // Copy constructor
    RecruitDB(const RecruitDB &other);

    // Destructor
    ~RecruitDB();

    // Method to read recruits from a text file
    void read_txt(const string &filename);

    // Method to print recruits to a text file
    void print_txt(const string &filename);
    
    void searchState(const string &State);                  // Search by state
    void searchHeightRange(string Height, string maxHeight); // Search by height range
    void searchByName(const string &name);                   // Search by name
    void searchByMultipleAttributes(string minHeight, string maxHeight, int minWeight, int maxWeight); // Search by height and weight
};


#endif
