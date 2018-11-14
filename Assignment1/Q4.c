/* CS261- Assignment 1 - Q.4*/
/* Name: Colin Van Overschelde
 * Date: 1/19/2018
 * Solution description: Q4.c demonstrates allocating memory for an array of students, generating random
 * 			scores, and then sorting the students by score in ascending order
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

/*****************************************************************************************
 * Function: sort(struct student* students, int n)
 * Description: Sorts an array of students by score in ascending order
 * Parameters: struct student* students is an array of students
 * 		int n is the size of students array
 * Pre-Conditions: n/a
 * Post-Conditions: Array is sorte din ascending order
 ****************************************************************************************/
void sort(struct student* students, int n){
    // Check if the array is empty
    if(students != NULL){ 
        /*Sort the n students based on their score*/
        for(int i = n - 1; i > 0; i--){
	    // Set maxIndex to last unsorted element
	    int maxIndex = i;

	    //  Find the largest element in the unsorted section
	    for(int j = 0; j < i; j++){
		// Compare the next element to the current max
	        if(students[j].score > students[maxIndex].score){
		    // If greater, update maxIndex
		    maxIndex = j;
	        }
	    }

	    // Swap the score values in students[i] with students[maxIndex]
	    int tempMax = students[maxIndex].score;
	    students[maxIndex].score = students[i].score;
 	    students[i].score = tempMax;
	    // Swap the id values in students[i] with students[maxIndex]
	    int tempId = students[maxIndex].id;
	    students[maxIndex].id = students[i].id;
	    students[i].id = tempId;
        }
    }
}

/*************************************************************************************
 * Function: printArray(struct student* students, int n)
 * Description: Prints an array of students
 * Parameters: struct student* students is an array of students to be printed
 * 		int n is the size of the array
 * Pre-Conditions: n/a
 * Post-Conditions: Array is printed
 *************************************************************************************/
void printArray(struct student* students, int n){
    // Check if the array is empty
    if(students != NULL){
	// Print each student
	for(int i = 0; i < n; i++){
	    printf("ID: %2d Score: %3d\n", students[i].id, students[i].score);
        }
    }
}		

/************************************************************************************
 * Function: main()
 * Description: Demonstrates allocating memory for an array of struct students, generating
 * 		random data for each student, and sorting the students by score
 * Parameters: n/a
 * Pre-Conditions: n/a
 * Post-Conditions: Program exits
 ***********************************************************************************/
int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 20;    

    /* Declare a loop control integer i */ 
    int i; 

    /*Allocate memory for n students using malloc.*/
    struct student* someStudents = malloc(sizeof(struct student) * n);    

    // newId is the newly generated id
    int newId;

    // isUnique is used to test if the generated id is unique 
    int isUnique;

    // Generate IDs and Scores for each student
    for(i = 0; i < n; i++){
	// Generate a unique id
	do{
	    // Reset uniqueness control 
	    isUnique = 0;

	    // Generate a random integer between 1 and n inclusive
	    newId = (rand() % n) + 1;

	    // Check if the id already exists
	    for(int j = 0; j < i; j++){
		if(newId == someStudents[j].id){
		    // If yes, set isUnique to 1 (false)
		    isUnique = 1;
		}
	    } 
	}while(isUnique != 0);

	// Assign newId to someStudents[i].id
	someStudents[i].id = newId;
	
	// Assign a random number between 0 and 100 inclusive
	someStudents[i].score = rand() % 101;
    }    

    /*Print the contents of the array of n students.*/
    printArray(someStudents, n);
    
    /*Pass this array along with n to the sort() function*/
    sort(someStudents, n);
    
    /*Print the contents of the array of n students.*/
    printArray(someStudents, n);

    /* Release allocated memory */
    free(someStudents);

    return 0;
}
