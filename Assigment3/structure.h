typedef struct Boards
{
	//name of the list
	char name[30];
	//pointer to next list
	struct Boards* nextL;
}Board;
 
typedef struct Elements 
{
	//name of the element
	char name[30];
	//pointer to next element
	struct Elements* nextE;
}Element;
