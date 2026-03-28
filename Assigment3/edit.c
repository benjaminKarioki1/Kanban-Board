#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "edit.h"

// searches the board for a list by name, returns a pointer to it (or NULL)
Listptr findList(Listptr head, char *targetName) {
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
Elementptr findElement(Elementptr head, char *targetName) {
    Elementptr current = head;
    while (current != NULL) {
        if (strcmp(current->name, targetName) == 0) {
            return current;
        }
        current = current->nextE;
    }
    return NULL;
}

void renameItem(Listptr head){

    printf("Enter name of the list: ");
    char name[20];
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    Listptr foundList = findList(head, name);
    if (foundList == NULL){
        printf("Can't find list\n");
    } else {
        printf("Enter the name of the item to edit: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        Listptr foundElement = findElement(foundList->head, name);
        if (strcmp(name, sizeof(name)) != 0){
            printf("Can't find item");
        } else {
            char newName[30];
            printf("Enter new name: ");
            fgets(newName, sizeof(newName), stdin);
            newName[strcspn(newName, "\n")] = '\0';
            strcpy(foundElement->name, newName);
        }
    }

}