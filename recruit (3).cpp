#include "recruit.h"
using namespace std;

string trim(const string str)
{
   // Remove white space from both ends of string
   int start = 0;
   int end = str.length()-1;
   while ((start < int(str.length())) && (isspace(str[start]))) start++;
   while ((end > start) && (isspace(str[end]))) end--;
   return str.substr(start, (end-start+1));
}

int range(int input, int minval, int maxval)
{
   // Force input to be in [minval..maxval] range
   if (input < minval)
      return minval;
   else if (input > maxval)
      return maxval;
   else
      return input;
}

Recruit::Recruit()
{
   FirstName = "none";
   LastName = "none";
   Position = "none";
   City = "none";
   State = "none";
   HighSchool = "none";
   Height = "none";
   Weight = 0;
   Stars = "none";
   Grade = 0;
   School = "none";
}

Recruit::Recruit(string first, string last, string position, 
   string city, string state, string highSchool, string height,
   int weight, string stars, int grade, string school)
{
   FirstName = trim(first);
   LastName = trim(last);
   Position = trim(position);
   City = trim(city);
   State = trim(state);
   HighSchool = trim(highSchool);
   Height = trim(height);
   Weight = range(weight, 0, 1000);
   Stars = trim(stars);
   Grade = range(grade, 0, 100);
   School = trim(school);
}

Recruit::Recruit(const Recruit & recruit)
{
   FirstName = recruit.FirstName;
   LastName = recruit.LastName;
   Position = recruit.Position;
   City = recruit.City;
   State = recruit.State;
   HighSchool = recruit.HighSchool;
   Height = recruit.Height;
   Weight = recruit.Weight;
   Stars = recruit.Stars;
   Grade = recruit.Grade;
   School = recruit.School;
}

Recruit::~Recruit()
{
}

string Recruit::getFirstName()
{
   return FirstName;
}

string Recruit::getLastName()
{
   return LastName;
}

string Recruit::getPosition()
{
   return Position;
}

string Recruit::getCity()
{
   return City;
}

string Recruit::getState()
{
   return State;
}

string Recruit::getHighSchool()
{
   return HighSchool;
}

string Recruit::getHeight()
{
   return Height;
}

int Recruit::getWeight()
{
   return Weight;
}

string Recruit::getStars()
{
   return Stars;
}

int Recruit::getGrade()
{
   return Grade;
}

string Recruit::getSchool()
{
   return School;
}

void Recruit::setFirstName(string first)
{
   FirstName = trim(first);
}

void Recruit::setLastName(string last)
{
   LastName = trim(last);
}

void Recruit::setPosition(string position)
{
   Position = trim(position);
}

void Recruit::setCity(string city)
{
   City = trim(city);
}

void Recruit::setState(string state)
{
   State = trim(state);
}

void Recruit::setHighSchool(string highSchool)
{
   HighSchool = trim(highSchool);
}

void Recruit::setHeight(string height)
{
   Height = trim(height);
}

void Recruit::setWeight(int weight)
{
   Weight = range(weight, 0, 1000);
}

void Recruit::setStars(string stars)
{
   Stars = trim(stars);
}

void Recruit::setGrade(int grade)
{
   Grade = range(grade, 0, 100);
}

void Recruit::setSchool(string school)
{
   School = trim(school);
}

void Recruit::read()
{
   string input;
   cout << "Enter FirstName: ";
   getline(cin, input); setFirstName(input);
   cout << "Enter LastName: ";
   getline(cin, input); setLastName(input);
   cout << "Enter Position: ";
   getline(cin, input); setPosition(input);
   cout << "Enter City: ";
   getline(cin, input); setCity(input);
   cout << "Enter State: ";
   getline(cin, input); setState(input);
   cout << "Enter HighSchool: ";
   getline(cin, input); setHighSchool(input); 
   cout << "Enter Height: ";
   getline(cin, input); setHeight(input);
   cout << "Enter Weight: ";
   getline(cin, input); setWeight(atoi(input.c_str()));
   cout << "Enter Stars: ";
   getline(cin, input); setStars(input);
   cout << "Enter Grade: ";
   getline(cin, input); setGrade(atoi(input.c_str()));
   cout << "Enter School: ";
   getline(cin, input); setSchool(input);
}

void Recruit::print()
{
   cout << "FirstName:  (" << FirstName << ")" << endl
        << "LastName:   (" << LastName << ")" << endl
        << "Position:   (" << Position << ")" << endl
        << "City:       (" << City << ")" << endl 
        << "State:      (" << State << ")" << endl 
        << "HighSchool: (" << HighSchool << ")" << endl 
        << "Height:     (" << Height << ")" << endl 
        << "Weight:     (" << Weight << ")" << endl 
        << "Stars:      (" << Stars << ")" << endl 
        << "Grade:      (" << Grade << ")" << endl 
        << "School:     (" << School << ")" << endl;
}

void Recruit::read_txt(istream &in) {
    if (in >> FirstName >> LastName >> Position >> City >> State >> HighSchool >> Height >> Weight >> Stars >> Grade >> School) {
        // Successfully read a recruit from the file
    } else // Clear the error state of the stream in case of failure
        cout << "Error reading recruit information from the file." << endl;
    }


void Recruit::print_txt(ostream &out) {
    out << FirstName << " " << LastName << " " << Position << " " << City << " " << State << " " << HighSchool << " " <<  Height << " " << Weight << " " << Stars << " " << Grade << "" << School;
}