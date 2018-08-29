//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

//one SymbolTable for all the expressions
//will be cleared for every new line of input - expression (not sub-expression)
SymbolTable symbolTable;

//function definition for assigning the values to the variables in the expression
void parseAssignments(stringstream& in);

//the main function
int main()
{
	//maximum number of characters per line;
	const int SIZE = 256;

	//the expression object
    Expression* expression;

	//functional variables
    char paren, comma, line[SIZE];

	//declaring file input
	ifstream fin("input.txt");

	//loops throught the lines in the input file, each representing a new expression
	//evaluates each expression, and print the value after each expression evaluated
	while (true)
	{
		//clears the SymbolTable for the new expression
		symbolTable.init();

		//gets a new line of no longer than SIZE # of characters
		fin.getline(line, SIZE);

		//exits the loop if the end of the file reached
		if (!fin)
			break;

		//a reader through the selected line (expression)
		stringstream in(line, ios_base::in);

		//reads the open parenthesis into the paren variable
		in >> paren;

		//prints the line (expressions) and adds space after it
		cout << line << " ";

		//evaluates the expression, that "in" is pointing at
		expression = SubExpression::parse(in);

		//reads the comma into the comma variable
		in >> comma;

		//assigns the values to the variables in the expression
		parseAssignments(in);

		//returns the integer value of the expression
		int result = expression->evaluate();

		//prints the value of the expression after the expression
		cout << "Value = " << result << endl;
	}

	//pauses the program for the user to see the output
	system("PAUSE");
}

//reads the assignemtns
//assigns the values to the variables in the expression
//stores them assignments in SymbolTable
void parseAssignments(stringstream& in)
{
	//functional variables
    char assignop, delimiter;

	//variable's name
    string variable;

	//variable's value
    int value;

	//loop through assignments
    do
    {
		//get the name of the variable
        variable = parseName(in);

		//get the value after the assign operator and before the delimiter
        in >> ws >> assignop >> value >> delimiter;

		//enter the assignemtn into the SymbolTable
        symbolTable.insert(variable, value);
    }
	//repeat while the delimiter is ","
    while (delimiter == ',');
}
   
