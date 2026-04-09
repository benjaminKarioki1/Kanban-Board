#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure.h"
#include "board.h"
#include "edit.h"

// sub-menu for option 4
int printBoardOptions(void) {
    int choice;
    printf("Options:\n"
           "1. Edit the name of a list\n"
           "2. Add a new list\n"
           "3. Delete a list\n"
           "4. Return to main menu\n"
           "Enter your option: ");
    scanf("%d", &choice);
    scanf("%*[^\n]");
    scanf("%*c");
    return choice;
}
