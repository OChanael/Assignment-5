#include "Faculty.h"

using namespace std;

Faculty::Faculty()
{

}

Faculty::~Faculty()
{
  delete []adviseeArray;
}

Faculty::Faculty(int ID_, string name_, string level_, string department_)
{
  ID = ID_;
  name = name_;
  level = level_;
  department = department_;

  adviseeArray = new int[5];
  numAdvisee = 0;
  maxSize = 5;

  for(int i = 0; i < 5; ++i)
  {
    adviseeArray[i] = -1;
  }
}

void Faculty::printFaculty() {
  cout << "Faculty ID:  " << ID << ", ";
  cout << "Faculty Name: " << name << ", ";
  cout << "Level: " << level << ", ";
  cout << "Department: " << department << ", ";
  cout << "Advisee IDs: ";
  printAdvisee();
}

void Faculty::printAdvisee()
{
  if(numAdvisee == 0) {
    cout << "None";
  }
  else
  {
    for(int i = 0; i < maxSize; ++i)
    {
      if(adviseeArray[i] != -1)
      {
        cout << adviseeArray[i];
        if(i < numAdvisee - 1)
        {
          cout  << ", ";
        }
      }
    }
  }
  cout << endl;
}

string Faculty::getDepartment()
{
  return department;
}

int Faculty::getAdviseeID()
{
  return numAdvisee;
}

void Faculty::addAdvisee(int ID)
{
  if(numAdvisee != maxSize)
  {
    int temp = 0;

    for(int i = 0; i < maxSize; ++i)
    {
      if(adviseeArray[i] == ID)
      {
        temp = maxSize;
      }
    }
    while(temp < maxSize)
    {
      if(adviseeArray[temp] == -1)
      {
        adviseeArray[temp] = ID;
        ++numAdvisee;
        break;
      }
      ++temp;
    }
  }
  else
  {
    if(numAdvisee == maxSize)
    {
      int *tempArray = new int[numAdvisee];

      for(int i = 0; i < numAdvisee; ++i)
      {
        tempArray[i] = adviseeArray[i];
      }

      adviseeArray = new int[numAdvisee + 1];
      maxSize = numAdvisee + 1;

      for(int i = 0; i < numAdvisee; ++i)
      {
        adviseeArray[i] = tempArray[i];
      }

      for(int i = numAdvisee; i < numAdvisee + 1; ++i)
      {
        adviseeArray[i] = -1;
      }

      adviseeArray[++numAdvisee] = ID;
    }
  }
}

bool Faculty::removeAdvisee(int adviseeID)
{
  bool removed = false;

  for(int i = 0; i < maxSize; ++i)
  {
    if(adviseeArray[i] == adviseeID)
    {
      adviseeArray[i] = -1;
      --numAdvisee;
      removed = true;
    }
    if(!removed)
    {
      cout << "Advisee Succesfully Removed" << endl;
    }
    return removed;
  }
}

int Faculty::getSizeArray()
{
  return maxSize;
}
