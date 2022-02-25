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
void nodePrintPeople(node_t *pHead)
{
    person_t *personData;
    int pplCount = 1;
    while (pHead != NULL) {
        personData = (person_t*)(pHead->data);
        printf("      #%d. %s is %d years old\n", pplCount, personData->name, personData->age);
        pHead = pHead->next;
        pplCount++;
    }
    printf("\n");
}

/* Sample driver code */
int main(int argc, char *argv[])
{

    /* 
     * personList will contain person_t data structure
     */
    printf("Person List:\n");
    printf("============================================\n\n");
    node_t *personList = NULL;
    
    person_t person_1;
    person_1.age = 30;
    strcpy(person_1.name, "Pisang");

    person_t person_2;
    person_2.age = 62;
    strcpy(person_2.name, "Keripik");

    person_t person_3;
    person_3.age = 19;
    strcpy(person_3.name, "Cokelat");

    printf("0. Initial\n");
    printf("    >> There are %d people in the list\n", getNodeCount(personList));
    nodePrintPeople(personList);
    /* DATA: NULL */

    nodeAppend(&personList, &person_1, sizeof(person_t));
    printf("1. Append Test\n");
    printf("  > Insert at the end: %s [%d years old]\n", person_1.name, person_1.age);
    printf("    >> There are %d people in the list\n", getNodeCount(personList));
    nodePrintPeople(personList);
    /* DATA: person_1 -> NULL */

    nodePush(&personList, &person_2, sizeof(person_t));
    printf("2. Push Test\n");
    printf("  > Insert at the beginning: %s [%d years old]\n", person_2.name, person_2.age);
    printf("    >> There are %d people in the list\n", getNodeCount(personList));
    nodePrintPeople(personList);
    /* DATA: person_2 -> person_1 -> NULL */

    nodeAppend(&personList, &person_3, sizeof(person_t));
    printf("3. Append Test\n");
    printf("  > Insert at the end: %s [%d years old]\n", person_3.name, person_3.age);
    printf("    >> There are %d people in the list\n", getNodeCount(personList));
    nodePrintPeople(personList);
    /* DATA: person_2 -> person_1 -> person_3 -> NULL */
    
    nodePop(&personList);
    printf("4. Pop Test\n");
    printf("  > Remove from beginning\n");
    printf("    >> There are %d people in the list\n", getNodeCount(personList));
    nodePrintPeople(personList);
    /* DATA: person_1 -> person_3 -> NULL */
    
    nodePoop(&personList);
    printf("5. Poop Test\n");
    printf("  > Remove from the end\n");
    printf("  >> There are %d people in the list\n", getNodeCount(personList));
    nodePrintPeople(personList);
    /* DATA: person_1 -> NULL */

    printf("============================================\n\n\n");
    nodeDestroy(&personList);

    return 0;
}