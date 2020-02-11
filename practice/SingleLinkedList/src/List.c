#include "List.h"

List *List_create() {
    List *list = malloc(sizeof(List));
    list->first = NULL;
    list->last = NULL;
    return list;
}

void List_push(List *list , void *value) {
   ListNode *node = calloc(1, sizeof(ListNode));
   node->value = value;
   if (list->last == NULL) {
       list->first = node;
       list->last = node;
   } else {
       list->last->next = node;
       list->last = node;
   }

   list->count++;
}

void List_destroy(List *list) {
    LIST_FOREACH(list, first, next, curr) {
        free(curr);
    }
    
    free(list);
}

void List_reverse(List *list) {
    if (list->first) {
        ListNode *cur = list->first;
        ListNode *next_node = cur->next;
        while (next_node != NULL) {
            ListNode *temp = next_node->next;
            next_node->next = cur;
            cur = next_node;
            next_node = temp;
        }
        list->first->next = NULL;
        ListNode *t2 = list->last;
        list->last = list->first;
        list->first = t2;
    }
}
