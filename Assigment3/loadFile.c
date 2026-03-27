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
	printf("Enter filename: ");
	scanf("%99s", fileName);
	//clean the stdin
	scanf("%*[^\n]");
	scanf("%*c");
	//open the file
	if ((fp = fopen(fileName, "r")) == NULL)
	{
		//faild to open
		printf("Error: Could not open file. The %s dose not exist! \n", fileName);
		
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
		if (title == NULL) 
		{
			//pass
			printf("Warning: Skipping malformed line: %s\n", line);
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
			strcpy(newList->name, title);
			//init. the pointer to elements
			newList->head = NULL;
			//chage the position of pointer
			newList->nextL = *Lptr;
			*Lptr = newList;
		}
		
		if (element != NULL) 
		{
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
			//init. the next element pointer postion
			newElement->nextE = NULL;
			//set the postion of pointer
			newElement->nextE = newList->head;
			newList->head = newElement;
		}
	}
	//close the doc.
	fclose(fp);
	return;
}