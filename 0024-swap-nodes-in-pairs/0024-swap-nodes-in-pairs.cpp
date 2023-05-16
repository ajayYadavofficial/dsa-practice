/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* helper( ListNode* head){
        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* newHead = helper(head->next->next);
        ListNode* t1 = head;
        ListNode* t2 = head->next;
        // cout<<t1->val<<"  = t1  t2 == "<<t2->val<<endl;
        t1->next = newHead;
        t2->next = t1;
        
        return t2;
        
    }
    
    ListNode* swapPairs(ListNode* head) {
        return helper(head);
    }
};