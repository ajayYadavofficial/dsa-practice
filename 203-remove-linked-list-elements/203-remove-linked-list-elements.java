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
    public ListNode removeElements(ListNode head, int val) {
        
                // base case
        if (head == null) {
            return null;
        }
        ListNode temp = head;
 // the logic is if temp.next has value equal to val then we just update the temp next
        while (temp != null) {
            if (temp.next != null && temp.next.val == val) {
                temp.next = temp.next.next;
            } else {
                temp = temp.next;
            }
        }
        // checking the head node
        if (head.val == val) {
            head = head.next;
        }
        return head;
    }
}