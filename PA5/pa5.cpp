/**
 * @ Author: MW Giannini
 * @ Create Time: 2022-03-23 16:50:23
 * @ Course: CSI-281-01
 * @ Assignment: PA5
 * @ Certificate of Authenticity: I certify that this is entirely my own work, except where I have given
 * @ : fully-documented references to the work of others. I understand the definition and
 * @ ~: consequences of plagiarism and acknowledge that the assessor of this assignment
 * @ ~~: may, for the purpose of assessing this assignment:
 * @ ~~~: - Reproduce this assignment and provide a copy to another member of academic staff;
 * @ ~~~~: and/or
 * @ ~~~~~: - Communicate a copy of this assignment to a plagiarism checking service (which may
 * @ ~~~~~~: then retain a copy of this assignment on its database for the purpose of future
 * @ ~~~~~~~: plagiarism checking)
 * @ Description: A scientific calculator implementation.
 */

#include <iostream>
#include <assert.h>
#include "header.h"

int main()
{
	assert(toPostFix("((10 - (2 + 3)) * 2)") == "10 2 3 + - 2 *");
	assert(toPostFix("6+9+(4*2+4^2)") == "6 9 + 4 2 * 4 2 ^ + +");
	assert(toPostFix("2*20/2+(3+4)*3^2-6+15") == "2 20 * 2 / 3 4 + 3 2 ^ * + 6 - 15 +");
	assert(toPostFix("(18/3)^2+((13+7)*5^2)") == "18 3 / 2 ^ 13 7 + 5 2 ^ * +");

	return 0;
}