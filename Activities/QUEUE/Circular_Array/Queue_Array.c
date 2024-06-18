#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue_Array.h"

bool isEmpty(circularQ LIST){
	bool retval;
	return retval = ((LIST.rear + 1)% MAX == LIST.front) ? 1 : 0;
}

bool isFull(circularQ LIST){
	bool retval;
	return retval = ((LIST.rear + 2)% MAX == LIST.front) ? 1 : 0;
}

void display(circularQ LIST){
	printf("\n\n\t--------DISPLAYING QUEUE---------\n\n\tFRONT:  ");
	
	if(!isEmpty(LIST)){
		
		int i;
		for(i = LIST.front; i <= LIST.rear; i++){
			printf(" %d ", LIST.data[i]);
		}
		printf("    :REAR");
	} else {
		printf("!!! QUEUE IS EMPTY !!!");
	}
}

int Rear(circularQ LIST){
	return LIST.rear;
}

int Front(circularQ LIST){
	return LIST.front;
}

void Enqueue(circularQ *LIST, int elem){
	printf("\n\n\t--------ENQUEUING %d---------", elem);
	
	if(!isFull(*LIST)){
		
		LIST->rear = (LIST->rear + 1) % MAX;
		LIST->data[LIST->rear] = elem;		
	} else {
		printf("\n\n\t!!! LIST IS FULL !!!");
	}
}

void Dequeue(circularQ *LIST){
	printf("\n\n\t--------DEQUEUING %d---------", LIST->data[LIST->front]);
	
	if(!isEmpty(*LIST)){
		
		LIST->front = (LIST->front + 1) % MAX;
	} else {
		printf("\n\n\t!!! LIST IS EMPTY !!!");
	}
}



