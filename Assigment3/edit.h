#pragma once
#include "structure.h"

Listptr findList(Listptr head, char *targetName);
Elementptr findElement(Elementptr head, char *targetName);

void renameItem(Listptr foundElement);
void addItem(Listptr foundList);
void deleteItem(Listptr foundList);