//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

//the class is used to store the variables and their values for an expression
class SymbolTable
{
public:

	//definition of constructor
    SymbolTable() {}

	//definition of the function for inserting a new entry into the symbol table
    void insert(string variable, int value);

	//definition of the function for looking up the variable's value by its name
    int lookUp(string variable) const;

	//definition of the function to clear the symbol table for each iteration
	void init();

private:

	//definition of a "Symbol" data-type of an entry in the symbol table
    struct Symbol
    {
		//constructor
		//creates an entry by assigning the name and the value of a variable
        Symbol(string variable, int value)
        {
            this->variable = variable;
            this->value = value;
        }

		//name of the variable
        string variable;

		//value of the variable
        int value;
    };

	//using vectors instead of arrays, for any amount of variables in the expression
    vector<Symbol> elements;
};


