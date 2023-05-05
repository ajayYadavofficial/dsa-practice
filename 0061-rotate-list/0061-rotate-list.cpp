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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        int size = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            size++;
        }
        cout<<size;
        int mv = k % size;
        if(mv == 0) return head;
        
        int pos = size-mv-1;
        temp = head;
        while(pos){
            temp = temp->next;
            pos--;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;
        temp = newHead;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = head;
        
        return newHead;
    }
};