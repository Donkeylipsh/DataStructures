/* CS261- Assignment 1 - Q.5*/
/* Name: Colin Van Overschelde
 * Date: 1/19/2018
 * Solution description: Demonstrates reading a word from keyboard input and converting it to
 * 			Sticky caps
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

/*****************************************************************************************
 * Function: sticky(char* word)
 * Description: Converts word to Sticky case, which is alternating upper/lower case starting
 * 		with the first character upper case
 * Parameters: char* word is a pointer to a char array (string)
 * Pre-Conditions: n/a
 * Post-Conditions: word is in Sticky caps
 ****************************************************************************************/	
void sticky(char* word){
    /*Convert to sticky caps*/
    // Declare a loop control variable
    int i = 0;

    // Loop through each character until '\0' is encountered
    while(word[i] != '\0'){
	// Check if the index of the current character is odd or even
	if(i % 2 == 0){
	    // If even, check if the character is lowercase
	    if(islower(word[i]) != 0){
		// If yes, set it to uppercase
		word[i] = toUpperCase(word[i]);
	    }
	}
	else{
	    // If odd, check if the character is lowercase
	    if(islower(word[i]) == 0){
		// If not, set it to lowercase
		word[i] = toLowerCase(word[i]);
	    }
	}
	i++;
    }
}

/*****************************************************************************************
 * Function: main()
 * Description: Reads a word from keyboard input and converts it to Sticky caps 
 * Parameters: n/a
 * Pre-Conditions: n/a
 * Post-Conditions: Program exits
 *****************************************************************************************/
int main(){
    /*Read word from the keyboard using scanf*/
    char *someString = malloc(sizeof(char) * 100);
    printf("Enter a word: ");
    scanf("%s", someString);

    /*Call sticky*/
    sticky(someString);

    /*Print the new word*/
    printf("New Word: %s\n", someString);

    // Release allocated memory
    free(someString);    

    return 0;
}
