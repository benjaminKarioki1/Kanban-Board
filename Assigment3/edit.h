#pragma once

Listptr findList(Listptr head, char *targetName);
Elementptr findElement(Elementptr head, char *targetName);

void renameItem(Listptr foundList);
void addItem(Listptr foundList);
void deleteItem(Listptr foundList);