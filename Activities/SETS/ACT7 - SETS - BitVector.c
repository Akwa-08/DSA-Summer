#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    unsigned int elem[MAX];    
} SET;

void addValue(SET *A, int data);
void deleteValue(SET *A, int data);
void display(SET A);

SET SetUnion(SET A, SET B);
SET SetIntersection(SET A, SET B);

void initializeSet(SET *A);

void main() {
    SET X, Y, Z;
    
    initializeSet(&X);
    initializeSet(&Y);
    initializeSet(&Z);
    
    addValue(&X, 0);
    addValue(&X, 2);
    addValue(&X, 4);
    addValue(&X, 5);
    addValue(&X, 6);
    addValue(&X, 8);
    printf("\n\n\t----------DISPLAYING SET X---------");
    printf("\n\n\tSET X =");
    display(X);
    
    addValue(&Y, 1);
    addValue(&Y, 2);
    addValue(&Y, 3);
    addValue(&Y, 5);
    addValue(&Y, 6);
    addValue(&Y, 7);
    addValue(&Y, 9);
    printf("\n\n\t----------DISPLAYING SET Y---------");
    printf("\n\n\tSET Y =");
    display(Y);
    
    Z = SetUnion(X, Y);
    printf("\n\n\t----------DISPLAYING X union Y---------");
    printf("\n\n\tSET Z =");
    display(Z);
    
    Z = SetIntersection(X, Y);
    printf("\n\n\t----------DISPLAYING X intersect Y---------");
    printf("\n\n\tSET Z =");
    display(Z);
}

void initializeSet(SET *A) {
	int i;
    for (i = 0; i < MAX; i++) {
        A->elem[i] = 0;
    }
}

void addValue(SET *A, int data) {
    if (data >= 0 && data < MAX) {
        printf("\n\n\t----------ADDING VALUE %d----------", data);
        A->elem[data] = 1;
    }
}

void deleteValue(SET *A, int data) {
    if (data >= 0 && data < MAX) {
        printf("\n\n\t----------DELETING VALUE %d----------", data);
        A->elem[data] = 0;
    }
}

void display(SET A) {
    printf("{");
    int i;
    for (i = 0; i < MAX; i++) {
        if (A.elem[i]) {
            printf(" %d", i);
        }
    }
    printf(" }");
}

SET SetUnion(SET A, SET B) {
    SET newSet;
    initializeSet(&newSet);
    printf("\n\n\t-------UNION OF TWO PASSED SETS------");
    int i;
	for (i = 0; i < MAX; i++) {
        if (A.elem[i] || B.elem[i]) {
            newSet.elem[i] = 1;
        }
    }
    return newSet;
}

SET SetIntersection(SET A, SET B) {
    SET newSet;
    initializeSet(&newSet);
    printf("\n\n\t-------INTERSECTION OF TWO PASSED SETS------");
    int i;
	for (i = 0; i < MAX; i++) {
        if (A.elem[i] && B.elem[i]) {
            newSet.elem[i] = 1;
        }
    }
    return newSet;
}
