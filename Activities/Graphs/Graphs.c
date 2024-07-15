#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Graphs.h"

void initAdjacencyMatrix(matrix AdjMat){
	int i, j;
	
	for(i = 0; i < Gsize; i++){
		for(j = 0; j < Gsize; j++){
			AdjMat[i][j] = 0;
		}
	}
}


void addEdge(matrix AdjMat, int vertex, int edge){
	if(vertex != edge){
		AdjMat[vertex][edge] = 1;
		AdjMat[edge][vertex] = 1;
	} 
}

void printAdjMat(matrix AdjMat){
	int i, j;
	char letter = 'A';
	
	printf("\n\n\n\tA\tB\tC\tD\tE");
	for(i = 0; i < Gsize; i++){
		printf("\n%c", letter+i);
		for(j = 0; j < Gsize; j++){
			printf("\t%d", AdjMat[i][j]);
		}
	}
}

void initAdjList(list AdjList){
	int i;
	for(i = 0; i < Gsize; i++){
		AdjList[i] = NULL;
	}
}

void addListEdge (list AdjList, int vertex, int edge){
	if(vertex != edge){
		NODEPTR newnode = (NODEPTR)malloc(sizeof(struct node));
		if (newnode != NULL){
			newnode->data = edge;
			newnode->next = NULL;	
		}
		
		NODEPTR *trav;
		for(trav = &AdjList[vertex]; *trav != NULL; trav = &(*trav)->next){}
		*trav = newnode;
		
		NODEPTR newnode1 = (NODEPTR)malloc(sizeof(struct node));
		if (newnode != NULL){
			newnode1->data = vertex;
			newnode1->next = NULL;	
		}
		
		for(trav = &AdjList[edge]; *trav != NULL; trav = &(*trav)->next){}
		*trav = newnode1;
	} 
}
void printAdjList(list AdjList){
	int i;
	char letter = 'A';
	NODEPTR trav;
	
	printf("\n\n");
	
	for(i = 0; i < Gsize; i++){
		printf("\n%c\t=\t{", letter+i);
		for(trav = AdjList[i]; trav != NULL; trav = trav->next){
			printf(" %c ", letter+(trav->data));
		}
		printf("}\n");
	}
}
