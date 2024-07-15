#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Graphs.h"

void main(){
	matrix AdjMat;
	list AdjList;
	
	initAdjacencyMatrix(AdjMat);
	
	printAdjMat(AdjMat);
	
	addEdge(AdjMat, 0, 1);
	addEdge(AdjMat, 0, 2);
	addEdge(AdjMat, 0, 3);
	addEdge(AdjMat, 1, 2);
	addEdge(AdjMat, 1, 3);
	addEdge(AdjMat, 1, 4);
	addEdge(AdjMat, 2, 3);
	addEdge(AdjMat, 3, 4);
	
	printAdjMat(AdjMat);
	
	initAdjList(AdjList);
	
	printAdjList(AdjList);
	
	addListEdge(AdjList, 0, 1);
	addListEdge(AdjList, 0, 2);
	addListEdge(AdjList, 0, 3);
	addListEdge(AdjList, 1, 2);
	addListEdge(AdjList, 1, 3);
	addListEdge(AdjList, 1, 4);
	addListEdge(AdjList, 2, 3);
	addListEdge(AdjList, 3, 4);
	
	printAdjList(AdjList);
}


