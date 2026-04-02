#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

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
	int editOption;


	/*
	 * Print the title at here
	 * ASCII Art
	 */
	title();
	//clean the terminal
	printf("Press Enter to continue...\n");
	getchar();
	printf("\033[2J\033[H");


	/*
	 *  Here has the main body of the board
	 */
	do
	{
		//get the option from user
		option = printMenu();
		
		//the main body to response the options
		if (option == 1) 
		{
			//display the board on terminal
			displayBoard(head);
		}
		else if (option == 2) 
		{
			//load the board from the file that user want
			int l_status = loadFile(&head);
			switch (l_status)
			{
			case LOAD_OK:
				printf("File load successfully.\n");
				break;
			case LOAD_ERR_CANCELLED:
				printf("Operation cancelled by user.\n");
				break;
			case LOAD_ERR_OPEN_FILE:
				printf("Could not open file.\n");
				break;
			case LOAD_ERR_NO_MEMORY:
				printf("Error during loading. No Memoery\n");
				break;
			default:
				printf("Unknown error occurred.\n");
			}
		}
		else if (option == 3)
		{
			//edit items on the board
			char name[20];
			printf("Enter the name of the list to edit: ");
			fgets(name, sizeof(name), stdin);
			name[strcspn(name, "\n")] = '\0';
			Listptr foundList = findList(head, name); //search function
			if (foundList == NULL)
			{
				printf("Can't find list\n");
			}
			else
			{
				do
				{
					editOption = printOptions();
					switch (editOption)
					{
					case 1:
						renameItem(foundList);
						break;
					case 2:
						addItem(foundList);
						break;
					case 3:
						deleteItem(foundList);
						break;
					case 4:
						break;
					default:
						printf("Invalid option!\n");
						break;
					}
				} while (editOption != 4);
			}
		}
		else if (option == 4) 
		{
			//
		}
		else if (option == 5) 
		{
			//write the board to the file
			int w_status = writeFile(head);
			//eoor solut
			switch (w_status) 
			{
			case WRITE_OK:
				printf("File written successfully.\n");
				break;
			case WRITE_ERR_CANCELLED:
				printf("Operation cancelled by user.\n");
				break;
			case WRITE_ERR_OPEN_FILE:
				printf("Could not open file.\n");
				break;
			case WRITE_ERR_WRITE_FAILED:
				printf("Error during writing. Disk full?\n");
				break;
			case WRITE_ERR_CLOSE_FILE:
				printf("Could not close file.\n");
				break;
			default:
				printf("Unknown error occurred.\n");
			}
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

	//release the linked list
	freeLists(head);

	return 0;
}