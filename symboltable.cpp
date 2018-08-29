//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

#include <string>
#include <vector>
using namespace std;

#include "symboltable.h"

//inserts an entry (a variable and its value) into the Symbol Table
void SymbolTable::insert(string variable, int value)
{
	//build a Symbol entry
    const Symbol& symbol = Symbol(variable, value);

	//adds the entry to the end of the vector
    elements.push_back(symbol);
}

//looks up the value of a variable and returns it
int SymbolTable::lookUp(string variable) const
{
	//loops through the elements of the vector
    for (int i = 0; i < elements.size(); i++)
		//if variable is found in the vector
        if (elements[i].variable == variable)
			//returns its value
             return elements[i].value;
    //if not found returns "-1"
	return -1;
}

//clears the symbol table array "elements"
void SymbolTable::init()
{
	elements.clear();
}

