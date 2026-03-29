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

void renameItem(Listptr foundElement) {

    if (foundElement == NULL) {
        printf("Can't find item");
        return;
    }
    else {
        char newName[30];
        printf("Enter new name: ");
        fgets(newName, sizeof(newName), stdin);
        newName[strcspn(newName, "\n")] = '\0';
        strcpy(foundElement->name, newName);
    }
}


void addItem(Listptr foundList) {
    Elementptr newElement = malloc(sizeof(Element));
    if (newElement == NULL) { printf("Error: No Memory\n"); return; }

    printf("Enter the name of the new item: ");
    char itemName[20];
    fgets(itemName, sizeof(itemName), stdin);
    itemName[strcspn(itemName, "\n")] = '\0';

    strcpy(newElement->name, itemName);
    newElement->nextE = foundList->head;
    foundList->head = newElement;
}

void deleteItem(Listptr foundList) {

}