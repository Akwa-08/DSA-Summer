#ifndef QUEUE_LL
#define QUEUE_LL

typedef struct node{
	int data;
	struct node *next;
}Node, *NodePTR;

typedef struct{
	NodePTR front;
	NodePTR rear;
}Queue;

bool isEmpty(Queue LIST);
void Enqueue(Queue *LIST, int elem);
void Dequeue(Queue *LIST);
int Front(Queue LIST);
int Rear(Queue LIST);

#endif
