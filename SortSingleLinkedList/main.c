#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list
 * struct ListNode {
 *     int val;
 *     strunct ListNode *next;
 * };
 */
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* sortList(struct ListNode* head) {
  if (!head || !(head->next)) return head;
  struct ListNode* fast = head->next, *slow = head;

  while (fast&&fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
}

int main () {
  struct ListNode *dump = malloc(sizeof(struct ListNode));
  memset(dump, 0, sizeof(*dump));
  printf("%d\n", dump->val); 
  return 0;
}
