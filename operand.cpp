//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

#include <cctype>
#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include <string>
#include <string>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"

//parsing the operand of the expression
//which can also be a sub-expression
Expression* Operand::parse(stringstream& in)
{
	//functional variables
    char paren;

	//the final value of the operand
    int value;

	//read separating characters
    in >> ws;

	//check if following value is a digit
    if (isdigit(in.peek())) //look ahead to check
    { 
		//if it is a digit
		//save the value
        in >> value;

		//read the literal
        Expression* literal = new Literal(value);

		//return the literal value of the operand
        return literal;
    }

	//check if the following is a parenthesis (symbolizing the sub-expression)
    if (in.peek() == '(') //look ahead to check
    { 
		//if there is a parenthesis, there is another sub-expression
		//read the parenthesis into paren variable
        in >> paren;

		//returned the parsed sub-expression
        return SubExpression::parse(in);
    }
    else
	{
		//if it is not a sub-expression and not a literal, it is a value
        return new Variable(parseName(in));
	}

	//return false ("0") if it didn't parse
	return 0;
}