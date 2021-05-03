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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "gen_llist.h"

#define NAME_LEN    32

struct person {
    char name[NAME_LEN];
    int age;
};

typedef struct person person_t;

/* 
 * Pass the reference of the pointer of a list.
 * This function is used to print list element as integer
 */
void nodePrintAsInteger(node_t *pHead)
{
    while (pHead != NULL) {
        printf("%d ", *(int *)(pHead->data));
        pHead = pHead->next;
    }
    printf("\n\n");
}

/* 
 * Pass the reference of the pointer of a list.
 * This function is used to print list element as integer
 */
void nodePrintPeople(node_t *pHead)
{
    person_t *personData;
    int pplCount = 1;
    while (pHead != NULL) {
        personData = (person_t*)(pHead->data);
        printf("%d. %s is %d years old\n", pplCount, personData->name, personData->age);
        pHead = pHead->next;
        pplCount++;
    }
    printf("\n");
}

/* Sample driver code */
int main(int argc, char *argv[])
{
    /* Section 1: Numeric List Example
     * numericList will contain both int & short data type 
     */
    
    node_t *numericList = NULL;
    
    /* Append int value to generic list */
    int intList[] = {1, 2, 3};

    printf("Numeric List:\n");
    printf("============================================\n");
    printf("-- Append\t: [ ");
    for (int i = 0; i < (sizeof(intList)/sizeof(int)); i++) {
        printf("%d ", intList[i]);
        nodeAppend(&numericList, &intList[i], sizeof(int));
    }
    printf("]\n");
    nodePrintAsInteger(numericList);
    /* 
     * numericList
     * 1
     * 1 2
     * 1 2 3
     */

    /* Append short value to generic list */
    short shortList[] = {4, 5, 6};

    printf("-- Push\t\t: [ ");
    for (int i = 0; i < (sizeof(shortList)/sizeof(short)); i++) {
        printf("%d ", shortList[i]);
        nodePush(&numericList, &shortList[i], sizeof(short));
    }
    printf("]\n");
    nodePrintAsInteger(numericList);
    /* 
     * numericList
     * 4 1 2 3
     * 5 4 1 2 3
     * 6 5 4 1 2 3
     */

    printf("-- Pop\n");
    nodePop(&numericList);
    nodePrintAsInteger(numericList);
    /* 
     * numericList
     * 5 4 1 2 3
     */

    printf("-- Poop\n");
    nodePoop(&numericList);
    nodePrintAsInteger(numericList);
    /* 
     * numericList
     * 5 4 1 2
     */

    printf("============================================\n\n\n");
    nodeDestroy(&numericList);


    /* Section 2: Custom List Example
     * personList will contain person_t data structure
     */
    printf("Person List:\n");
    printf("============================================\n");
    node_t *personList = NULL;
    
    person_t person_1;
    person_1.age = 30;
    strcpy(person_1.name, "pisang");

    person_t person_2;
    person_2.age = 1;
    strcpy(person_2.name, "keripik");

    person_t person_3;
    person_3.age = 19;
    strcpy(person_3.name, "cokelat");

    /* DATA: NULL */
    nodeAppend(&personList, &person_1, sizeof(person_t));
    printf("-- Append\t: %s [%d years old]\n", person_1.name, person_1.age);
    nodePrintPeople(personList);
    /* DATA: person_1 -> NULL */

    nodePush(&personList, &person_2, sizeof(person_t));
    printf("-- Push\t\t: %s [%d years old]\n", person_2.name, person_2.age);
    nodePrintPeople(personList);
    /* DATA: person_2 -> person_1 -> NULL */

    nodeAppend(&personList, &person_3, sizeof(person_t));
    printf("-- Append\t: %s [%d years old]\n", person_3.name, person_3.age);
    nodePrintPeople(personList);
    /* DATA: person_2 -> person_1 -> person_3 -> NULL */
    
    nodePop(&personList);
    printf("-- Pop\n");
    nodePrintPeople(personList);
    /* DATA: person_1 -> person_3 -> NULL */
    
    nodePoop(&personList);
    printf("-- Poop\n");
    nodePrintPeople(personList);
    /* DATA: person_1 -> NULL */

    printf("============================================\n\n\n");
    nodeDestroy(&personList);

    return 0;
}