/****************************************************************************
* Author: Colin Van Overschelde
* Class: CS 261 - Data Structures
* Description: arrayBagStack.c in a demonstration of the Stack data structure
*****************************************************************************/

/****************************************************************************
* Description: initArray is a function to initialize an arrayBagStack struct
* Parameters: b is a pointer to an arrayBagStack representing the stack to be initialized
* Pre-conditions: b has been dynamically allocated to memory
* Post-conditions: The value of b->count has been initialized to 0
*****************************************************************************/
void initArray(struct arrayBagStack* b){
    // Validate params
    assert(b != 0);
    
    // Initialize the count value of the arrayBagStack to 0
    b->count = 0;
}

/*****************************************************************************
* Description: pushArray is a function to push(add) an element on top of the stack
* Parameters: b is a pointer to an arrayBagStack representing the stack to add v to
*             v is the value to be added to the underlying stack
* Pre-conditions: b has been allocated to dynamic memory
* Post-conditions: v has been added as the first value in the stack b->data
*****************************************************************************/
void pushArray(struct arrayBagStack* b, TYPE v){
    // Validate params
    assert(b != 0);

    // Use the addArray function to add the element to the stack
    addArray(b, v);
}

/*****************************************************************************
* Description: topArray is a function to return the value at the top of the stack
* Parameters: b is a pointer to an arrayBagStack representing a stack of TYPE values
* Pre-conditions: b has been allocated to dynamic memory
* Post-conditions: The value of the first element in the stack contained in b is returned
*****************************************************************************/
TYPE topArray(struct arrayBagStack* b){
    // Validate params
    assert(b != 0);

    // Return the value at the top of the stack
    return b->data[b->count];
}

/*****************************************************************************
* Description: popArray is a function to remove the first element from the stack
* Parameters: b is a pointer to an arrayBagStack struct containing the target stack
* Pre-conditions: b has been allocated to dynamic memory
* Post-conditions: The first value has been removed from the stack contained in b
*****************************************************************************/
void popArray(struct arrayBagStack* b){
    // Validate params
    assert(b != 0);

    // Check if there is at least one element in the array
    if( b->count > 0){
        // Decrement the size of the underlying array, removing the last element from the active portion of the array
        b->count--;
    }
}

/*****************************************************************************
* Description: isEmptyArray is a function to test if the array is empty or not
* Parameters: b is a pointer to an arrayBagStack to be tested
* Pre-conditions: b has been allocated to dynamic memory
* Post-conditions: Returns 1 (true) if the array is empty, 0 (false) otherwise
*****************************************************************************/
int isEmptyArray(struct arrayBagStack* b){
    // Validate params
    assert(b != 0);

    // Check if there are 0 elements containing values in the stack
    if(b->count == 0){
        // If yes, return 1 (true)
        return 1;
    }
    else{
        // If not, return 0 (false)
        return 0;
    }
}

/*****************************************************************************
* Description: addArray is a function that adds a new value to the top of the stack
* Parameters: b is a pointer to the an arrayBagStack containing the stack to add the value to
*             v is the value to be added to the top of the stack
* Pre-conditions: b has been allocated to dynamic memory
*                 b->data array is not full
* Post-conditions: The value of v has been added to the top of the stack
*****************************************************************************/
void addArray(struct arrayBagStack* b, TYPE v){
    // Validate params
    assert(b != 0);

    // Check if the stack is full
    if( b->count < 100 ){
        // If not, add the value of v to the next element in the array
        b->data[count] = v;
        // Increment the count of elements in the activ eportion of the array
        b->count++;
    }
}

/*****************************************************************************
* Description: containsArray is a function that determines if a certain value is contained in the stack
* Parameters: b is a pointer to the arrayBagStack that is to be tested
*             v is the value to search for
* Pre-conditions: b has been allocated to dynamic memory
* Post-conditions: Returns 1 (true) if the input value was contained in the array
*                  Returns 0 (false) otherwise
*****************************************************************************/
int containsArray(struct arrayBagStack* b, TYPE v){
    // Validate params
    assert(b != 0);
    
    // Search each element in the stack for the input value
    int isFound = 0;
    int currentIndex = 0;
    // Loop through each element in the stack
    while( (!isFound) && (currentIndex < b->count) ){
        // Test if the value of the current element equals in teh input value
        if(b->data[currentIndex] == v){
            // If yes, set isFound to 1 (true)
            isFound = 1;
        }
        // If not, move to the next element and repeat loop
        currentIndex++;
    }

    // Check if the value was found in the stack
    if(isFound == 1){
        // If yes, return 1 (true)
        return 1;
    }
    else{
        // If not, return 0 (false)
        return 0;
    }
}

/*****************************************************************************
* Description: removeArray is a function that removes a specified input value from the stack, if it exists
* Parameters: b is a pointer to the arrayBagStack to have it's element removed
*             v is the value to remove from the stack
* Pre-conditions: b has been allocated to dynamic memory
* Post-conditions: If the value is found, it is removed from the stack
*****************************************************************************/
void removeArray(struct arrayBagStack* b, TYPE v){
    int isFound = 0;
    int currentIndex = 0;
    while( (!isFound) && (currentIndex < b->count) ){
        if(b->data[currentIndex] == v){
            isFound = 1;
        }
        currentIndex++;
    }

    // Check if the value was found in the stack
    if(isFound == 1){
        // If yes, remove the value from the stack
        // Decrement b->count to reflect 1 less element in the stack
        b->count--;
        // Move the value of each element after the one containing the value to be removed to the previous index
        for(currentIndex; currentIndex < b->count; currentIndex++){
            b->data[currentIndex] = b->data[currentIndex + 1];
        }
    }
}

/*****************************************************************************
* Description: sizeArray is a function that returns the number of elements in the stack
* Parameters: b is a pointer the arrayBagStack to hav eit's b->coutn value returned
* Pre-conditions: b has been allocated to dynamic memory
* Post-conditions: The value stored in b->count has been returned
*****************************************************************************/
int sizeArray(struct arrayBagStack* b){
    // Validate params
    assert(b != 0);
    
    // Return the value of b->count
    return b->count;
}
