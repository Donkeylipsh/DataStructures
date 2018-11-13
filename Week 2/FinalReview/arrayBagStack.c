/****************************************************************************
* Author: Colin Van Overschelde
* Class: CS 261 - Data Structures
* Description: arrayBagStack.c in a demonstration of the Stack data structure
*****************************************************************************/

/****************************************************************************
* Description: initArray is a function to initialize an arrayBagStack struct
* Parameters: b is a pointer to an arrayBagStack representing the stack to be initialized
* Pre-conditions: b has been dynamically allocated to memory
*                 b->data has not been previously allocated
* Post-conditions: 
*****************************************************************************/
void initArray(struct arrayBagStack* b){
    // Validate params
    assert(b != 0);
    assert(b->data == 0);

    // Allocate memory for the underlying array of the arrayBagStack data structure
    b->data = malloc(sizeof(TYPE) * 100);
    // Initialize the count value of the arrayBagStack to 0
    b->count = 0;
}

/*****************************************************************************
* Description: pushArray is a function to push(add) an element on top of the stack
* Parameters: b is a pointer to an arrayBagStack representing the stack to add v to
*             v is the value to be added to the underlying stack
* Pre-conditions: b has been allocated to dynamic memory
*                 b->data hase been allocated to dynamic memory
* Post-conditions: v has been added as the first value in the stack b->data
*****************************************************************************/
void pushArray(struct arrayBagStack* b, TYPE v){
    // Validate params
    assert(b != 0);
    assert(b->data != 0);

    // Use the addArray function to add the element to the stack
    addArray(b, v);
}

/*****************************************************************************
* Description: topArray is a function to return the value at the top of the stack
* Parameters: b is a pointer to an arrayBagStack representing a stack of TYPE values
* Pre-conditions: b has been allocated to dynamic memory
*                 b->data has been allocated to dynamic memory
* Post-conditions: The value of the first element in the stack contained in b is returned
*****************************************************************************/
TYPE topArray(struct arrayBagStack* b){
    // Validate params
    assert(b != 0);
    assert(b->data != 0);

    // Return the value of the first element in the array
    return b->data[0];
}

/*****************************************************************************
* Description: popArray is a function to remove the first element from the stack
* Parameters: b is a pointer to an arrayBagStack struct containing the target stack
* Pre-conditions: b has been allocated to dynamic memory
*                 b->data has been allocated to dynamic memory
* Post-conditions: The first value has been removed from the stack contained in b
*****************************************************************************/
void popArray(struct arrayBagStack* b){
    // Validate params
    assert(b != 0);
    assert(b->data != 0);

    // Check if there is at least one element in the array
    if( b->count > 0){
        // Decrement the size of the underlying array
        b->count--;
        // Move the value of each element up one element
        for(int i = 0; i < b->count; i++){
            // Copy the value of the next element to the current element
            b->data[i] = b->data[i + 1];
        }
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
*                 b->data has been allocated to dynamic memory
* Post-conditions: The value of v has been added to the top of the stack
*****************************************************************************/
void addArray(struct arrayBagStack* b, TYPE v){
    // Validate params
    assert(b != 0);
    assert(b->data != 0);

    // Check if
    if( b->count < 100 ){
        b->data[count] = v;
    }
}

/*****************************************************************************
* Description: 
* Parameters:
* Pre-conditions: 
* Post-conditions:
*****************************************************************************/
int containsArray(struct arrayBagStack* b, int v){

    int isFound = 0;
    int currentIndex = 0;
    while( (!isFound) && (currentIndex < b->count) ){
        if(b->data[currentIndex] == v){
            isFound = 1;
        }
        currentIndex++;
    }

    if(isFound == 1){
        return 1;
    }
    else{
        return 0;
    }
}

/*****************************************************************************
* Description:
* Parameters:
* Pre-conditions: 
* Post-conditions:
*****************************************************************************/
void removeArray(struct arrayBagStack* b, int v){
    int isFound = 0;
    int currentIndex = 0;
    while( (!isFound) && (currentIndex < b->count) ){
        if(b->data[currentIndex] == v){
            isFound = 1;
        }
        currentIndex++;
    }

    if(isFound == 1){
        b->count--;
        for(currentIndex; currentIndex < b->count; currentIndex++){
            b->data[currentIndex] = b->data[currentIndex + 1];
        }
    }
}

/*****************************************************************************
* Description: 
* Parameters:
* Pre-conditions: 
* Post-conditions:
*****************************************************************************/
int sizeArray(struct arrayBagStack* b){
    return b->count;
}

/*****************************************************************************
* Description: 
* Parameters:
* Pre-conditions: 
* Post-conditions:
*****************************************************************************/
void initDynArr(struct DynArr *v, int capacity){
    v->data = malloc(sizeof(TYPE) * capacity);
    v->size = 0;
    v->capacity = capacity;
}

/*****************************************************************************
* Description: 
* Parameters:
* Pre-conditions: 
* Post-conditions:
*****************************************************************************/
void _setCapacityDynArr(struct DynArr *v, int newCap){
    struct DynArr *newArray;

    initDynArr(&newArray, newCap);

    for(int i = 0; i < v->size; i++){
        newArray->data[i] = v->data[i];
    }

    freeDynArray(v);

    v = newArray;
}
