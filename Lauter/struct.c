#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

int main(int argc, char **argv) {



struct LinkedList *head;

head = malloc(sizeof(LinkedList));

head -> data = 4; // change the head's data
free(head);



int x;
x = 10;

printf("My var is %d\n", x);

// int my_arr[10]; // pointer in stack, contents of array in heap
// y_arr[0]; // accessing element stored in heap

// bad_fib(2);

return 0;
}

/* 
int bad_fib(int n) {
printf("%d\n", n);
return bad_fib(n - 1) + bad_fib(n - 2);

} */

int good_fib(int n) {
if (n <= 1) {return 1;}
return good_fib(n - 1) + good_fib(n - 2);
}
