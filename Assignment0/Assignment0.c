/*******************************************************************************************
 * Author: 		Colin Van Overschelde
 * Date Created: 	1/15/2018
 * Last Modified Date:	1/15.2018
 * File name:		Assignment0.c
 *
 * Overview:
 * 	Assignment0.c is a program that calculates of a triagle given 3 side lengths and 
 * 	outputs the result
 *
 * Input:			
 *	The input of this program has been hardcoded into variables a, b and c
 *
 * Output:
 * 	The output of this program will display the calculated area of the triangle
*******************************************************************************************/

#include <stdio.h>	// Required for printf
#include <math.h>	// Required for sqrt

void main (int argc, char **argv) 
{

    double a = 10.0, 	// Length of side a
	   b = 15.0,	// length of side b
	   c = 20.0,	// Length of side c
	   perimeter,	// Perimeter of the triangle, this value is calculated
	   area;	// Area of the triangle, this value is calculated
    
    // Calculate the perimeter of the triangle
    perimeter = ( a + b + c ) / 2.0;

    // Use the result of perimeter to calculate the area of the triangle
    area = sqrt( perimeter * ( perimeter - a ) * ( perimeter - b ) * ( perimeter - c ) );

    // Display the area of the triangle
    printf("The are of the triangle is: %lf\n", area);

} 
