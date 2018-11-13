/* CS261- Assignment 1 - Q.1*/
/* Name: Colin Van Overschelde
 * Date: 1/19/2018
 * Solution description: Q1.c demonstrates calling functions to allocate memorary for an array of
 * 			struct students, assign random values to id and score, display these values,
 * 			print the min, max and average score, and then deallocate the memory
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


/*************************************************************************************
 * Description: student is a structure that contains two int's, id and score, which describe a student
**************************************************************************************/ 
struct student{
	int id;
	int score;
};

const int NUM_STUDENTS = 10;	// Number of students in the array

/***********************************************************************************
 * Function: allocate()
 * Description: Creates and returns an array of struct students
 * Parameters: n/a
 * Pre-Conditions: n/a
 * Post-Conditions: An array of struct students is returned
 ***********************************************************************************/
struct student* allocate(){
     
    /*Allocate memory for ten students*/
    struct student *someStudents = malloc( sizeof(struct student) * NUM_STUDENTS );
    
    /*return the pointer*/
    return someStudents;
 
}

/*************************************************************************************
 * Function: generate(struct student* students)
 * Description: Generates random IDs and scores for eeach of the ten students and stores them 
 * 		in the array of students
 * Parameters: struct student* students is an array of NUM_STUDENTS students
 * Pre-Conditions: n/a
 * Post-Conditions: Array of 10 students have new IDs and scores assigned
 *************************************************************************************/
void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    
    // Check if the array is empty
    if (students != NULL){ 
	int isNew = 0;	// Loop control variable 
	int newId = 0;	// Last generated ID

        // Loop through each student and assign an id and score
        for(int i = 0; i < NUM_STUDENTS; i++){

	    // Assign a random number between 1 and 10
	    do{
	        // Reset loop control variable
	        isNew = 0;

	        // Generate an ID between 1 and 10
	        newId = (rand() % 10) + 1;

	        // Initialize loopCounter
	        int loopCounter = 0;

	        // Compare newId to each existing ID
	        do{
		    // Check if newId is already assigned
		    if(newId == students[loopCounter].id){
		        // If yes, assign 1 to isNew
		        isNew = 1;
		    }   

		    // Increment loopCounter
		    loopCounter++;

	        }while(loopCounter < i && isNew == 0);

	    }while(isNew != 0);
	
	    // Assign newId to students[i].id
	    students[i].id = newId;

	    // Generate and assign a new score for student[i].score
	    students[i].score = rand() % 101;
        }
    }
}

/***********************************************************************************************
 * Function: output(struct student* students)
 * Description: Prints the ids and scores of all the students
 * Parameters: struct student* students is an array NUM_STUDENTS
 * Pre-Conditions: n/a
 * Post-Conditions: Students are printed
 **********************************************************************************************/
void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/

    // Check if the array is empty
    if (students != NULL){
        printf("Printing students...\n");
        printf("ID Score\n");
        for(int i = 0; i < NUM_STUDENTS; i++){
	    printf("%2d %3d\n", students[i].id, students[i].score);
        }
    }
}
/*********************************************************************************************
 * Function: summary(struct student* students)
 * Description: Prints the minimum score, maximum score and average score for the students
 * Parameters: struct* student students is an array of NUM_STUDENTS
 * Pre-Conditions: n/a
 * Post-Conditions: Minimum score, maximum score and average score are printed
 *********************************************************************************************/
void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    
    // Check if students array is empty
    if(students != NULL){ 
        // Declare min, max total and average
        int minScore = 101; 
        int maxScore = -1; 
    	int totalScore = 0;
    	double averageScore; 
    
    	// Loop through each student
    	for(int i = 0; i < NUM_STUDENTS; i++){ 
    	    // Check if score is less than min
    	    if ( students[i].score < minScore ){ 
    	        // If yes, set min = students[i].score
    	    	minScore = students[i].score;
	    }
 
    	    // Check if score is greater than max
    	    if ( students[i].score > maxScore ){ 
                // If yes, set max = students[i].score
    	        maxScore = students[i].score;
    	    } 
    	    // Add students[i].score to total
    	    totalScore += students[i].score;
        }
        // Compute the average score
        averageScore = (double)totalScore / NUM_STUDENTS;
 
        // Display minimum score
        printf("Minimum Score: %d\n", minScore);

        // Display max score
        printf("Maximum Score: %d\n", maxScore);

        // Display average score
        printf("Average Score: %3.2f\n", averageScore);    
    }
}

/*********************************************************************************************
 * Function: deallocate(struct student* stud)
 * Description: Frees the memory allocated to students
 * Parameters: struct student* stud is an array of NUM_STUDENTS students
 * Pre-Conditions: stud has been allocated memory
 * Post-Conditions: memory allocated to stud ahs been freed
 *********************************************************************************************/
void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    if(stud != NULL){
	free(stud);
    }

}

/*********************************************************************************************
 * Function main()
 * Description: Demonstrates the functionality of each function by callign them
 * Parameters: n/a
 * Pre-Conditions: n/a
 * Post-Conditions: Program exits
 ********************************************************************************************/
int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();   

    /*call generate*/
    generate(stud);

    /*call output*/
    output(stud);

    /*call summary*/
    summary(stud);

    /*call deallocate*/
    deallocate(stud);

    return 0;
}
