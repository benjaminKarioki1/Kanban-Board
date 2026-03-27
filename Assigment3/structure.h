//the structure for elements
typedef struct Elements
{
	//name of the element
	char name[30];
	//pointer to next element
	struct Elements* nextE;
}Element;
//make a pointer 
typedef Element* Elementptr;

//the structure for lists
typedef struct Lists
{
	//name of the list
	char name[30];
	//to the elements
	Elementptr head;
	//pointer to next list
	struct Lists* nextL;
}List;
//make a pointer
typedef List* Listptr;