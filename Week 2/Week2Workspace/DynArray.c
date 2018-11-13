/*************************************************************************************************
* Author: Colin Van Overschelde
* Course: CS 261 - Data Structures
* Description: DynArray.c demonstrates the Dynamic Array data structure
**************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

// DynArray is a struct that represents a dynamic array data structure
struct DynArray{

    int *data;
    int size;
    int capacity;

};

/*************************************************************************************************
* initDynArray is a function to initialize an input DynArray struct with dynamic memory and assigns values to the
* capacity and size variables of the DynArray
**************************************************************************************************/
void initDynArray(struct DynArray *v, int cap){
	// Allocate dynamic memory for cap number of integers in the array
    printf("* initDynArray - Allocating memory...\n");
    v->data = malloc(sizeof(int) * cap);

	// Validate the memory was successfully allocated
    printf("* initDynArray - Asserting success...\n");
	assert(v->data != 0);

	// Assigns values to capacity and size variables of the input DynArray
    printf(" initDynArray - Assigning cap to v->capacity\n");
    v->capacity = cap;

    printf(" initDynArray - Assigning 0 to v->size\n");
    v->size = 0;
}

/*************************************************************************************************
* freeDynArray is a function to free the memory allocated to the DynArray and then resets all the 
* DynArray data structure's variable values to 0
**************************************************************************************************/
void freeDynArray(struct DynArray *v){
	// Check if the input DynArray has memory allocated
    if(v->data != 0){
		// If yes, free the allocated memory
        free(v->data);
		// Reset the memory location of the input DynArray to Null
        v->data = 0;
    }

	// Reset the input DynArray's variable values to 0
    v->size = 0;
    v->capacity = 0;
}

/*************************************************************************************************
* sizeDynArray is a function to return the size variable value for an input DynArray struct
**************************************************************************************************/
int sizeDynArray(struct DynArray *v){
	// Return the size value of the input struct
    return v->size;
}

/*************************************************************************************************
* setCapacityDynArray is a function that sets the capacity for an input DynArray struct. 
* This is done by allocating a new int array in dynamic memory and then if the input Dyn array struct
* contains an array that already exists, the existing values will be copied to the newly allocated array.
* If the size of the existing array is greater than the new capacity, all additional elements will be
* truncated.
**************************************************************************************************/
void setCapacityDynArray(struct DynArray *v, int cap){
	// Allocate memory for the new array
    int *tempArray = malloc(sizeof(int) * cap);

	// Store the size of the new array
	int tempSize;
	// Check if the new cap value is less than the current size of the array
	if (cap <= v->size) {
		// If yes, set tempSize to the input cap value
		tempSize = cap;
	}
	else {
		// If not, set tempSize to the size of the existing array
		tempSize = v->size;
	}

    // Check if data already exists
    if(v->data != 0){
        // If yes, copy contents of v->data to tempArray
        for(int i = 0; i < v->size; i++){
            tempArray[i] = v->data[i];
        }

        // Free the memory allocated to the existing array
        freeDynArray(v);
    }

	// Assignn the new array to the DynArray
    v->data = tempArray;
	// Update the size value of the DynArray to the new size
    v->size = tempSize;
	// Update the capacity of the DynArray to the new capacity
    v->capacity = cap;
}

/*************************************************************************************************
* addDynArray is a function to add a new integer element to the DynArray.
* If there are no empty elements in the array, a new array will be allocated twice the size of the 
* existing array
**************************************************************************************************/
void addDynArray(struct DynArray *v, int val){
	// Check if there is an empty element in the array
    if(v->size = v->capacity){
		// If not, copy all values in the array to a new array twice the size of the existing array
        setCapacityDynArray(v, 2 * v->capacity);
    }

	// Add the input value to the end of the array
    v->data[v->size] = val;
	//Increment the size of the array
    v->size++;

}

/*************************************************************************************************
* fillArray is a function that assigns a random integer value to each element in a DynArray
**************************************************************************************************/
void fillArray(struct DynArray *v){
	// Check if the array has been allocated to memory
    assert(v->data != 0);

	// Initialize each element of the array to a random value
    for(int i = 0; i < v->capacity; i++){
		//Generate a random value for the current element
        v->data[i] = rand();
		//Display the value assigned to the current element
        printf("Assigning %d to someArray[%d]\n", v->data[i], i);
    }
	// Update the size value of the DynArray
    v->size = v->capacity;
}

/*************************************************************************************************
* printArray is a function to display the value of each element in the DynArray
**************************************************************************************************/
void printArray(struct DynArray *v){
	// Check if the array has been allocated to memory
	assert(v->data != 0);

	// Print the array properties
    printf("*************************\n");
    printf("* Size = %d\n", v->size);
    printf("* Capacity = %d\n", v->capacity);

    // Print each element in the array
    for(int i = 0; i < v->size; i++){

        printf("* someArray[%d] = %d\n", i, v->data[i]);
    }

}

/*************************************************************************************************
* swapDynArr is a function to swap two values within an input DynArray
**************************************************************************************************/
void swapDynArr (struct DynArray * v, int i, int j) {
	// Check to make sure i and j are valid indexes
	assert( i >= 0 && i < v->size );
	assert( j >= 0 && j < v->size );

	// Copy the value of v->data[i] to tempInt
	int tempInt = v->data[i];
	// Copy the value of v->data[j] to v->data[i]
	v->data[i] = v->data[j];
	// Copy the value of tempInt to v->data[j]
	v->data[j] = tempInt;
}

/*************************************************************************************************
* The main function of DynArray.c is a function to test each function of the DynArray data structure
**************************************************************************************************/
int main(int argc, char** argv){

    printf("Declaring struct someArray...\n");
    struct DynArray someArray;

    printf("Initializing someArray...\n");
    initDynArray(&someArray, 20);

	printf("Testing DynArray functions on someArray...\n");
    printArray(&someArray);

    fillArray(&someArray);

    printArray(&someArray);

    addDynArray(&someArray, 36);

    printArray(&someArray);

    swapDynArr(&someArray, 5, 20);

    printArray(&someArray);

    printf("Freeing someArray...\n");
    freeDynArray(&someArray);

    return 0;
}
