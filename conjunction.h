//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

class Conjunction: public SubExpression
{
public:
	//constructor
	//uses superclass constructor for binary operations
    Conjunction(Expression* left, Expression* right): SubExpression(left, right)
    {
    }
	//logical conjunction
	//returns "1" (true) if both sides of the equation are true
	//returns "0" (false) if any or both sides of the equation are false
    int evaluate()
    {
       return left->evaluate() && right->evaluate();
    }
};