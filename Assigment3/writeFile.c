#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure.h"
#include "board.h"

int writeFile(Listptr Lptr)
{
	//variable
	FILE* fp;

	char fileName[100];
	char confirm[16];

	//get the name of file
	do
	{
		//clean the terminal
		printf("\033[2J\033[H");
		//ask for the name of file to write
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
		//confirm the name
		printf("The filename is: %s \nConfirm (yes/cancel): ", fileName);
		fgets(confirm, sizeof(confirm), stdin);
		confirm[strcspn(confirm, "\n")] = '\0';
		//cancel
		if (strcmp(confirm, "cancel") == 0)
		{
			return WRITE_ERR_CANCELLED;
		}
	} while (strcmp(confirm, "yes") != 0);

	//open the file
	if ((fp = fopen(fileName, "w")) == NULL)
	{
		return WRITE_ERR_OPEN_FILE;
	}

	//excude the recursion
	int err = writeListRecursively(Lptr, fp);
	//close the file when has error
	if (err != WRITE_OK)
	{
		fclose(fp);  
		return err;
	}

	//failed to close file
	if (fclose(fp) == EOF) 
	{
		return WRITE_ERR_CLOSE_FILE;
	}

	return WRITE_OK;
}


/*
 * recursive functions
 */
//recursion the List
int writeListRecursively(Listptr Lptr, FILE* fp)
{
	//to the end of Linked List
	if (Lptr == NULL) 
	{
		return WRITE_OK;
	}

	//recursion to the next List
	int err = writeListRecursively(Lptr->nextL, fp);
	if (err != WRITE_OK)
	{
		return err;
	}

	////recursion the elenments under this List
	if (Lptr->head == NULL) 
	{
		//if there has no element under this List 
		if (fprintf(fp, "%s\n", Lptr->name) < 0)
		{
			//send back error
			return WRITE_ERR_WRITE_FAILED;
		}
		//write succesful
		return WRITE_OK;
	}
	else 
	{	
		//use recursion to write
		err = writeElemRecursively(Lptr->head, Lptr->name, fp);
		//send back error
		if (err != WRITE_OK)
		{
			return err;
		}
		//send succes message
		return WRITE_OK;
	}
}

int writeElemRecursively(Elementptr Eptr, char* name, FILE* fp)
{
	//to the end of linked list
	if (Eptr == NULL) 
	{
		return WRITE_OK;
	}

	//recursion to the next element
	int err = writeElemRecursively(Eptr->nextE, name, fp);
	//send back error
	if (err != WRITE_OK)
	{
		return err;
	}

	//write into file
	if (fprintf(fp, "%s,%s\n", name, Eptr->name) < 0) 
	{
		//send back error
		return WRITE_ERR_WRITE_FAILED;
	}
	//write succesful
	return WRITE_OK;
}