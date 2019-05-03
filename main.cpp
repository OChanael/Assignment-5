#include <iostream>
#include "Processor.h"

using namespace std;

int main(int argc, char** argv)
{
  Processor p;

  p.readFile();
  p.printMenu();
  p.writeFile();

  return 0;
}
