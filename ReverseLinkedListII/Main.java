
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class Main {
    public ListNode reverseBetween( ListNode head, int m, int n) {
        // set a dump node is very useful when implement single linked list data model;
        // helps a lot when dealing with boundries situation
        // because head node may not always be the first node in row;
        // and when input m = 1, it makes code more concisely;
        ListNode dump = new ListNode(0);
        dump.next = head;
        int idx = 1;
        ListNode node = dump;
        while (idx < m) {
            node = node.next;
            idx += 1; 
        }
        // now node is the ref of the node before mth node
        
        ListNode prev = null;
        ListNode next = null;
        ListNode cur = node.next;
        
        idx = m;
        while (idx <= n ) {
            next = cur.next;
            cur.next = prev;
            prev = cur;
            cur = next;
            idx += 1;
        }
        node.next.next = next;
        node.next = prev;
        return dump.next;
    }

    public static void main(String[] args) {
        System.out.print("OK\n");
        //reverseBetween();
    }
}