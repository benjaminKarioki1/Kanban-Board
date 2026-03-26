#include "structure.h"
#include "board.h"

int printMenu(void) 
{
	//variable
	int choose;
	//print out the menu
	printf(	"Menu:\n" 
			"1. Display board\n"
			"2. Load board from a file\n"
			"3. Edit list\n"
			"4. Edit Board\n"
			"5. Save board to a file\n"
			"6. Quit\n"
			"Enter your choice(1 - 5) : \n");
	//get the option thar user want
	scacnf("%d", &choose);
	//return the option number back
	return choose; 
}