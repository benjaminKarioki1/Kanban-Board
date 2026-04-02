#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure.h"
#include "board.h"

int loadFile(Listptr *Lptr) 
{
	//vairables
	FILE* fp;

	char fileName[100];
	char confirm[16];
	char line[100];
	char* title;
	char* element;
	
	//get the name of file
	do
	{
		//clean the terminal
		printf("\033[2J\033[H");
		//ask for the name of file to load
		printf("Enter filename (xxx.csv): ");
		fgets(fileName, sizeof(fileName), stdin);
		fileName[strcspn(fileName, "\n")] = '\0';
		//auto add ".csv"
		if (strstr(fileName, ".csv") == NULL)
		{
			char tmp[sizeof(fileName)];
			snprintf(tmp, sizeof(tmp), "%s.csv", fileName);
			strncpy(fileName, tmp, sizeof(fileName));
			fileName[sizeof(fileName) - 1] = '\0';
		}
		//confirm
		//confirm the name
		printf("The filename is: %s \nConfirm (yes/cancel): ", fileName);
		fgets(confirm, sizeof(confirm), stdin);
		confirm[strcspn(confirm, "\n")] = '\0';
		//cancel
		if (strcmp(confirm, "cancel") == 0) 
		{
			return LOAD_ERR_CANCELLED;
		}
	} while (strcmp(confirm, "yes") != 0);

	//open the file
	if ((fp = fopen(fileName, "r")) == NULL)
	{
		//failed to open
		return LOAD_ERR_OPEN_FILE;
	}

	//get the every line of the csv doc.
	while (fgets(line, sizeof(line), fp))
	{
		//remove the entery tab
		line[strcspn(line, "\n")] = '\0';
		//divided the title and element
		title = strtok(line, ",");
		element = strtok(NULL, ",");
		//if the data damaged in this line
		if (title == NULL) 
		{
			//pass
			printf("Warning: Skipping a empty line.\n");
			continue;
		}

		//set the position of pointer
		Listptr currentptr = *Lptr;
		Listptr newList = NULL;

		//not the first time
		while (currentptr != NULL) 
		{
			//find the same title
			if (strcmp(currentptr->name, title) == 0) 
			{
				//set the postion
				newList = currentptr;
				break;
			}
			//move to next List title
			currentptr = currentptr->nextL;
		}

		//if it first time 
		if (newList == NULL)
		{
			//set the memory
			newList = malloc(sizeof(Node));
			//faild
			if (newList == NULL)
			{
				goto ERROR;
			}
			//insert name
			strncpy(newList->name, title, sizeof(newList->name) - 1);
			newList->name[sizeof(newList->name) - 1] = '\0';
			//init. the pointer to elements
			newList->head = NULL;
			newList->lastL = NULL;
			//chage the position of pointer
			newList->nextL = *Lptr;
			*Lptr = newList;
			//if this is not the sigle one list node.
			if (newList->nextL != NULL) 
			{
				//set the new listnode location to the last listnode.
				newList->nextL->lastL = newList;
			}
		}
		
		if (element != NULL) 
		{
			//creat element 
			Elementptr newElement = malloc(sizeof(Elem));
			//faild
			if (newElement == NULL)
			{
				goto ERROR;
			}
			//insert the value
			strncpy(newElement->name, element, sizeof(newElement->name) - 1);
			newElement->name[sizeof(newElement->name) - 1] = '\0';
			//init. the next element pointer postion
			newElement->nextE = NULL;
			newElement->lastE = NULL;
			//set the postion of pointer
			newElement->nextE = newList->head;
			newList->head = newElement;
			//if this is not the sigle one element node.
			if (newElement->nextE != NULL) 
			{
				//set the new element node location to the last element.
				newElement->nextE->lastE = newElement;
			}
		}
	}
	//close the doc.
	fclose(fp);

	return LOAD_OK;

	ERROR:
		fclose(fp);
		freeLists(*Lptr);
		*Lptr = NULL;
		return LOAD_ERR_NO_MEMORY;
}