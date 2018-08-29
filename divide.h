//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

class Divide: public SubExpression
{
public:
	//constructor
	//uses superclass constructor for binary operations
    Divide(Expression* left, Expression* right): SubExpression(left, right)
    {
    }
	//performs division of the right operand into the left operand of the expression
	//rounds down the result to the int value
    int evaluate()
    {
       return left->evaluate() / right->evaluate();
    }
};