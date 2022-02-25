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
 
#ifndef GEN_LLIST_H
#define GEN_LLIST_H

/* Generic Node structure */
struct node {
    void *data;
    struct node *next;
};

typedef struct node node_t;

/*
 * Pass the reference to the head pointer of a list.
 * This function is used to add the node at the beginning of the list.
 */
void nodePush(node_t **pHead, void *inputElemData, int inputElemSize);

/* 
 * Pass the reference to the head pointer of a list.
 * This function is used to add the node at the end of the list
 */
void nodeAppend(node_t **pHead, void *inputElemData, int inputElemSize);

/* 
 * Pass the reference of the head pointer of a list.
 * This function is used to remove first node on the list.
 */
void nodePop(node_t **pHead);

/*
 * Pass the reference of the head pointer of a list.
 * This function is used to remove last node on the list.
 */
void nodePoop(node_t **pHead);

/* 
 * Pass the reference of the head pointer of a list.
 * This function is used to free all allocated memory [node & data]
 */
void nodeDestroy(node_t **pHead);

/*
 * Pass the head pointer of the list
 * This function is used to count the elements in the list
 */
int getNodeCount(node_t *pHead);

#endif /* GEN_LLIST_H */