#include "Student.h"

using namespace std;

Student::Student()
{

}

Student::~Student()
{

}

Student::Student(int ID_, string name_, string level_, string major_, double gpa_, int advisorID_)
{
  ID = ID_;
  name = name_;
  level = level_;
  major = major_;
  gpa = gpa_;
  advisorID = advisorID_;
}

string Student::getMajor()
{
  return major;
}

double Student::getGPA()
{
  return gpa;
}

void Student::setAdvisor(int advisorID_)
{
  advisorID = advisorID_;
}

int Student::getAdvisor()
{
  return advisorID;
}

void Student::printStudent()
{
  cout << "Student ID: " << ID << ", ";
  cout << "Student Name: " << name << ", ";
  cout << "Grade: " << level << ", ";
  cout << "Major: " << major << ", ";
  cout << "GPA: " << gpa << ", ";
  cout << "Advisor ID: " << advisorID << endl;
}
