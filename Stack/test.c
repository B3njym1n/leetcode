#include "stack.h"
#include <stdio.h>

int main(int argc, char** argv)
{
	struct node* head = NULL;
	int size, element;
	int counter = 0;

	printf("Enter the number of stack elements:");
	scanf("%d", &size);

	printf("--- Push elements into stack\n");

	init(head);

	while(counter < size)
	{
		printf("Enter a number to push into stack\n");
		scanf("%d", &element);
		head = push(head, element);
		display(head);
		counter++;
	}

	printf("--- Pop elements from the stack\n");
	while(empty(head) == 0)
	{
		head = pop(head, element);
		printf("pop %d from stack\n", element);
		display(head);
	}

	return 0;
}
