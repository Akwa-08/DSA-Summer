#ifndef QUEUE_ARRAY
#define QUEUE_ARRAY

#define MAX 6

typedef struct{
	int data[MAX];
	int front;
	int rear;
}circularQ;

void Enqueue(circularQ *LIST, int elem);
void Dequeue(circularQ *LIST);

bool isEmpty(circularQ LIST);
bool isFull(circularQ LIST);

void display(circularQ LIST);
int Rear(circularQ LIST);
int Front(circularQ LIST);


#endif
