//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

class SubExpression: public Expression
{
public:

	//definition of the constructor for unary operations
	SubExpression(Expression* expression);

	//definition of the constructor for binary operations
    SubExpression(Expression* left, Expression* right);

	//definition of the constructor for conditional expressions with three operands
	SubExpression(Expression* trueExpr, Expression* falseExpr, Expression* conditionExpr);

	//definition of the function for parsing the subexpression
    static Expression* parse(stringstream& in);

protected: 

	//left side or the first operand in the expression
    Expression* left;

	//right side or the second operand in the expression
    Expression* right;

	//the conditional expression, or the third operand in the expression
	Expression* condition; 
};    