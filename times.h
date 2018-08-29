//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

class Times: public SubExpression
{
public:
	//constructor
	//uses superclass constructor for binary operations
    Times(Expression* left, Expression* right): SubExpression(left, right)
    {
    }
	//multiplies the left operand of the expression by the right operand
    int evaluate()
    {
       return left->evaluate() * right->evaluate();
    }
};