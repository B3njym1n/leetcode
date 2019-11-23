#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

struct node;
int empty(struct node*);
struct node* push(struct node* s, int data);
struct node* pop(struct node *s, int* element);
void init(struct node* s);
void display(struct node* head);

#endif
