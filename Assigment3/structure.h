typedef struct Lists
{
	//name of the list
	char name[30];
	//pointer to next list
	struct Lists* nextL;
}List;
 
typedef struct Elements 
{
	//name of the element
	char name[30];
	//pointer to next element
	struct Elements* nextE;
}Element;
