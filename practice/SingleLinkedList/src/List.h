#ifndef _List_H
#define _List_H

#include <stdio.h>
#include <stdlib.h>

struct ListNode;

typedef struct ListNode {
    struct ListNode *next;
    void *value;
} ListNode;

typedef struct List {
    int count;
    ListNode *first;
    ListNode *last;
} List;

List *List_create();
void List_push(List *list , void *value);
void List_destroy(List *list);
void List_reverse(List *list);

#define List_count(A) ((A)->count)
#define List_first(A) ((A)->first != NULL ? (A)->first->value : NULL)
#define List_last(A) ((A)->last!= NULL ? (A)->last->value : NULL)
#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
                                                   ListNode *V = NULL;\
for (V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif
