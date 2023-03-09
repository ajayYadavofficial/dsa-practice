/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
  ListNode *slow = head;
        ListNode *fast = head;
        boll isPresent = false;
        while( fast->next != NULL || fast != NULL){
            if(slow == fast ) {isPresent = true; break;}
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(!isPresent)return NULL;
 */


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        map<ListNode*, int> mp;
        ListNode* st = head;
        while(st != NULL){
            mp[st] ++;
            st = st->next;
            if(mp[st] == 2) return st;
        }
        return NULL;
    }
};