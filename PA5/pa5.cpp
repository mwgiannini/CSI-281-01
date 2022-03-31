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
 * @ Description: A scientific calculator implementation to solve fully parenthesized expressions.
 */

#include <iostream>
#include <assert.h>
#include "header.h"

int main()
{
	assert(toPostFix("((10 - (2 + 3)) * 2)") == "10 2 3 + - 2 *");

	string infix, postfix, response;
	bool quit = false, validInfix;

	while (!quit)
	{
		cout << "\nEnter an fully-parenthesized infix expression: \n";
		
		try
		{
			getline(cin, infix);
			postfix = toPostFix(infix);

			cout << "Postfix: " << postfix << endl;
			cout << "Evaluated: " << evalPostFix(postfix) << endl;
		}
		catch (const char *exception)
		{
			cout << exception << endl;
		}

		response = "";
		while (response != "y" && response != "Y" &&
			response != "n" && response != "N")
		{
			cout << "Would you like to evaluate another expression? (y/n)";
			getline(cin, response);
		}
		quit = (response == "n" || response == "N");
	}

	return 0;
}