/**
 * 环形链表
 * Given a linked list, determine if it has a cycle in it.
 * To represent a cycle in the given linked list, 
 * we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. 
 * If pos is -1, then there is no cycle in the linked list.
 */

 /**
  * Example 1:
  * Input: head = [3,2,0,-4], pos = 1
  * Output: true
  * Explanation: There is a cycle in the linked list, where tail connects to the second node.
  */

/** 
 * Example 2:
 * Input: head = [1,2], pos = 0
 * Output: true
 * Explanation: There is a cycle in the linked list, where tail connects to the first node. 
 */

/** 
Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 */

 /**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */
var hasCycle = function(head) {
    let count = -1;
    let cur = head;
    while (cur != null) {
        cur = cur.next;
        count += 1;
        let sp = head;
        let cnt = 0;
        while (sp !== cur && cnt < count) {
            sp = sp.next;
            cnt += 1;
        }
        if (sp !== cur) continue;
        if (sp === cur) {
            return true;
        }
    }
    return false;
};