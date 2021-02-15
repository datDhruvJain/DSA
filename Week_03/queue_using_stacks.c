#include<stdio.h>
#include<stdlib.h>

/* Create stack struct which contains 
   a pointer to an array, the size of that array and a pointer to the current entry location */
typedef struct Stack {
	int *stk;
	int size;

	int t;
} stack;

int isFull(stack *s) {
	if ((*s).t == (*s).size - 1) return 1;
	
	return 0;
}

int isEmpty(stack *s) {
	if ((*s).t == -1) return 1;

	return 0;
}

void push(stack *s, int x) {
	if (!isFull(s)) {
		(*s).t++;
		printf("%s", "Pushing an element");
		(*s).stk[(*s).t] = x;
	}
	else {
		printf("%s","stack full");
	}
}

int pop(stack *s){
	int temp;
	if(!isEmpty(s)){
		temp = (*s).stk[(*s).t];
		(*s).stk--;
		return temp;
	}

	else return -1;
}

typedef struct queue {
	stack *s1;
	stack *s2;
} Queue;

void enQueue(Queue *q, int x) {
	if (!isFull((*q).s2)){
		push((*q).s2, x);
	}
}

void deQueue(Queue *q) {
	while (!isEmpty((*q).s2)) {
		push((*q).s1, pop((*q).s2));

	}

	while (!isEmpty((*q).s1)) {
		pop((*q).s2);
	}
	
}

int main() {
	Queue *q; 
	q = (Queue*) malloc(1*sizeof(Queue));

	(*q).s1 = (stack*) malloc(sizeof(stack));
	(*((*q).s1)).stk = (int*) malloc(10*sizeof(int));
	(*((*q).s1)).size = 1;
	(*((*q).s1)).t = -1;
	(*q).s2 = (stack*) malloc(sizeof(stack));
	(*((*q).s2)).stk = (int*) malloc(10*sizeof(int));
   	(*((*q).s2)).size = 1;
	(*((*q).s2)).t = -1;

	enQueue(q, 10);
	deQueue(q);

}
