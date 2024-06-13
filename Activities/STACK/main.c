#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "StackArray.h"

void main(){
	StackArrayList s = createStack();
	
	stack_push(&s, 1);
	stack_push(&s, 2);
	stack_push(&s, 3);
	
	display(s);
	visualize(s);
	
	stack_pop(&s);
	stack_pop(&s);
	stack_push(&s, 4);
	
	display(s);
	visualize(s);
	
	
}
