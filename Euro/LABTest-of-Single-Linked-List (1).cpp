#include <stdio.h>
#include <stdlib.h>

//structure
struct Node {
	int data ;
	Node *next ;
};

Node* start = NULL ;

void AddNode( Node** start, int data) {                               
    Node* new_Node = (struct Node*)malloc(sizeof(struct Node));            
    new_Node -> data = data;                                                      
    new_Node -> next = (*start);
    (*start) = new_Node;                                                             
}

void ShowAll(Node* start)
{
    Node* temp = start;
    while (temp != NULL) {
        printf("%d  ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

void ReverseNode( Node* start) {
    if (start == NULL)
	 return;                                                
    ReverseNode(start -> next) ;
    printf("%d  ", start -> data) ;                                                
}

void UpdateNode(Node** start, int prevValue, int newValue) {
    Node* temp = *start ;
    while (temp != NULL) {
        if (temp -> data == prevValue) {
            temp -> data = newValue ;
            return ;
        }
        temp = temp -> next ;
    }
}

void Swap(Node** start, int x, int y) {
	if(x == y) 
		return ;
	Node* prevX = NULL, *presX = *start ;
	while(presX && presX -> data != x) {
		prevX = presX ;
		presX = presX -> next ;
	}
	Node* prevY = NULL, *presY = *start ;	
	while(presY && presY -> data != y) {
		prevY = presY ;
		presY = presY -> next ;
	}
	if(presX == NULL || presY == NULL ) 
		return ;
	if(prevX != NULL) 
		prevX -> next = presY ;
	else 
		*start = presY ;
	
	if(prevY != NULL) 
		prevY -> next = presX ;
	else 
		*start = presX ;
	
	Node* temp = presY -> next ;
	presY -> next = presX -> next ;
	presX -> next = temp ;	
}


int main () {

	AddNode(&start, 40);
    AddNode(&start, 30);
    AddNode(&start, 20);
    AddNode(&start, 10);
    
    printf("Linked List : ") ;
	ShowAll(start);
    printf("-------------------------------\n") ;
    
    printf("ReverseNode : ") ;
    ReverseNode(start) ;
    printf("\n-------------------------------\n") ;
    
    printf("UpdateNode (10 to 99) : ") ;
    UpdateNode(&start, 10,99);
    ShowAll(start);
    printf("------------------------------------------\n") ;
    
    printf("UpdateNode (99 to 10) : ") ;
    UpdateNode(&start, 99,10);
    ShowAll(start);
    printf("------------------------------------------\n") ;  
    
	printf("Swapping Node : ") ;
	Swap(&start, 10, 40) ;
	ShowAll(start) ;
    printf("-------------------------------\n") ;
	printf("Swapping Node : ") ;
	Swap(&start, 20, 30) ;
	ShowAll(start) ;    
	
	return 0 ;
}//end function


