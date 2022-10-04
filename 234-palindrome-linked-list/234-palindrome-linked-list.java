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
     public boolean isPalindrome(ListNode head) {
        ListNode temp=head;
        ListNode mid=middleNode(head);
        ListNode rev=reverse(mid);
        while(temp!=null && temp.next!=null){
            if(temp.val!=rev.val){
                return false; 
            }
            temp=temp.next;
            rev=rev.next;
            
        }
        return true;
    }
    
     public ListNode middleNode(ListNode head) {
        ListNode slow=head;
        ListNode fast=head;
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }
    
    public ListNode reverse(ListNode head){
        if(head==null || head.next==null){
            return head;
        }
        ListNode prev=null;
        ListNode curr=head;
        ListNode forw=null;
        while(curr!=null){
            forw=curr.next;
            curr.next=prev;
            prev=curr;
            curr=forw;
        }
        head=prev;
        return head;
    }
}