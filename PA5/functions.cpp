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

std::string toPostFix(const std::string &infix)
{
    if (infix.length() == 0) return "";

    std:string postfix;
    Stack<char> operatorStack;
    Queue<char> operandQueue;
    unordered_map<char, int> precedence{
        {'(', -1},{'-', 0},{'+', 0},{'*', 1},{'/', 1},{'^', 2}
    };
    unordered_map<char, std::string> associativity{
        {'-', "left"},{'+', "left"},{'*', "left"},{'/', "left"},{'^', "right"}
    };

    for(const char& character : infix)
    {
        if(character == ' ') continue;

        // Place digits in a queue to handle longer numbers
        if(character >= '0' && character <= '9')
            operandQueue.enqueue(character);
        else
        {
            // Empty the operand queue when reading an operator
            if(!operandQueue.isEmpty())
            {
                while(!operandQueue.isEmpty())
                    postfix += operandQueue.dequeue();
                postfix += " ";
            }

            if (character == ')')
            {
                while (operatorStack.peekTop() != '(')
                {
                    postfix += operatorStack.pop();
                    postfix += " ";
                }
                operatorStack.pop();
            }

            else if (   character == '('                ||
                        operatorStack.isEmpty()         ||
                        operatorStack.peekTop() == '('  ||
                        precedence[character] > precedence[operatorStack.peekTop()])
            {
                operatorStack.push(character);
            }

            // For right associative operators such as ^
            else if (   precedence[character] == precedence[operatorStack.peekTop()] &&
                        associativity[character] == "right")
            {
                operatorStack.push(character);
            }
            
            else
            {
                while ( !operatorStack.isEmpty()            &&
                        operatorStack.peekTop() != '('      && 
                        precedence[character] <= precedence[operatorStack.peekTop()])
                {
                    postfix += operatorStack.pop();
                    postfix += " ";
                }
                operatorStack.push(character);
            }
        }
    }
    if (!operandQueue.isEmpty())
    {
        while (!operandQueue.isEmpty())
            postfix += operandQueue.dequeue();
        postfix += " ";
    }
    while(!operatorStack.isEmpty())
    {
        postfix += operatorStack.pop();
        postfix += " ";
    }
    
    return postfix.substr(0, postfix.length() - 1);
}