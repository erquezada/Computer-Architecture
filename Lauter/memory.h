#include <stdio.h>

typedef struct LinkedList {
	int data;
	struct LinkedList *next;

} LinkedList;

int bad_fib(int n);

int good_fib(int n);
