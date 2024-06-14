#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QueueLL.h"

void main(){
	Queue LIST;
	LIST.rear = LIST.front = NULL;
	
	Enqueue(&LIST, 1);
	display(LIST);
	Front(LIST);
	Rear(LIST);
	
	Enqueue(&LIST, 2);
	Enqueue(&LIST, 3);
	Enqueue(&LIST, 4);
	display(LIST);
	Front(LIST);
	Rear(LIST);
	
	Dequeue(&LIST);
	display(LIST);
	Front(LIST);
	Rear(LIST);
	
	Dequeue(&LIST);
	Dequeue(&LIST);
	display(LIST);
	Front(LIST);
	Rear(LIST);
	
}
