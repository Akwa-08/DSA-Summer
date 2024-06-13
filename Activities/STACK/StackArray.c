#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

StackArrayList createStack() {
    StackArrayList s;
    s.top = -1;
    return s;
}

bool isEmpty(StackArrayList s) {
    return (s.top == -1);
}

bool isFull(StackArrayList s) {
    return (s.top >= MAX-1); 
}

bool stack_push(StackArrayList *s, int elem) {
    if (!isFull(*s)) {
        s->data[s->top+1] = elem; 
        s->top++;
        return true;
    }
    return false;
}

bool stack_pop(StackArrayList *s) {
    if (!isEmpty(*s)) {
    	
        s->top--;
        return true;
    }
    return false;
}

int stack_peek(StackArrayList s) { 
    if (!isEmpty(s)) {
        return s.data[s.top];
    }
    return -1; 
}

void display(StackArrayList s) {
    if (!isEmpty(s)) {
    	
        StackArrayList temp;
		temp.top = -1;
		printf("\n\n\t-----DISPLAYING LIST--------");
		printf("\n\n\t BOTTOM :\t");
		
		int i;
		for(i = s.top ;i >= 0; i--){
			stack_push(&temp, stack_peek(s));
			stack_pop(&s);
		}
		
		for(i = temp.top ;i >= 0; i--){
			printf("%d ", stack_peek(temp));
			stack_pop(&temp);
		}
			
		printf("\t : TOP");
        
    } else {
        printf("Stack is Empty\n");
    }
}

void visualize(StackArrayList s) {
    if (!isEmpty(s)) {
    	printf("\n\n\t-----VISUALIZING LIST--------");
        printf("\n\n\tIndex\tData\n");
        
        StackArrayList temp;
		temp.top = -1;
		
		int i;
		for(i = s.top ;i >= 0; i--){
			stack_push(&temp, stack_peek(s));
			stack_pop(&s);
		}
		
		int ctr = 0;
		for(i = temp.top ;i >= 0; i--){
			printf("\n\t%d\t%d", ctr, stack_peek(temp));
			stack_pop(&temp);
			ctr++;
			if(isEmpty(temp)){
				printf(" TOP");
			}
		}

    } else {
        printf("Stack is Empty\n");
    }
}

