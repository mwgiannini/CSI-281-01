/**
 * @ Author: MW Giannini
 * @ Create Time: 2022-03-23 16:50:56
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

#include "header.h"

double evalPostFix(const std::string& in)
{
    double operand, firstOperand, secondOperand, result;
    char character;
    Stack<double> operandStack;
    stringstream infix(in);

    while (infix.get(character))
    {
        if (character == ' ') continue;

        // Add operands to a stack
        else if (isdigit(character))
        {
            infix.putback(character);
            infix >> operand;
            operandStack.push(operand);
        }
        // Operate on the top two operands
        else if (character == '+' || character == '-' ||
            character == '/' || character == '*' ||
            character == '^')
        {
            secondOperand = operandStack.pop();
            firstOperand = operandStack.pop();

            switch (character)
            {
            case '+':
                result = firstOperand + secondOperand;
                break;
            case '-':
                result = firstOperand - secondOperand;
                break;
            case '*':
                result = firstOperand * secondOperand;
                break;
            case '/':
                result = firstOperand / secondOperand;
                break;
            case '^':
                result = pow(firstOperand, secondOperand);
                break;
            }
            operandStack.push(result);
        }

        else
            throw "Expression contains invalid character";
    }
    return operandStack.pop();
}

std::string toPostFix(const std::string &in)
{
    int openParCount = 0, closeParCount = 0, operandCount = 0, operatorCount = 0;
    char character;
    double operand;
    stringstream infix(in);
    stringstream postfix;
    Stack<char> operatorStack;
    string postfixString;

    while(infix.get(character))
    {
        if (character == ' ') continue;

        // Add operands to the postfix expression
        else if (isdigit(character))
        {
            infix.putback(character);
            infix >> operand;
            postfix << operand << " ";
            operandCount++;
        }
        // Empty the operator stack when closing a set of parentheses
        else if (character == ')')
        {
            while (operatorStack.peekTop() != '(')
                postfix << operatorStack.pop() << " ";
            operatorStack.pop();
            closeParCount++;
        }
        // Add open parentheses and operators to the operator stack
        else if (character == '(')
        {
            operatorStack.push(character);
            openParCount++;
        }
        else if (character == '+' || character == '-' ||
            character == '/' || character == '*' ||
            character == '^')
        {
            operatorStack.push(character);
            operatorCount++;
        }

        else
            throw "Expression contains invalid character";
    }
    // Empty the rest of the operator stack
    while(!operatorStack.isEmpty())
        postfix << operatorStack.pop() << " ";

    // Handle exceptions
    if (closeParCount != openParCount)
        throw "Expression contains unpaired parentheses";
    else if (operatorCount < openParCount)
        throw "Expression is missing an operator";
    else if (operandCount - 1 > operatorCount)
        throw "Expression contains an extra operand";
    else if (operandCount - 1 < operatorCount || operatorCount > openParCount)
        throw "Expression is not fully parenthesized";

    // Remove extra space after last character before returning
    postfixString = postfix.str();
    postfixString = postfixString.substr(0, postfixString.length() - 1);
    return postfixString;
}