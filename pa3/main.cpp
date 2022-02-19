/*  Author: MW Giannini
    Class: CSI-281-01
    Assignment: PA3
    Date Assigned: 02/10/2022
    Due Date: 02/11/2022
    Description: A stub driver to test sortingFunctions.h
    Certification of Authenticity:
    I certify that this is entirely my own work, except where I have given
    fully-documented references to the work of others. I understand the definition and
    consequences of plagiarism and acknowledge that the assessor of this assignment
    may, for the purpose of assessing this assignment:
    - Reproduce this assignment and provide a copy to another member of academic staff;
    and/or
    - Communicate a copy of this assignment to a plagiarism checking service (which may
    then retain a copy of this assignment on its database for the purpose of future
    plagiarism checking)
*/

#include "RandIntArray.h"
#include "tests.h"
#include <assert.h>

int main()
{
  int SIZE = 1000;
  int MAX = 10000;
  RandIntArray test(SIZE, MAX);

  //printTest(Bubble, test);
  //printTest(Insertion, test);
  //printTest(Merge, test);
  //printTest(Quick, test);
  //printTest(Selection, test);
  //printTest(Shell, test);

  assert(sortTest(test));

  return 0;
}