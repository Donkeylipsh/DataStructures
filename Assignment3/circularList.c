/******************************************************************************************************************
 * CS261 - Assignment 3 - Part 2
 * Author: Colin Van Overschelde
 * Date: 2/4/2018
 * Soluction Description: circularList.c demonstrates the circular list implementation of the deque data structure
 ******************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	// Validate parameters
	assert(list != 0);

	// Allocate memory for sentinel
    list->sentinel = malloc(sizeof(struct Link));
    assert(list->sentinel != 0);

	// Assign sentinel to sentinel->next and sentinel->prev
	list->sentinel->next = list->sentinel->prev = list->sentinel;

	// Assign 0 to size
	list->size = 0;

}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this

	// Allocate memory for newLink
	struct Link *newLink = malloc(sizeof(struct Link));
	assert(newLink != 0);

	// Assign NULL to newLink->next and newLink->prev
	newLink->next = newLink->prev = NULL;

	// Assign value to newLink->value
    newLink->value = value;

	// Return newLink
	return newLink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
	// Validate parameters
	assert(list != 0);
	assert(link != 0);

	// Find link in list
    // Assign list->sentinel ->next to currentLink
    struct Link *currentLink = list->sentinel->next;

    // Loop through list until currentLink == list->sentinel || currentLink == link
    while((currentLink != list->sentinel ) && (currentLink != link)){
            // Increment currentLink
            currentLink = currentLink->next;
    }

	// Create newLink using createLink()
	struct Link *newLink = createLink(value);

	// Assign currentLink to newLink->prev
	newLink->prev = currentLink;

	// Assign currentLink->next to newLink->next
	newLink->next = currentLink->next;

	// Assign newLink to currentLink->next
	currentLink->next = newLink;

	// Assign newLink to newLink->next->prev
	newLink->next->prev = newLink;

	// Increment list->size
	list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	// FIXME: you must write this
	// Validate parameters
	assert(list != 0);
	assert(link != 0);

	// Find link in list
	// Assign list->sentinel->next to currentLink
	struct Link *currentLink = list->sentinel->next;

    // Assign 0 to found
    int found = 0;

    // Loop through list until currentLink equals list->sentinel or found equals 1
    while((currentLink != list->sentinel) && (found == 0)){
            // Check if currentLink equals link
            if(currentLink == link){
                // Assign currentLink->prev to currentLink->next->prev
                currentLink->next->prev = currentLink->prev;

                // Assign currentLink->next to currentLink->prev->next
                currentLink->prev->next = currentLink->next;

                // Free link
                free(link);

                // Decrease list->size
                list->size = 0;

                found = 1;
            }
            else{
                // Increment currentLink
                currentLink = currentLink->next;
            }
    }
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	// FIXME: you must write this
	// Validate parameters
	assert(list != 0);

	// Loop through list until isEmpty equals 1
	while(circularListIsEmpty(list) == 0){
        // Use removeLink to remove list->sentinel->next
        removeLink(list, list->sentinel->next);
	}

    // Free sentinel
    free(list->sentinel);

    // Free list
    free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	// Validate parameters
	assert(list != 0);

	// Use createLink() to allocate newLink
	struct Link *newLink = createLink(value);

	// Assign list->sentinel->next to newLink->next
	newLink->next = list->sentinel->next;

	// Assign list->sentinel to newLink->prev
	newLink->prev = list->sentinel;

	// Assign newLink to newLink->next->prev
	newLink->next->prev = newLink;

	// Assign newLink to list->sentinel->next
	list->sentinel->next = newLink;

	// Increment list->size
    list->size++;
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	// Validate parameters
	assert(list != 0);

	// Use createLink() to allocate newLink
	struct Link *newLink = createLink(value);

	// Assign list->sentinel->prev to newLink->prev
	newLink->prev = list->sentinel->prev;

	// Assign list->sentinel to newLink->next
	newLink->next = list->sentinel;

	// Assign newLink to newLink->prev->next
	newLink->prev->next = newLink;

	// Assign newLink to list->sentinel->prev
	list->sentinel->prev = newLink;

	//Increment list->size
	list->size++;
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this
	// Validate parameters
	assert(list != 0);

	// return list->sentinel->next->value
	return list->sentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this
	// Validate parameters
	assert(list != 0);

	// return list->sentinel->prev->value
	return list->sentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this
	// Validate parameters
	assert(list != 0);

	// Assign list->sentinel->next to removedLink
	struct Link *removedLink = list->sentinel->next;

	// Assign removedLink->next to list->sentinel->next
	list->sentinel->next = removedLink->next;

	// Assign list->sentinel to removedLink->next->prev
	removedLink->next->prev = list->sentinel;

	// Free removedLink
	free(removedLink);

	// Decrease size
	list->size--;
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
	// Validate parameters
	assert(list != 0);

	// Assign list->sentinel->prev to removedLink
	struct Link *removedLink = list->sentinel->prev;

	// Assign removedLink->prev to list->sentinel->prev
	list->sentinel->prev = removedLink->prev;

	// Assign list->sentinel to removedLink->prev->next
	removedLink->prev->next = list->sentinel;

	// Free removedLink
	free(removedLink);

	// Decrease size
	list->size--;
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	// FIXME: you must write this
	//Validate parameters
	assert(list != 0);

	// Check if list->sentinel->next equals list->sentinel
	if(list->sentinel->next == list->sentinel){
        // If yes, the list is empty, so return 1
        return 1;
	}
    // If not, the list contains a link, so return 0
	return 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	// FIXME: you must write this
	// Validate parameters
	assert(list != 0);

	// Assign list->sentinel->next to currentLink
	struct Link *currentLink = list->sentinel->next;

	// Loop through list until currentLink equals list->sentinel
	while(currentLink != list->sentinel){
        // Print currentLink->value
        printf("%lf\n", currentLink->value);

        // Increment currentLink
        currentLink = currentLink->next;
	}

}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this
	// Validate parameters
	assert(list != 0);

	// Assign list->sentinel->next to currentLink
	struct Link *currentLink = list->sentinel->next;

	// Assign currentLink->next to nextLink
	struct Link *nextLink = currentLink->next;

	// Loop through list until currentLink equals list->sentinel
	while(currentLink != list->sentinel){
        // Assign currentLink->prev to currentLink->next
        currentLink->next = currentLink->prev;

        // Assign nextLink to currentLink->prev
        currentLink->prev = nextLink;

        // Increment currentLink
        currentLink = nextLink;

        // Increment nextLink
        nextLink = nextLink->next;
	}

	// Reverse the sentinel
	currentLink = list->sentinel->next; 
	list->sentinel->next = list->sentinel->prev;
	list->sentinel->prev = currentLink; 
}
