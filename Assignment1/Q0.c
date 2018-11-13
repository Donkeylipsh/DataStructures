/* CS261- Assignment 1 - Q. 0*/
/* Name: Colin Van Overschelde
 * Solution description: Q0.c is a program that prints the address of an int x, and then passes
 * 			 a pointer to x to function fooA.  When fooA completes, the value of x
 * 			 is printed and the program exits 
 */

#include <stdio.h>
#include <stdlib.h>

/***************************************************************************************
 * Function: fooA(int* iptr)
 * Description: Accepts as a parameter a pointer to an int, prints the value 
 * 		pointed to by iptr, prints the address pointed to by iptr, and prints the 
 * 		address of iptr itself
 * Parameters: iptr is a pointer to an integer
 * Pre-Conditions: n/a
 * Post-Conditions: n/a
****************************************************************************************/  
void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
    printf("Value pointed to by iptr*: %d\n", *iptr);

     /*Print the address pointed to by iptr*/
    printf("Address pointed to by iptr*: %p\n", iptr);

     /*Print the address of iptr itself*/
     printf("Address of iptr itself: %p\n", &iptr);
}

/**********************************************************************************
 * Fuction: int main()
 * Description: main function that declares a variable x, prints it's address, calls
 * 		calls function fooA, and then prints the value of x
 * Pre-Conditions: n/a
 * Post-Conditions: Program exits
 **********************************************************************************/		
int main(){

    /*declare an integer x*/
    int x;

    /*print the address of x*/
    printf("Address of x: %p\n", &x);

    /*Call fooA() with the address of x*/
    fooA(&x);

    /*print the value of x*/
    printf("Value of x: %d\n", x);

    return 0;
}
