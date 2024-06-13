#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char name[20];
	int idNum;
	int age;
}info;

typedef struct node{
	info data;
	struct node *next;
}NODE, *NODEPTR;

info getData();
void populateList(NODEPTR *head);
void display(NODEPTR head);
void insertFront(NODEPTR *head);
void insertEnd(NODEPTR *head);
void insertAt(NODEPTR *head);


void main(){
	NODEPTR head = NULL;
	
	populateList(&head);
	display(head);
	
//	insertFront(&head);
//	display(head);
//	
//	insertEnd(&head);
//	display(head);
	
	insertAt(&head);
	display(head);
	
}

info getData(){
	
	info data;
	
	printf("\n\tID: ");
	scanf("%d", &data.idNum);
	
	printf("\tName: ");
	scanf("%s", data.name);
	
	printf("\tAge: ");
	scanf("%d", &data.age);
	
	return data;
}

void populateList(NODEPTR *head){
	
	NODEPTR node1 = (NODEPTR)malloc(sizeof(struct node));
	node1->data.idNum = 1;
	strcpy(node1->data.name, "Vinceade");
	node1->data.age = 20;
	
	NODEPTR node2 = (NODEPTR)malloc(sizeof(struct node));
	node2->data.idNum = 2;
	strcpy(node2->data.name, "Natasha");
	node2->data.age = 21;
	
	NODEPTR node3 = (NODEPTR)malloc(sizeof(struct node));
	node3->data.idNum = 3;
	strcpy(node3->data.name, "Ash");
	node3->data.age = 22;
	
	*head = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	
}

void display(NODEPTR head){
	if(head != NULL){
		
		printf("\n\n\t--------DISPLAYING LINKED LIST---------\n\n\t ");
		NODEPTR trav;
		for(trav = head; trav != NULL; trav = trav->next){
			printf("|%d - %s - %d|", trav->data.idNum, trav->data.name, trav->data.age);
			if(trav->next != NULL){
				printf("  >  ");
			}
		}
			printf("\n");
	}
}

void insertFront(NODEPTR *head){
	
	printf("\n\n\t--------INSERTING AT FRONT---------\n");
	
	NODEPTR newNode = (NODEPTR)malloc(sizeof(struct node));
	newNode->data = getData();
	newNode->next = *head;
	*head = newNode;
	
}

void insertEnd(NODEPTR *head){
	printf("\n\n\t--------INSERTING AT END---------\n");
	
	NODEPTR *trav;
	for(trav = head; *trav != NULL; trav = &((*trav)->next)){}
	
	NODEPTR newNode = (NODEPTR)malloc(sizeof(struct node));
	newNode->data = getData();
	newNode->next = NULL;
	*trav = newNode;
	
}

void insertAt(NODEPTR *head){
	printf("\n\n\t--------INSERTING AT INDEX---------\n");
	
	int pos;
	printf("\n\tPosition: ");
	scanf("%d", &pos);
	
	NODEPTR *trav;
	int i = 1;
	for(trav = head; *trav != NULL && i < pos; trav = &((*trav)->next)){ i++; }
	
	NODEPTR newNode = (NODEPTR)malloc(sizeof(struct node));
	newNode->data = getData();
	newNode->next = *trav;
	*trav = newNode;
}

