/**************************************************************************************************
 * CS261 - Assignment 3 - Part 1
 * Author: Colin Van Overschelde
 * Date: 2/4/2018
 * Solution Description: linkedList.c demonstrates the linked list implementation of the deque and bag data structures
***************************************************************************************************/
#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list) {
	// Validate parameters
	assert(list != 0);

	// Assign 0 to list->size
	list->size = 0;


	// Allocate memory for list->frontSentinel
	list->frontSentinel = malloc(sizeof(struct Link));
	assert(list->frontSentinel != 0);

	// Allocate memory for list->backSentinel
	list->backSentinel = malloc(sizeof(struct Link));
	assert(list->backSentinel !=0);

	// Assign list->frontSentinel->prev and next values
	list->frontSentinel->prev = 0;
	list->frontSentinel->next = list->backSentinel;

	// Assign list->backSentinel->prev and next values
	list->backSentinel->next = 0;
	list->backSentinel->prev = front;

}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
	// Validate parameters
	assert(list != 0);
	assert(link != 0);
	
	// Loop through list to find link
	struct Link *currentLink = list->frontSentinel;

	while((currentLink->next != list->backSentinel) && (currentLink->next != link)){
        	// Increment currentLink
        	currentLink = currentLink->next;
        }
        
	// Allocate memory for new link
	struct Link *someLink = malloc(sizeof(struct Link));
	assert(someLink != 0); 

	// Set new link's prev, next and value
        someLink->next = currentLink->next;
 	someLink->prev = currentLink;
	someLink->value = value; 

        // Set currentLInk->next to newLink
        currentLink->next = someLink;
	 
        // Set link->prev to newLink
	someLink->next->prev = someLink;        

	// Increment list->size
	list->size++;  
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
	// FIXME: you must write this

	// Validate parameters
	assert(list != 0);
	assert(link != 0); 
	
	// Loop through list to find link
	struct Link *currentLink = list->frontSentinel;

	while(currentLink->next != list->backSentinel){ 
        	// Check if currentLink->next = link
        	if(currentLink->next == link){ 
            		// Set currentLink->next to link->next
            		currentLink->next = link->next;

            		// Set link->next->prev to currentLink
            		link->next->prev = currentLink;
 
            		// Deallocate link
            		free(link);

			// Decrease list->size
			list->size--;
            	}
	
		// Increment currentLink
		currentLink = currentLink->next;
        } 
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this

	// Validate params
	assert(list != 0);
	
	// Allocate new link
	struct Link *newLink = malloc(sizeof(struct Link));
	assert(newLink != 0);

	// Assign value to newLink->value
	newLink->value = value;

	// Assign list->frontSentinel->next to newLink->next
	newLink->next = list->frontSentinel->next;
 
	// Assign newLink to newLink->next->prev
	newLink->next->prev = newLink;
 
	// Assign list->frontSentinel to newLink->prev
	newLink->prev = list->frontSentinel;
 
	// Assign newLink to list->frontSentinel->next
	list->frontSentinel->next = newLink; 

	// Increment list->size
	list->size++;
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this

	// Validate params
	assert(list != 0);

	// Allocate new link
	struct Link *newLink = malloc(sizeof(struct Link));
	assert(newLink != 0); 

	// Assign value to newLink->value
	newLink->value = value;
 
	// Assign list->backSentinel->prev to newLink->prev
	newLink->prev = list->backSentinel->prev;
 
	// Assign newLink to newLink->prev->next
	newLink->prev->next = newLink;
 
	// Assign list->backSentinel to newLink->next
	newLink->next = list->backSentinel;

	// Assign newLink to list->backSentinel->prev
	list->backSentinel->prev = newLink;

	// Increment list->size
	list->size++;
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList* list)
{
    // Validate parameters
    assert(list != 0);

	// Return the value of the link at the front of the deque
	return list->frontSentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList* list)
{
    // Validate parameters
    assert(list != 0);

	// Return the value of the link at the back of the deque
	return list->backSentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList* list)
{
	// FIXME: you must write this
	// Validate parameters
	assert(list != 0);

	// Assign list->frontSentinel->next to removedLink
	struct Link *removedLink = list->frontSentinel->next;

	// Assign removedLink->next to list->frontSentinel->next
	list->frontSentinel->next = removedLink->next;

	// Assign list->frontSentinel to removedLink->next->prev
	removedLink->next->prev = list->frontSentinel;

	// Deallocate removedLink
	free(removedLink);

	// Decrease list->size
	list->size--; 
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList* list)
{
	// FIXME: you must write this
	// Validate parameters
	assert(list != 0);

	// Assign list->backSentinel->prev to removedLink
	struct Link *removedLink = list->backSentinel->prev;

	// Assign removedLink->prev to list->backSentinel->prev
	list->backSentinel->prev = removedLink->prev;

	// Assign list->backSentinel to removedLink->prev->next
	removedLink->prev->next = list->backSentinel;

	// Deallocate removedLink
	free(removedLink);

	// Decrease list->size
	list->size--;
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{
	// FIXME: you must write this
	// Validate parameters
	assert(list != 0);

	// Check if list->frontSentinel->next == list->backSentinel
	if(list->frontSentinel->next == list->backSentinel){ 
        	// If yes, then the deque is empty, so return 1
        	return 1; 
        } 
	else{
        	// Else, the list is not empty, so return 0
        	return 0;
	}
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{
	// FIXME: you must write this
	// Validate parameters
	assert(list != 0);

	// Set currentLink to list->frontSentinel->next
	struct Link *currentLink = list->frontSentinel->next;

	// Loop through list while currentLink != list->frontSentinel
	while(currentLink != list->backSentinel){
        	// Print currentLink->value
        	printf("%i\n", currentLink->value);

		// Increment currentLink
		currentLink = currentLink->next;
	}
}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	// Validate parameters
	assert(list != 0);

	// Use linkedListAddFront() to add the value to the bag
	linkedListAddFront(list, value); 
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	// Validate parameters
	assert(list != 0); 

	// Assign list->frontSentinel->next to currentLink
	struct Link *currentLink = list->frontSentinel->next;

	// Loop through list while currentLink != list->backSentinel
	while(currentLink != list->backSentinel){ 
        	// Check if currentLink->value == value
        	if(currentLink->value == value){
    			// If yes, the value is in the bag, so return 1
    			return 1;
		}
	
		// Increment currentLink
		currentLink = currentLink->next;
	}

    	// When the loop completes, the value wasn't found, so return 0
	return 0;
}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	// Validate parameters
	assert(list != 0);

	// Assign list->frontSentinel->next to currentLink
	struct Link *currentLink = list->frontSentinel->next;

	int removed = 0;

	// Loop through list while currentLink != list->backSentinel
	while((currentLink != list->backSentinel) && (removed == 0)){ 
        	// Check if currentLink->value == value
        	if(currentLink->value == value){
            		// If yes, use removeLink() to remove currentLink
            		removeLink(list, currentLink);
			removed = 1;
		}
		// Increment currentLink
		currentLink = currentLink->next; 
	}
}

