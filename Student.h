#include <iostream>
#include "Person.h"

using namespace std;

class Student : public Person
{
  private:

  public:
    string major;
    double gpa;
    int advisorID;

    Student();
    ~Student();
    Student(int ID_, string name_, string level_, string major_, double gpa_, int advisorID_);

    string getMajor();
    double getGPA();

    void setAdvisor(int advisorID_);
    int getAdvisor();

    void printStudent();

    bool operator == (const Student &s)
    {
      return(this->ID == s.ID);
    }
    bool operator != (const Student &s)
    {
      return(this->ID != s.ID);
    }
    bool operator <= (const Student &s)
    {
      return(this->ID <= s.ID);
    }
    bool operator >= (const Student &s)
    {
      return(this->ID >= s.ID);
    }
    bool operator < (const Student &s)
    {
      return(this->ID < s.ID);
    }
    bool operator > (const Student &s)
    {
      return(this->ID > s.ID);
    }

    friend ostream& operator << (ostream& output, const Student &s)
    {
      output << "Student ID: " << s.ID << endl;
      output << "Student Name: " << s.name << endl;
      output << "Grade: " << s.level << endl;
      output << "Major: " << s.major << endl;
      output << "GPA: " << s.gpa << endl;
      output << "Advisor ID: " << s.advisorID << endl;
      return output;
    }
};
