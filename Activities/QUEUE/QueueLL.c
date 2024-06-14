#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QueueLL.h"

bool isEmpty(Queue LIST){
	bool retval = (LIST.front == NULL && LIST.rear == NULL) ? 1 : 0;
}

void display(Queue LIST){
	if(!isEmpty(LIST)){
		
		printf("\n\n\t----------PRINTING QUEUE----------\n\n\t FRONT: ");
		NodePTR trav;
		for(trav = LIST.front; trav != NULL; trav = trav->next){
			printf("|%d|", trav->data);
			if(trav->next != NULL){
				printf(" <- ");
			}
		}
	} else {
		printf("QUEUE IS EMPTY");
	}
}

void Enqueue(Queue *LIST, int elem){
	
	printf("\n\n\t----------ENQUEUING NUMBER %d----------\n", elem);
	
	NodePTR newNode = (NodePTR) malloc (sizeof(struct node));
	newNode->data = elem;
	newNode->next = NULL;
	
	if(isEmpty(*LIST)){	
		LIST->front = LIST->rear = newNode;		
	} else {
		LIST->rear->next = newNode;
		LIST->rear = newNode;
	}
}

void Dequeue(Queue *LIST){
	
	printf("\n\n\t----------DEQUEUING FRONT----------\n");
	
	if(!isEmpty(*LIST)){
		
		NodePTR temp = LIST->front;
		LIST->front = LIST->front->next;
		free(temp);
		
	} else {
		printf("\n\n\t QUEUE IS EMPTY");
	}
}

void Front(Queue LIST){
	if(!isEmpty(LIST)){
		printf("\n\n\t----------PRINTING FRONT----------\n\n\t");
		printf("FRONT: %d", LIST.front->data);
	}
}

void Rear(Queue LIST){
	if(!isEmpty(LIST)){
		printf("\n\n\t----------PRINTING REAR----------\n\n\t");
		printf("REAR: %d", LIST.rear->data);
	}
}



