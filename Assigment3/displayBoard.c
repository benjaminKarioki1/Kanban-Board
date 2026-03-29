#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "structure.h"
#include "board.h"

void displayBoard(Listptr Lptr)
{
	//if the List is empty
	if (Lptr == NULL) 
	{
		printf("EMPTY!!!\n");
	}
	else 
	{
		//copy the pointer
		Listptr currentList = Lptr;
		//print out all List
		while (currentList != NULL)
		{
			printf("%s:\n", currentList->name);
			//access the elements
			Elementptr currentElement = currentList->head;
			//print out eleents
			while (currentElement != NULL)
			{
				printf("    %s\n", currentElement->name);
				//move to next element
				currentElement = currentElement->nextE;
			}
	        //move to next List
			currentList = currentList->nextL;
		}
	}
	return;
}