/********************************************************************
* CS261- Assignment 2 - Part 1
* Author: Colin Van Overschelde
* Date: 1/28/2018
* Solution Description: dynamicArray.c demonstrates the dynamic array and the dynamic array-based implementation of a stack and a bag
**********************************************************************/

/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string
	pre: s is not null
*/
char nextChar(char* s)
{
	static int i = -1;
	char c;
	++i;
	c = *(s+i);
	if ( c == '\0' )
		return '\0';
	else
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string
	pre: s is not null
	post: Returns either 1 (true), or 0 (false)
*/
int isBalanced(char* s)
{
	// Assert valid parameter
	assert(s != 0);

	// Create DynArr stack to hold "("
	DynArr *parens = newDynArr(20);

	// Create DynArr stack to hold "{"
        DynArr *braces = newDynArr(20);

	// Create DynArr stack to hold "["
	DynArr *brackets = newDynArr(20);

	// Confirm DynArr creation
	assert(parens != 0);
	assert(braces != 0);
	assert(brackets != 0);

	// Initialize loop control variables
	int balanced = 1;
	char someChar = nextChar(s);

	// loop through s until /0 or balanced == 0 is encountered
	while( (someChar != '\0') && (balanced != 0) ){
		     // check if someChar == '('
            if( someChar == '(' ){
                pushDynArr(parens, someChar);       // if yes, push onto parens
		//printf("Adding '(' to parens\n");
            }
            else if( someChar == ')' ){                     // check if next character in s is ')'
                // if yes, check if parens is empty
                if ( isEmptyDynArr(parens) == 1 ){
		    //printf("Parens already empty, setting unbalanced\n");
                     balanced = 0;                              // if yes, set balanced = 0
                }
                else{
                    popDynArr(parens);       // if no, popDynArr parens
		    //printf("Removing ')' from parens\n");
                }
            }

            // check if someChar == '{'
            if( someChar == '{' ){
                pushDynArr(braces, someChar);        // if yes, push onto braces
            }
            else if( someChar == '}' ){                     // check if next character in s is '}'
                // if yes, check if parens is empty
                if ( isEmptyDynArr(braces) == 1 ){
                     balanced = 0;                              // if yes, set balanced = 0
                }
                else{
                    popDynArr(braces);       // if no, popDynArr braces
                }
            }

            // check if someChar == '['
            if( someChar == '[' ){
                pushDynArr(brackets, someChar);        // if yes, push onto brackets
            }
            else if( someChar == ']' ){                     // check if next character in s is ']'
                // if yes, check if parens is empty
                if ( isEmptyDynArr(brackets) == 1 ){
                     balanced = 0;                              // if yes, set balanced = 0
                }
                else{
                    popDynArr(brackets);       // if no, popDynArr brackets
                }
            }

			// set someChar = nextChar
			someChar = nextChar(s);
		}

	// check if balanced = 1
	if( balanced == 1 ){
		// if yes, check if parens is empty
		if( isEmptyDynArr(parens) == 0 ){
			balanced = 0;           // if not, balanced = 0
		}
		if( isEmptyDynArr(braces) == 0 ){
			balanced = 0;           // if not, balanced = 0
		}
		if( isEmptyDynArr(brackets) == 0 ){
			balanced = 0;           // if not, balanced = 0
		}
	}

	return balanced;
}

int main(int argc, char* argv[]){

	char* s=argv[1];
	int res;

	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else
		printf("The string %s is not balanced\n",s);

	return 0;
}

