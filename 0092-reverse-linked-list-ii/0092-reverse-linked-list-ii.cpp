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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if(head==NULL || head->next==NULL) return head;    //if list contain only single node or no node
        ListNode *h1=head;
        ListNode *x = head;
        ListNode *x1=head,*x2=head;
        int n = 0;
        while(x!=NULL) {
            n++;
            x=x->next;
        }
        if(left==n) return head;   //if left position is equal to size 
        int i=1;
        while(i<left) {      //assining left position
            x1 = h1;
            h1=h1->next;
            i++;
        }
        ListNode *t1=head;
        if(right<n) {        //assigning right position
            i=1;
            while(i<right){
                t1=t1->next;
                i++;
            }
            x2=t1->next;
            t1->next=NULL;
        }
        ListNode *t = NULL, *p=NULL;
        ListNode *temp = h1;
        while(h1!=NULL)       //reversing from left positin to right position
        {
            t=h1->next;
            h1->next=p;
            p=h1;
            h1=t;
        }
        h1=p;
        while(p->next != NULL)
            p=p->next;
        if(left!=1)
        {
            x1->next=h1;
            if(right != n)
                temp->next = x2;
            return head;
        }
        if(right != n)
                temp->next = x2;
        return h1;
    }
};