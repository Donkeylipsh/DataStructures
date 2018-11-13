/* CS261- Assignment 1 - Q.3*/
/* Name: Colin Van Overschelde
 * Date: 1/19/2018
 * Solution description: Q3.c demonstrates allocating memorary for an array of int's with randomly 
 * 			generated values, and passing it to sort to be sorted in ascending order
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

/******************************************************************************************
 * Function: sort(int* number, int n)
 * Description: Takes an array of integers and the size of the array and sorts the elements
 * 		in ascending order
 * Parameters: int* number is an array of integers
 * 	       int n is the size of number
 * Pre-conditions: n/a
 * Post-Conditions: number is sorted in ascending order
 *****************************************************************************************/    		
void sort(int* number, int n){
     /*Sort the given array number , of length n*/
    // Loop through each int, starting from the last     
    for(int i = n - 1; i > 0; i--){
	// Set the index of the highest value to i
	int maxIndex = i;
	// Compate each value in number to number[maxIndex]
	for(int j = 0; j < i; j++){
	    if(number[j] > number[maxIndex]){
	        // If yes, set maxIndex to j
		maxIndex = j;
	    }
	}
	
	// Swap the value stored in number[maxIndex] with the value stored in number[i]
	int tempNum = number[i];
	number[i] = number[maxIndex];
	number[maxIndex] = tempNum;
    }
}

/***************************************************************************************
 * Function: main()
 * Description: Demonstrates allocating memory for an array of int's with random values and
 * 		calling sort() function to sort the numbers in ascending order
 * Parameters: n/a
 * Pre-Conditions: n/a
 * Post-Conditions: Program exits
 ***************************************************************************************/
int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;

    // Declare a loop counter variable
    int i = 0;
    
    /*Allocate memory for an array of n integers using malloc.*/
    int *someNumbers = malloc(sizeof(int) * n);
    
    /*Fill this array with random numbers, using rand().*/
    for(i = 0; i < n; i++){
	someNumbers[i] = rand();
    }
    
    /*Print the contents of the array.*/
    for(i = 0; i < n; i++){
	printf("someNumbers[%2d] = %12d\n\n", i, someNumbers[i]);
    }

    /*Pass this array along with n to the sort() function of part a.*/
    sort(someNumbers, n);
 
    /*Print the contents of the array.*/    
    for(i = 0; i < n; i++){
	printf("someNumbers[%2d] = %12d\n", i, someNumbers[i]);
    }    

    // Free allocated memory
    free(someNumbers);
 
    return 0;
}
