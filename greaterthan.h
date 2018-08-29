//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

class GreaterThan: public SubExpression
{
public:
	//constructor
	//uses superclass constructor for binary operations
    GreaterThan(Expression* left, Expression* right): SubExpression(left, right)
    {
    }
	//checks if the left side of the expression is greater than the right side
	//return "1" (true) only if the right side is greater than the left side
	//return "0" (false) if the right side is less or equals to the left side
    int evaluate()
    {
       return left->evaluate() > right->evaluate();
    }
};