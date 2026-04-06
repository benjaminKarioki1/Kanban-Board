#pragma once 
//the structure for elements
typedef struct Element
{
	//name of the element
	char name[30];
	//pointer to next element
	struct Element* nextE;
	//pointer to last element
	struct Element* lastE;
}Elem;
//make a pointer 
typedef Elem* Elementptr;

//the structure for lists
typedef struct ListNode
{
	//name of the list
	char name[30];
	//to the elements
	Elementptr head;
	//pointer to next list
	struct ListNode* nextL;
	//pointer to last llist
	struct ListNode* lastL;
}Node;
//make a pointer
typedef Node* Listptr;

//the enumeration for loading
typedef enum 
{
	LOAD_OK = 0,
	LOAD_ERR_CANCELLED = -1,
	LOAD_ERR_OPEN_FILE = 1,
	LOAD_ERR_NO_MEMORY = 2
} LoadStatus;

//the enumeration for writting
typedef enum 
{
	WRITE_OK = 0,
	WRITE_ERR_CANCELLED = -1,     
	WRITE_ERR_OPEN_FILE = 1,      
	WRITE_ERR_WRITE_FAILED = 2,   
	WRITE_ERR_CLOSE_FILE = 3,     
	//WRITE_ERR_INVALID_PARAM = 4   
} WriteStatus;
