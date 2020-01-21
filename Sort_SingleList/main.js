/**
 * 排序链表
 * Sort a linked list in O(n log n) time using constant space complexity.
 */
/**
 * Example 1:
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 */
/**
 * Example 2:
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
 * @return {ListNode}
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
 * @return {ListNode}
 */
var sortList = function(head) {
    var dump = new ListNode(0);
    dump.next = head;
    var slow = head;
    var fast = head;
    var beforeSlow = null;
    while (fast != null && fast.next != null)
    {
        beforeSlow = slow;
        slow = slow.next;
        fast = fast.next.next;
    }

    // partition
    var mid = slow;
    var start = dump;
    if (beforeSlow != null) {
        beforeSlow.next = null;
    } else {
        return head;
    }

    // recursion
    head = sortList(head);
    mid = sortList(mid);

    while(head != null && mid != null) {
        if (head.val <= mid.val) {
            start.next = head;
            start = start.next;
            head = head.next;
        } else {
            start.next = mid;
            start = start.next;
            mid = mid.next;
        }
    }

    if (head != null) {
        start.next = head;
    }

    if (mid != null) {
        start.next = mid;
    }

    return dump.next;
};
