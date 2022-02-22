/*  Author: MW Giannini
    Class: CSI-281-01
    Assignment: PA3
    Date Assigned: 02/21/2022
    Due Date: 02/28/202
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

#include "generateData.h"
#include "tests.h"
#include <assert.h>
#include <iomanip>

int main()
{
  int N = 10000;

  int *test = new int[N];
  readArray(test, N, "test-2-average.dat");
  std::cout << "Array created\n";

  double timeTaken = testSort(test, N, Merge);

  std::cout << std::fixed << std::setprecision(15);
  std::cout << "The test took  " << timeTaken << " seconds.\n";

  system("pause");
  delete [] test;

  return 0;
}