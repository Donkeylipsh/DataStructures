/*
 * This is the file in which you'll write the functions required to implement
 * a stack using two queues.  Make sure to add your name and @oregonstate.edu
 * email address below:
 *
 * Name: Colin Van Overschelde
 * Email: vanoverc@oregonstate.edu
 */

/**********************************************************************************************
 * CS261 - Assignment 3 - Part 3
 * Author: Colin Van Overschelde
 * Date: 2/4/2018
 * Description: stack_from_queue.c demonstrates using two instances of Queue data structures to implement 
 * 		a stack data structure
 ***********************************************************************************************/

 #ifndef TYPE
    #define TYPE int
 #endif // TYPE

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/* All by yourself */

/*********************************************************************************************
 * Description: struct link represents each link in the listQueue data structure
 * value: is the value stored in the link
 * next: is a pointer to the next link in the listQueue
 **********************************************************************************************/
struct link {
    TYPE value;
    struct link * next;
};

/*********************************************************************************************
 * Description: struct listQueue represents a Queue data structure
 * firstLink: is a pointer to a sentinel link at the front of the Queue
 * lastLink: is a pointer to the last link in the listQueue
 **********************************************************************************************/
struct listQueue {
    struct link *firstLink;
    struct link *lastLink;
};

/*********************************************************************************************
 * Description: struct stackFromQueue represents a Stack data structure using a queue implementation
 * someQueue: is a pointer to a the listQueue holding the Stack
 * spareQueue: is a pointer  to a listQueue used to help implement the Stack
 **********************************************************************************************/
struct stackFromQueue {
        struct listQueue *someQueue;
};

void listQueueInit (struct listQueue *);
void listQueueAddBack (struct listQueue *, TYPE );
TYPE listQueueFront (struct listQueue *);
void listQueueRemoveFront (struct listQueue *);
int listQueueIsEmpty (struct listQueue *);

void stackFromQueueInit (struct stackFromQueue *);
void stackFromQueueFree (struct stackFromQueue *);
void stackFromQueuePush (struct stackFromQueue *, TYPE );
TYPE stackFromQueueTop (struct stackFromQueue *);
void stackFromQueuePop (struct stackFromQueue *);
int stackFromQueueIsEmpty (struct stackFromQueue *);
void stackFromQueuePrint(struct stackFromQueue *);


/****************************************************************************************************
 * Function: listQueueInit(struct listQueue *q)
 * Description: Allocates memory for the sentinel link and initializes it's values
 * Parameters: struct listQueue q holds the listQueue to be initialized
 * Pre-condition: q is empty
 * Post-condition: q contains a newly allocated sentinel link
 ****************************************************************************************************/
void listQueueInit (struct listQueue *q) {
    // Validate parameters
    assert(q != 0);
    //assert(listQueueIsEmpty(q) != 0);

    struct link *lnk = (struct link *) malloc(sizeof(struct link));
    assert(lnk != 0); /* lnk is the sentinel */

    lnk->next = 0;
    q->firstLink = q->lastLink = lnk;
}

/****************************************************************************************************
 * Function: listQueueAddBack(struct listQueue *q, TYPE e)
 * Description: Adds a new link with value e to the back of the queue
 * listQueue q: Struct containing the queue to add the link
 * TYPE e: the value to be assigned to the new link
 * Pre-condition: n/a
 * Post-condition: The new link is added to the back of the queue
 ****************************************************************************************************/
void listQueueAddBack (struct listQueue *q, TYPE e) {
    // Validate parameters
    assert(q != 0);

    // Allocate memory for newLink
    struct link *newLink = (struct link *) malloc(sizeof(struct link));
    assert(newLink != 0);

    // Assign e to newLink->value
    newLink->value = e;

    // Assign 0 to newLink->next
    newLink->next = 0;

    // Assign newLink to q->lastLink->next
    q->lastLink->next = newLink;

    // Assign newLink to q->lastLink
    q->lastLink = newLink;
}

/****************************************************************************************************
 * Function: listQueueFront(struct listQueue *q)
 * Description: Returns the value stored in the first element of listQueue q
 * Pre-condition: n/a
 * Post-condition: Value of the first element is returned
 ****************************************************************************************************/
TYPE listQueueFront (struct listQueue *q) {
    // Validate Parameters
    assert(q != 0);
    assert(listQueueIsEmpty(q) != 1);

    // Return the value of the first link
    return q->firstLink->next->value;
}

/****************************************************************************************************
 * Function: listQueueRemoveFront(struct listQueue *q)
 * Description: Removes the first element of the listQueue
 * Pre-condition: listQueue is not empty
 * Post-condition: The first element is removed
 ****************************************************************************************************/
void listQueueRemoveFront (struct listQueue *q) {
    // Validate parameters
    assert(q != 0);
    assert(listQueueIsEmpty(q) != 1);

    // Assign q->front->next to removedLink
    struct link *removedLink = q->firstLink->next;

    // Assign removedLink->next to q->front->next
    q->firstLink->next = removedLink->next;

    // Free removedLink
    free(removedLink);
}

/****************************************************************************************************
 * Function: listQueueIsEmpty(struct listQueue *q)
 * Description: Tests q to see if it is empty, if it is, returns 1, return 0 otherwise
 * Parameters: struct listQueue q is the listQueue to be evaluated
 * Pre-condition: n/a
 * Post-condition: Returns 1 if q is empty, 0 otherwise
 ****************************************************************************************************/
int listQueueIsEmpty (struct listQueue *q) {
    // Validate parameters
    assert(q != 0);

    // Check if q->firstLink->next == 0
    if(q->firstLink->next == 0){
        // The list is empty, so return 1
        return 1;
    }
    else{
        // The list contains at least 1 link
        return 0;
    }
}

/***************************************************************************************************
 *                                      Stack implementation
 ***************************************************************************************************/

/****************************************************************************************************
 * Function: linkedListStackInit (struct linkedListStack * s)
 * Description: Allocates memory and initializes the underlying queue
 * Pre-condition: n/a
 * Post-condition: Stack is initialized
 ****************************************************************************************************/
void stackFromQueueInit (struct stackFromQueue * s) {
    // Validate parameters
    assert(s != 0);

    // Allocate memory for someQueue
    s->someQueue = (struct listQueue *) malloc(sizeof(struct listQueue));

    // Initialize s->someQueue using listQueueInit(s->someQueue)
    listQueueInit(s->someQueue);
}

/****************************************************************************************************
 * Function: linkedListStackFree (struct linkedListStack * s)
 * Description: Deallocates all elements in the underlying Queue and then deallocates the underlying queue
 * Pre-condition: stack parameter has been initialized
 * Post-condition:  All elements and the underlying queue are deallocated
 ****************************************************************************************************/
void stackFromQueueFree (struct stackFromQueue *s){
    // Validate Parameters
    assert(s != 0);
    assert(s->someQueue != 0);

    // Loop through the stackFromQueue, popping each element until it is empty
     while (! stackFromQueueIsEmpty(s)) {
        stackFromQueuePop(s);
    }

    // Deallocate the underlying queue
    free(s->someQueue);
}

/****************************************************************************************************
 * Function: linkedListStackPush (struct stackFromQueue * s)
 * Description: Pushes a new element onto the stack using 2 listQueue structures
 * Pre-condition: n/a
 * Post-condition: The new element is the first element in the stack
 ****************************************************************************************************/
void stackFromQueuePush (struct stackFromQueue *s, TYPE d) {
    // Validate Parameters
    assert(s != 0);

    // Allocate tempQueue
    struct listQueue *tempQueue = (struct listQueue *) malloc(sizeof(struct listQueue));

    // Initialize tempQueue
    listQueueInit(tempQueue);

    // Push newLink to tempQueue
    listQueueAddBack(tempQueue, d);

    // Loop through someQueue until someQueue is empty
    while(!stackFromQueueIsEmpty(s)){
        // Push oldQueue->front->next->value to tempQueue
        listQueueAddBack(tempQueue, s->someQueue->firstLink->next->value);

        // Use listQueueRemoveFront to remove the front value
        listQueueRemoveFront(s->someQueue);
    }

    // Free s->someQueue
    free(s->someQueue);

    // Point s->someQueue to tempQueue
    s->someQueue = tempQueue;

}

/****************************************************************************************************
 * Function: stackFromQueueTop (struct stackFromQueue * s)
 * Description: Returns the value stored at the top of the stack
 * Pre-condition: n/a
 * Post-condition: Value stored at the top of the stack is returned
 ****************************************************************************************************/
TYPE stackFromQueueTop (struct stackFromQueue *s) {
    /* Fix me */
    // Validate parameters
    assert(s != 0);

    return listQueueFront(s->someQueue);
}

/****************************************************************************************************
 * Function: linkedListStackPop (struct stackFromQueue * s)
 * Description: Removes the top element from the stack
 * Pre-condition: n/a
 * Post-condition: Top element of stack has been removed
 ****************************************************************************************************/
void stackFromQueuePop (struct stackFromQueue *s) {
    /* Fix me */
    // Validate parameters
    assert(s != 0);

    // Use listQueueRemoveFront() to remove the element at the top of the stack
    listQueueRemoveFront(s->someQueue);
}

/****************************************************************************************************
 * Function: linkedListStackIsEmpty (struct lstackFromQueue * s)
 * Description: Returns 1 if the stack is empty, 0 otherwise
 * Pre-condition: n/a
 * Post-condition: Returns 1 if the stack is empty, 0 otherwise
 ****************************************************************************************************/
int stackFromQueueIsEmpty (struct stackFromQueue *s) {
    /* Fix me */
    // Validate parameters
    assert(s != 0);

    // Use listQueueIsEmpty() to determine if the stack is empty
    return listQueueIsEmpty(s->someQueue);
}


/***************************************************************************************************
 * Function: stackFromQueuePrint (struct stackFromQueue * s)
 * Description: Print all the elements in teh stack from the top to the bottom
 * Pre-condition: n/a
 * Post-condition: All elements of the stack have been printed
 ****************************************************************************************************/
void stackFromQueuePrint(struct stackFromQueue *s){
    printf("Printing stack...\n");
    struct link *currentLink = s->someQueue->firstLink->next;
    while(currentLink != 0){
            printf("* %d\n", currentLink->value);
            currentLink = currentLink->next;
    }

}

/****************************************************************************************************
 * Function: main()
 * Description: Demonstrates all functions of the stackFromQueue data structure
 * Pre-condition: n/a
 * Post-condition: All demonstrations complete without error
 ****************************************************************************************************/
 int main()
 {
     printf("****************************************************\n");
     printf("* Welcome to stack_from_queue\n");
     printf("* Created by: Colin Van Overschelde\n");
     printf("****************************************************\n");

     struct stackFromQueue *s1 = malloc(sizeof(struct stackFromQueue));
     stackFromQueueInit(s1);

     printf("Testing if stack is empty, should return 1\n");
     printf("* Result = %d\n", stackFromQueueIsEmpty(s1));


     printf("Pushing 10 to stack...\n");
     stackFromQueuePush(s1, 10);
     printf("* New value at the top of the stack: %d\n", stackFromQueueTop(s1));
     printf("Pushing 20 to stack...\n");
     stackFromQueuePush(s1, 20);
     printf("* New value at the top of the stack: %d\n", stackFromQueueTop(s1));
     stackFromQueuePrint(s1);
     printf("Pushing 30 to stack...\n");
     stackFromQueuePush(s1, 30);
     printf("* New value at the top of the stack: %d\n", stackFromQueueTop(s1));

     stackFromQueuePrint(s1);

     printf("Popping top element of stack...\n");
     stackFromQueuePop(s1);
     printf("* New value at the top of the stack: %d\n", stackFromQueueTop(s1));

     stackFromQueuePrint(s1);

     printf("Popping top element of stack...\n");
     stackFromQueuePop(s1);
     printf("* New value at the top of the stack: %d\n", stackFromQueueTop(s1));

     stackFromQueuePrint(s1);

     printf("Popping top element of stack...\n");
     stackFromQueuePop(s1);

     stackFromQueuePrint(s1);

     printf("Testing if stack is empty, should return 1\n");
     printf("* Result = %d\n", stackFromQueueIsEmpty(s1));

     printf("Pushing 100 to stack...\n");
     stackFromQueuePush(s1, 100);
     printf("* New value at the top of the stack: %d\n", stackFromQueueTop(s1));

     printf("Testing if stack is empty, should return 0\n");
     printf("* Result = %d\n", stackFromQueueIsEmpty(s1));

     stackFromQueueFree(s1);

     free(s1);
 }
