//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

class Plus: public SubExpression
{
public:
	//constructor
	//uses superclass constructor for binary operations
    Plus(Expression* left, Expression* right): SubExpression(left, right)
    {
    }
	//calculates the sum of the first and second operands in the expression
    int evaluate()
    {
       return left->evaluate() + right->evaluate();
    }
};