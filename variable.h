//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

//this class represents variables in the expression
class Variable: public Operand
{
public:

	//constructor
	//assigns the name of the variable
    Variable(string name)
    {
        this->name = name;
    }

	//looks up the value of the variable in SymolTable
    int evaluate();

private:

	//the name of the variable
    string name;

};