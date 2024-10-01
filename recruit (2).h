#ifndef RECRUIT_H
#define RECRUIT_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Recruit
{
 public:
   Recruit();
   Recruit(string first, string last, string position,
      string city, string state, string highSchool, string height,
      int weight, string stars, int grade, string school);
   Recruit(const Recruit & recruit);
   ~Recruit();

   string getFirstName();
   string getLastName();
   string getPosition();
   string getCity();
   string getState();
   string getHighSchool();
   string getHeight();
   int getWeight();
   string getStars();
   int getGrade();
   string getSchool();

   void setFirstName(string first);
   void setLastName(string last);
   void setPosition(string position);
   void setCity(string city);
   void setState(string state);
   void setHighSchool(string highSchool);
   void setHeight(string height);
   void setWeight(int weight);
   void setStars(string stars);
   void setGrade(int grade);
   void setSchool(string school);

   void read();
   void print();
   void read_txt(istream &in);
   void print_txt(ostream &out);
   
 private:
   string FirstName;
   string LastName;
   string Position;
   string City;
   string State;
   string HighSchool;
   string Height;
   int Weight;
   string Stars;
   int Grade;
   string School;
};

#endif