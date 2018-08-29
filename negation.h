//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

class Negation: public SubExpression
{
public:
	//constructor
	//uses superclass constructor for unary operations
    Negation(Expression* left): SubExpression(left)
    {
    }
	//performs negation (logical compliment)
	//returns true ("1") if the expression is evaluated as false ("0")
	//returns false ("0") if the expression is evaluated as true ("1")
    int evaluate()
    {
       return !(left->evaluate());
    }
};