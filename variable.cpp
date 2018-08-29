//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

#include <strstream>
#include <vector>
using namespace std;

#include "expression.h"
#include "operand.h"
#include "variable.h"
#include "symboltable.h"

extern SymbolTable symbolTable;

//evaluates the variable inside the expression
int Variable::evaluate()
{
	//looks for it in the Symbol Table and returns its value if found
    return symbolTable.lookUp(name);
}