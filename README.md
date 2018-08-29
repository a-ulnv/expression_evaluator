# expression_evaluator
This program evaluates mathematical and logical expressions with the use of variables and if-statements

## Running locally
You can use a C++ compiler of your choice to build and run this project. Provide the input to the program by placing the "input.txt" in the main directory. File "module3" contains the main function which will start the program.

## Expected output
Expressions with variables:
Input: (x12yz+3), x12yz=4;
Expecting: 4 + 3 = 7
Output: (x12yz+3), x12yz=4; Value = 7
  
Expressions with multiplication and division:
Input: ( (x*y) - (x/y) ), x=5, y=2;
Expecting: ( (5*2) – (5/2) ) = (10 – 2 ) = 8
Output: ( (x*y) - (x/y) ), x=5, y=2; Value = 8

Expressions with logical operations:
Input: ( ((x=2)&(x<3)) & ((y=3)|(y<x)) ), x=2, y=3;
Expecting: ( ((true) & (true)) & ( (true) | (false) )) = 1 (true)
Output: ( ((x=2)&(x<3)) & ((y=3)|(y<x)) ), x=2, y=3; Value = 1

Expressions with negations:
Input: ( ( (x=5) ! ) ! ); x=5;
Expecting: ( ( (true) ! ) ! ) = 1 (true)
Output: ( ( (x=5) ! ) ! ); x=5; Value = 1

Expressions with subexpressions:
Input: ((((x*3)-(y*2))*(x-y)) + ( x+y ) ); x=3, y=2;
Expecting: ((((3*3)-(2*2))*(3-2))+(3+2)) = 10
Output: ((((x*3)-(y*2))*(x-y)) + ( x+y ) ); x=3, y=2; Value = 10

Expressions with if-condition:
Input: ( (x23 + y71) : ( x23 < y71 ) ? (z91 = 50 ) ); x23=50, y71=12, z91 = 51;
Expecting: 50 < 12 -> 0 (false)
Output: ( (x23 + y71) : ( x23 < y71 ) ? (z91 = 50 ) ); x23=50, y71=12, z91 = 51; Value = 0

## TODO
- Add functionality to solve polynomial expressions
