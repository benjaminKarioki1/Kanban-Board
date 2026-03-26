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
	int option;

	/*
	 *  Here has the main body of the board
	 */
	do
	{
		option = printMenu();
		if (option == 1) 
		{
			//
		}
		else if (option == 2) 
		{
			//
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
			printf("Quit the board right now.\n");
		}
		else 
		{
			printf("Invalid Option!\n");
		}

		system("pause");
		printf("\033[2J\033[H");
	} 
	while (option != 6);

	return 0;
}