//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "greaterthan.h"
#include "lessthan.h"
#include "equals.h"
#include "conjunction.h"
#include "disjunction.h"
#include "negation.h"
#include "ifcondition.h"

//constructor for unary operations
SubExpression::SubExpression(Expression* expr)
{
	this->left = expr;
}

//constructor for binary operations
SubExpression::SubExpression(Expression* left, Expression* right)
{
    this->left = left;
    this->right = right;
}

//constructor for condition statements with three operands
SubExpression::SubExpression(Expression* trueExpr, Expression* falseExpr, Expression* conditionExpr)
{
	this->left = trueExpr;
	this->right = falseExpr;
	this->condition = conditionExpr;
}

//parsing the subexpression
Expression* SubExpression::parse(stringstream& in)
{
	//functional variables
	char operation, paren;

	//the first part of the expression
    Expression* left;

	//reads the first operand of the expression
    left = Operand::parse(in);

	//reads the operation following the operand
    in >> operation;

	//for operations requiring only one operand
	//negation is the only unary operation in this program
	if (operation == '!')
	{
		//reads the parenthesis into the paren variable
		in >> paren;

		//returns the value after the negation of the operand
		return new Negation(left);
	}

	//for operations requiring two or more operands
	Expression* right;

	//gets the second operand for the binary operations
    right = Operand::parse(in);

	//reads the following symbol after the operand into the paren variable
    in >> paren;
    switch (operation)
    {

		//if the operator is "+"
        case '+':
			//returns the result of the addition of two operands
            return new Plus(left, right);
		
		//if the operator is "-"
        case '-':
			//returns the result of the substraction of the right operand from the left
            return new Minus(left, right);

		//if the operator is "*"
        case '*':
			//returns the product of the multiplication of the left by the right operands
            return new Times(left, right);

		//if the operator is "/"
        case '/':
			//returns the result of division of the right operand into the left
            return new Divide(left, right);

		//if the operator is ">"
		case '>':
			//returns true ("1") if the left operand is greater than the right, else return falase ("0")
			return new GreaterThan(left, right);

		//if the operator is "<"
		case '<':
			//returns true ("1") if the left operand is less than the right, else return falase ("0")
			return new LessThan(left, right);

		//if the operator is "="
		case '=':
			//returns true ("1") if the operands are equal, else return false ("0")
			return new Equals(left, right);

		//if the operator is "&"
		case '&':
			//returns the result of conjunction of the right and the left operands in the expression
			return new Conjunction(left, right);

		//if the operator is "|"
		case '|':
			//returns the result of disjunction of the right and the left operands in the expression
			return new Disjunction(left, right);

		//if the operator is ":"
		case ':':
			//Checking if "?" sign follows, to comply with grammar rules
			if (paren == '?')
			{
				//proceeds to the condition expression
				Expression* condition = Operand::parse(in);

				//reads the parenthesis into paren variable
				in >> paren;

				//returns the outcomes of the conditional expression
				return new IfCondition(left, right, condition);
			}
    }

	//if parsing fails, returns false
    return 0;

}
        