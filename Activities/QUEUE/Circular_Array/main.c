#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue_Array.h"

int main(){
	circularQ LIST;
	LIST.front = 0;
	LIST.rear = MAX-1;
	
	Enqueue(&LIST, 1);	
	Enqueue(&LIST, 2);
	Enqueue(&LIST, 3);
	Enqueue(&LIST, 4);	
	Enqueue(&LIST, 5);
	Enqueue(&LIST, 6);
	display(LIST);
	
	Dequeue(&LIST);
	display(LIST);
	
	Enqueue(&LIST, 6);
	Enqueue(&LIST, 7);
	display(LIST);
	
	
	return 0;
}
