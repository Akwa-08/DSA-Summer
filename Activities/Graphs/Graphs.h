#ifndef GRAPHS
#define GRAPHS

#define Gsize 5

typedef struct node{
	char data;
	struct node *next;
}*NODEPTR;

typedef NODEPTR list[Gsize];

typedef int matrix[Gsize][Gsize];

void createAdjacencyMatrix(matrix AdjMat);
void addEdge(matrix AdjMat, int vertex, int edge);
void printAdjMat(matrix AdjMat);

void initAdjList(list AdjList);
void addListEdge(list AdjList, int vertex, int edge);
void printAdjList(list AdjList);


#endif
