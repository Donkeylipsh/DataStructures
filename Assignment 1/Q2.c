/* CS261- Assignment 1 - Q.2*/
/* Name: Colin Van Overschelde
 * Date: 1/19/2018
 * Solution description: Q2.c is a program that passes several integer variables by reference and
 * 			 value for function foo() which performs calcualtions on the variables to
 * 			 demonstrate teh difference between passing by value and reference
 */
 
#include <stdio.h>
#include <stdlib.h>

/********************************************************************************************
 * Function: foo(int* a, int* b, int c)
 * Description: Performs assignmnet calculations on each parameter and returns the value of c
 * Parameters: *a and *b are pointers to int's and c is an int
 * Pre-Conditions: n/a
 * Post-Conditions: New value of c is returned
 *******************************************************************************************/
int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a *= 2;
    
    /*Set b to half its original value*/
    *b /= 2;    

    /*Assign a+b to c*/
    c = *a + *b + c;

    /*Return c*/
    return c;
}

/*********************************************************************************************
 * Function: main()
 * Description: Initializes 3 int's and passes them to foo to demostrate the difference between 
 * 		passing by reference and value
 * Parameters: n/a
 * Pre-Conditions: n/a
 * Post-Conditions: Program exits
 ********************************************************************************************/
int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;
    
    /*Print the values of x, y and z*/
    printf("x = %d\ny = %d\nz = %d\n", x, y, z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int returned = foo(&x, &y, z);

    /*Print the value returned by foo*/
    printf("Value returned by foo(): %d\n", returned);

    /*Print the values of x, y and z again*/
    printf("x = %d\ny = %d\nz = %d\n", x, y, z);

    /*Is the return value different than the value of z?  Why?*/
    /* Answer: Yes, because z was passed by value, not by reference. Meaning the variable c in foo 
     * was a copy of the value stored in z. So when c is altered in foo, only the copy is changed, and the
     * the value stored in z is left unchanged */

    return 0;
}
    
    
