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
  ListNode* rev(ListNode* head) {
          if(head==NULL)
            return NULL;
    ListNode*curr=head;
    ListNode*prev=NULL;
    ListNode*nex=NULL;
        while(curr!=NULL){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    ListNode*rev2(ListNode*head){
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode*newhead=rev2(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;
    }
    ListNode* solve(ListNode* head1, ListNode* head2) {
          int car=0;
    ListNode*p=new ListNode(9);
        ListNode*ans=p;
    while(head1!=NULL||head2!=NULL||car>0){
        int sum=car;
        if(head1!=NULL){
            sum+=head1->val;
            head1=head1->next;
        }
        if(head2!=NULL){
            sum+=head2->val;
            head2=head2->next;
        }
        int v=sum%10;
        car=sum/10;
        ans->next=new ListNode(v);
        ans=ans->next;
    }
    return p->next;;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*l1rev=rev(l1);
        ListNode*l2rev=rev2(l2);
        ListNode*res=solve(l1rev,l2rev);
        return rev(res);
    }
};