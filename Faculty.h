#include <iostream>
#include "DoublyLinkedList.h"
#include "Person.h"

using namespace std;

class Faculty : public Person
{
  private:

  public:
    string department;

    unsigned int numAdvisee;
    unsigned int maxSize;

    int *adviseeArray;

    Faculty();
    ~Faculty();
    Faculty(int ID, string name_, string level_, string department_);

    void printFaculty();
    void printAdvisee();

    string getDepartment();

    int getAdviseeID();
    void addAdvisee(int ID);
    bool removeAdvisee(int adviseeID);

    int getSizeArray();

    bool operator == (const Faculty &f)
    {
      return(this->ID == f.ID);
    }
    bool operator != (const Faculty &f)
    {
      return(this->ID != f.ID);
    }
    bool operator <= (const Faculty &f)
    {
      return(this->ID <= f.ID);
    }
    bool operator >= (const Faculty &f)
    {
      return(this->ID >= f.ID);
    }
    bool operator < (const Faculty &f)
    {
      return(this->ID < f.ID);
    }
    bool operator > (const Faculty &f)
    {
      return(this->ID > f.ID);
    }

    friend ostream& operator << (ostream& output, const Faculty &f)
    {
      output << "Faculty ID: " << f.ID << endl;
      output << "Faculty Name: " << f.name << endl;
      output << "Level: " << f.level << endl;
      output << "Department: " << f.department << endl;
      output << "Advisee IDs: ";

      return output;
    }
};
