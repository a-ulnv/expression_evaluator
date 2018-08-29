//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

class Disjunction: public SubExpression
{
public:
	//constructor
	//uses superclass constructor for binary operations
    Disjunction(Expression* left, Expression* right): SubExpression(left, right)
    {
    }
	//logical disjunction
	//returns "1" (true) if any or both sides of the equation are true
	//returns "0" (false) if both sides of the equation are false
    int evaluate()
    {
       return left->evaluate() || right->evaluate();
    }
};