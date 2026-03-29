/*
 * functional functions
 */
//the function that use for Menu
int printMenu(void);
//the function that use for display
void displayBoard(Listptr Lptr);
//the function that use for load file
int loadFile(Listptr* Lptr);
//the function that use for write file
int writeFile(Listptr Lptr);

/*
 * recursive functions
 */
//recursion the linked list
int writeListRecursively(Listptr Lptr, FILE* fp);
//recursion the sub-linked list
int writeElemRecursively(Elementptr Eptr, char* name, FILE* fp);

/*
 * memory release functions
 */
//release the linked list
void freeLists(Listptr Lptr);
//release the sub-linked list
void freeElements(Elementptr Eptr);

/*
 * ASCII art functions
 */
//print out the title of programe
void title(void);