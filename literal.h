//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

class Literal: public Operand
{
public:

	//constructor
	//sets the value of the literal
    Literal(int value)
    {
        this->value = value;
    }

	//return the value of the literal
    int evaluate()
    {
        return value;
    }

private:

	//the value of the literal
    int value;

};