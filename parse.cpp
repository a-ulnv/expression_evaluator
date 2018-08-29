//Compiler: Visual Studio 2012 (Intel Core i5-3210M, Windows 7)
//Last Compiled: 08-Mar-2015

#include <cctype>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#include "parse.h"

//parsing the name of a variable
//the variables can be consisted of alphanumeric characters
string parseName(stringstream& in)
{
	//functional variables
    char alnum;
    string name = "";

    in >> ws;

	//check if the following characted is an alphanumeric character
	//parses the name character by character
    while (isalnum(in.peek())) //look ahead to check, stop when not an alphanumeric char
    {
		//read the characted into a variable
        in >> alnum;

		//add the character to the name
        name += alnum;
    }

	//returns the variable's name
    return name;
}