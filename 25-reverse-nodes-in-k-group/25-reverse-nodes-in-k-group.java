/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    
   public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummyHead = new ListNode(-1);
        dummyHead.next = head;
        ListNode curr = head;
        ListNode prev = dummyHead;
        int count = k;
        while(curr != null) {
            if(count > 0) {
                count--;
            }
            if(count == 0) {
                ListNode next = curr.next;
                curr.next = null;
                prev = reverse(prev, prev.next, next); //Reverse from prev.next until curr. Final state: prev->curr->...->prev.next->next->...
                while(curr != next) {
                    prev = curr;
                    curr = curr.next;
                }
                count = k;
            }
            else if(curr != null) {
                curr = curr.next;
            }
        }
        return dummyHead.next;
    }
    
    public ListNode reverse(ListNode before, ListNode head, ListNode after){
        ListNode curr = head;
        ListNode prev = after;
        while (curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        before.next = prev;
        return before;
    }
}