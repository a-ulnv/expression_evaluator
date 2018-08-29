//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

class IfCondition: public SubExpression
{
public:
	//constructor
	//uses superclass constructor for ternary (conditional) expressions
    IfCondition(Expression* left, Expression* right, Expression* condition): SubExpression(left, right, condition)
    {
    }
	//look and the third operand (the condition) after the "?" sign and evaluates it
	//returns the value of the first operand if the condition evaluated as true ("1")
	//returns the value of the second operand if the condition evaluated as false ("0")
    int evaluate()
    {
		if (condition->evaluate()) //evaluating the condition
		{
			//condition evaluated as true ("1")
			//return the value of the first operand
			return left->evaluate();
		}
		else
		{
			//condition evaluated as false ("0")
			//returns the value of second operand
			return right->evaluate();
		}
    }
};