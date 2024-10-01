#include "recruit.h"
#include <vector>
#include "recruitDB.h"
using namespace std;

//-----------------------------------------------------------
// Main program
//-----------------------------------------------------------
int main()
{

    // Read recruits from the input file
    RecruitDB.read_txt("top100.txt");

    // Print recruits to the output file
    RecruitDB.print_txt("output.txt");

    cout << "Recruits have been successfully read and written to the output file." << endl;

    return 0;
    
   // Ask user for number of recruits
   cout << "Enter number of recruits: ";
   int count = 0;
   cin >> count;
   cin.ignore();

   // Read Recruits from user
   vector<Recruit> data;
   for (int i=0; i<count; i++)
   {
      Recruit recruit;
      recruit.read();
      data.push_back(recruit);
   } 

   // Printing Recruits to screen
   for (unsigned int i=0; i<data.size(); i++)
   {
      cout << i+1 << endl;
      data[i].print();
      cout << endl;
   }
   return 0;
}