#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "structure.h"
#include "board.h"
#include <stdlib.h>

//release the sub-linked list
void freeElements(Elementptr Eptr) 
{
    Elementptr tmp;
    while (Eptr != NULL) 
    {
        tmp = Eptr;
        Eptr = Eptr->nextE;
        free(tmp);
    }
}

//release the linked list
void freeLists(Listptr Lptr) 
{
    Listptr tmp;
    while (Lptr != NULL) 
    {
        tmp = Lptr;
        Lptr = Lptr->nextL;
        freeElements(tmp->head);
        free(tmp);
    }
}