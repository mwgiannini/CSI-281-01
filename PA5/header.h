/**
 * @ Author: MW Giannini
 * @ Create Time: 2022-03-23 16:50:45
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
#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <sstream>
#include <unordered_map>
#include "stack.h"

/*
* Pre: Given a string containing a valid postfix expression.
* Post: Return a double containing the value of the given expression.
*		Throw exception for invalid characters in input expression.
* Summary: Evaluate a postfix expression.
*/
double evalPostFix(const std::string& in);


/*
* Pre: Given a string containing a infix expression.
* Post: Return the valid, equivalent postfix expression.
*		Throw exception if the input is not a valid infix expression.
* Summary: Convert an infix expression to postfix.
*/
std::string toPostFix(const std::string &s);

#endif