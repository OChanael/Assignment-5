#include "Person.h"

using namespace std;

Person::Person()
{

}

Person::~Person()
{

}

void Person::setID(int value)
{
  ID = value;
}

int Person::getID()
{
  return ID;
}

string Person::getName()
{
  return name;
}

string Person::getLevel()
{
  return level;
}
