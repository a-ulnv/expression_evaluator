//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

class Equals: public SubExpression
{
public:
	//constructor
	//uses superclass constructor for binary operations
    Equals(Expression* left, Expression* right): SubExpression(left, right)
    {
    }
	//checks if both sides of binary equation equal to each other
	//returns "1" (true) if the do, "0" (false) if they don't
    int evaluate()
    {
       return left->evaluate() == right->evaluate();
    }
};