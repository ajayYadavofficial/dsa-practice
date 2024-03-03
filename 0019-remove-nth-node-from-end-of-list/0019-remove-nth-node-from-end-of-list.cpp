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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        ListNode* prevTemp = temp1;
        n = n-1;
        
        while(n--) temp2 = temp2->next;
        if(temp2->next == NULL ){ head = head->next; return head;}
        while(temp2->next != NULL) {
            prevTemp = temp1;
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        
        prevTemp->next = temp1->next;
        
        return head;
        
    }
};