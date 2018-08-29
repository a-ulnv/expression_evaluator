//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

class Minus: public SubExpression
{
public:
	//constructor
	//uses superclass constructor for binary operations
    Minus(Expression* left, Expression* right): SubExpression(left, right)
    {
    }
	//substracts the right side of the equation from the left side
    int evaluate()
    {
       return left->evaluate() - right->evaluate();
    }
};