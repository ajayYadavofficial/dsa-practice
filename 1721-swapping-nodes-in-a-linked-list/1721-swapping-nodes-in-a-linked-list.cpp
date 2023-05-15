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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* t1 = head; // mark node from First Kth
        ListNode* t2 = head;// traversing 
        ListNode* t3 = head;// marking Node from Last Kth
        
        for(int i=1; i<=k-1; i++){
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t2->next != NULL){
            t2 = t2->next;
            t3 = t3->next;
        }
        // cout<<t1->val<<" "<<t3->val<<" "<<t2->val<<endl;
        int temp = t1->val;
        t1->val = t3->val;
        t3->val = temp;
        // swap(t1,t3);
        return head;
    }
};