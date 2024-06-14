#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QueueLL.h"

void main(){
	Queue LIST;
	LIST.rear = LIST.front = NULL;
	
	Enqueue(&LIST, 1);
	display(LIST);
	
	Enqueue(&LIST, 2);
	Enqueue(&LIST, 3);
	Enqueue(&LIST, 4);
	display(LIST);
	
	Dequeue(&LIST);
	display(LIST);
	
	Dequeue(&LIST);
	Dequeue(&LIST);
	display(LIST);
	
}
