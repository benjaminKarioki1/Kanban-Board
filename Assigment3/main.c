#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "structure.h"
#include "board.h"
#include "edit.h"

int main(void) 
{
	/*
	 *  Here has the variables of the board
	 */
	Listptr head = NULL;

	int option;

	/*
	 *  Here has the main body of the board
	 */
	do
	{
		option = printMenu();
		if (option == 1) 
		{
			//display the board on terminal
			displayBoard(head);
		}
		else if (option == 2) 
		{
			//load the board from the file that user want
			loadFile(&head);
		}
		else if (option == 3)
		{
			//
		}
		else if (option == 4) 
		{
			//
		}
		else if (option == 5) 
		{
			//
		}
		else if (option == 6) 
		{
			//leave out the board
			printf("Quit the board right now.\n");
		}
		else 
		{
			//invalid input
			printf("Invalid Option!\n");
		}
		//clean the terminal
		printf("Press Enter to continue...\n");
		getchar();
		printf("\033[2J\033[H");
	} 
	while (option != 6);

	return 0;
}