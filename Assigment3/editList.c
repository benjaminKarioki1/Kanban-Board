#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structure.h"
#include "edit.h"

// searches the board for a list by name, returns a pointer to it (or NULL)
Listptr findList(Listptr head, char* targetName) {
    Listptr current = head;
    while (current != NULL) {
        if (strcmp(current->name, targetName) == 0) {
            return current;
        }
        current = current->nextL;
    }
    return NULL;
}

// searches a list for an element by name, returns a pointer to it (or NULL)
Elementptr findElement(Elementptr head, char* targetName) {
    Elementptr current = head;
    while (current != NULL) {
        if (strcmp(current->name, targetName) == 0) {
            return current;
        }
        current = current->nextE;
    }
    return NULL;
}

// function to rename the element of a board
void renameItem(Listptr foundList) {
    // ask which element to rename
    char itemName[30];
    printf("Enter the name of the item to edit: ");
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = '\0';

    // find the element inside the list
    Elementptr foundElement = findElement(foundList->head, itemName);

    // check if it exists
    if (foundElement == NULL) {
        printf("Can't find item\n");
        return;
    }

    // ask for the new name
    char newName[30];
    printf("Enter new name for item '%s': ", itemName);
    fgets(newName, sizeof(newName), stdin);
    newName[strcspn(newName, "\n")] = '\0';

    //  overwrite the old name
    strcpy(foundElement->name, newName);
}

//function to add an element to the board
void addItem(Listptr foundList) {
    //allocate memory for a new node
    Elementptr newElement = malloc(sizeof(Node));
    if (newElement == NULL) { printf("Error: No Memory\n"); return; }

    //get the name of the new item
    printf("Enter the name of the new item: ");
    char itemName[20];
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = '\0';

    //add it to the list and set the pointers to the next node
    strcpy(newElement->name, itemName);
    newElement->nextE = foundList->head;
    foundList->head = newElement;
}

//function to delete the element of a board
void deleteItem(Listptr foundList) {
    //ask which element to delete
    char name[20];
    printf("Enter the name of the item to delete: ");
	fgets(name, sizeof(name),stdin);
	name[strcspn(name, "\n")] = '\0';

    Elementptr current = foundList->head;
    Elementptr prev = NULL;

    //check if the list is empty
    if (foundList->head == NULL)
    {
        printf("The list is empty");
        return;
    }
    else 
    {   
        //otherwise check if the name the user gave is the same as the head node
        if (strcmp(foundList->head->name, name)== 0) 
        {
            Elementptr temp = foundList->head; //save old head node
            foundList->head = foundList->head->nextE; //move head pointer to next element
            free(temp); //free memory of the old head node
        } 
        else
        {
            
            while (current != NULL)
            {
                //check equivalence for the rest of the nodes
                if (strcmp(current->name, name) == 0){
                    prev->nextE = current->nextE; //moves "prev" pointer to the value of nextE pointed to by "current"
                    free(current); //free memory of the current node
                    return;
                }
                // keep track of the node behind "current" and node ahead of "current"
                prev = current;
                current = current->nextE;
            }
            printf("Can't find item\n");
        }
    }
}