/*
 * DESCRIPTION :
 *      Generic linked-list implementation in C
 *
 * ORIGINAL AUTHOR : 
 *      ASAF ZEBULON (azeb.cc07@gmail.com)
 *
 * START DATE :
 *      3 May 2021
 */

#include <string.h>
#include <stdlib.h>

#include "gen_llist.h"

/*
 * Pass the reference to the head pointer of a list.
 * This function is used to add the node at the beginning of the list.
 */
void nodePush(node_t **pHead, void *inputElemData, int inputElemSize)
{
    /* Allocate memory for new node */
    node_t *newNode = malloc(sizeof(node_t));

    /* Allocate memory for new data and store the pointer */
    void *newData = malloc(inputElemSize);
    memcpy(newData, inputElemData, inputElemSize);
    newNode->data = newData;
    newNode->next = *pHead;

    /* New node is the new head */
    *pHead = newNode;
}

/* 
 * Pass the reference to the head pointer of a list.
 * This function is used to add the node at the end of the list
 */
void nodeAppend(node_t **pHead, void *inputElemData, int inputElemSize)
{
    /* Allocate memory for new node */
    node_t *newNode = malloc(sizeof(node_t));

    /* Allocate memory for new data */
    void *newData = malloc(inputElemSize);
    memcpy(newData, inputElemData, inputElemSize);

    /* Store new data to node pointer */
    newNode->data = newData;
    newNode->next = NULL;

    /* If head is empty */
    if (*pHead == NULL) {
        *pHead = newNode;
        return;
    }

    /* Get last node information */
    node_t *lastNode = *pHead;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    /* Point last node's next address to new node */
    lastNode->next = newNode;
}

/* 
 * Pass the reference of the head pointer of a list.
 * This function is used to remove first node on the list.
 */
void nodePop(node_t **pHead)
{
    node_t *firstNode = *pHead;

    /* Change head pointer to secondNode */
    *pHead = (*pHead)->next;

    /* Remove allocated memory of firstNode */
    free(firstNode->data);
    free(firstNode);
}

/*
 * Pass the reference of the head pointer of a list.
 * This function is used to remove last node on the list.
 */
void nodePoop(node_t **pHead)
{
    node_t *tempNode = *pHead;

    /* Find second-to-last node */
    while (tempNode->next->next != NULL) {
        tempNode = tempNode->next;
    }

    /* Find node to be deleted */
    node_t *lastNode = tempNode->next;

    /* Second-to-last node should point to NULL instead of lastNode */
    tempNode->next = NULL;

    /* Free allocated memory of lastNode */
    free(lastNode->data);
    free(lastNode);
}

/* 
 * Pass the reference of the head pointer of a list.
 * This function is used to free all allocated memory [node & data]
 */
void nodeDestroy(node_t **pHead)
{
    node_t *currentNode = *pHead;
    node_t *nextNode;

    while (currentNode != NULL) {
        nextNode = currentNode->next;

        /* Free data first */
        free(currentNode->data);
        free(currentNode);

        currentNode = nextNode;
    }

    *pHead = NULL;
}

/*
 * Pass the head pointer of the list
 * This function is used to count the elements in the list
 */
int getNodeCount(node_t *pHead)
{
    int count = 0;
    node_t *currentNode = pHead;

    while (currentNode != NULL) {
        count++;
        currentNode = currentNode->next;
    }

    return count;
}