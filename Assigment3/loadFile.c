#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure.h"
#include "board.h"

void loadFile(Listptr *Lptr) 
{
	//vairables
	FILE* fp;
	char fileName[100];
	char line[100];
	char* title;
	char* element;
	
	//get the name of file
	scanf("%99s", fileName);
	//open the file
	if ((fp = fopen(fileName, "r")) == NULL)
	{
		//faild to open
		printf("Error: Could not open file. The file dose not exist! \n");
		return;
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
		if (title == NULL || element == NULL) 
		{
			//pass
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
			newList = malloc(sizeof(List));
			//faild
			if (newList == NULL)
			{
				printf("Error: No Memory.\n");
				free(newList);
				fclose(fp);
				return;
			}
			//insert name
			newList->head = title;
			//chage the position of pointer
			newList->nextL = *Lptr;
			*Lptr = newList;
		}

		//creat element 
		Elementptr newElement = malloc(sizeof(Element));
		//faild
		if (newElement == NULL)
		{
			printf("Error: No Memory.\n");
			free(newElement);
			fclose(fp);
			return;
		}
		//insert the value
		strcpy(newElement->name, element);
		newElement->nextE = NULL;
		//set the postion of pointer
		newElement->nextE = newList->head;
		newList->head = newElement;
	}
	//close the doc.
	fclose(fp);
	return;
}