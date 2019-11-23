#include "stack.h"
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

/* returns 1 if stack is empty, otherwise return 0 */
int empty(struct node *head) {
	return head == NULL ? 1 : 0;
}

void init(struct node *head) {
	head = NULL;
}

struct node* push(struct node *head, int X) {
	struct node* newhead = (struct node*) malloc(sizeof(struct node));
	newhead->data = X;
	newhead->next = head;
	head = newhead;
	return head;
}

struct node* pop(struct node *head, int *element) {
	struct node* newhead = head->next;
	element = head->data;
	free(head);
	head = newhead;
	return head;
}

void display(struct node* head) {
	struct node* curr;
	curr = head;
	if (curr != NULL) {
		printf("Stack: ");
		do
		{
			printf("%d ", curr->data);
			curr = curr->next;
		}
		while (curr != NULL);
		printf("\n");
	}
	else
	{
		printf("The stack is empty\n");
	}
}
