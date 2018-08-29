//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

class Operand: public Expression
{
public:
	//definition of the function to parse an operand
    static Expression* parse(stringstream& in);
};
