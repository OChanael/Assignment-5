#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string>
#include <fstream>
#include <sstream>
#include "BST.h"

using namespace std;

class Processor
{
  private:

  public:
    BST<Student> masterStudent;
    BST<Faculty> masterFaculty;

    Processor();
    ~Processor();

    void readFile();
    void writeFile();

    void printMS(TreeNode<Student> *s);
    void printMF(TreeNode<Faculty> *f);

    void outputMS(TreeNode<Student> *s, string student);
    void outputMF(TreeNode<Faculty> *f, string faculty);

    TreeNode<Student>* getMSRoot();
    TreeNode<Faculty>* getMFRoot();

    void printMenu();
    void printAllStudents();
    void printAllFaculty();
    void printStudent();
    void printFaculty();
    void printAdvisor();
    void printAdvisee();

    void addStudent();
    void deleteStudent();
    void addFaculty();
    void deleteFaculty();
    void changeAdvisor();
    void removeAdvisee();

    void rollback();

    void exit();
};
