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
    int pairSum(ListNode* head) {
        vector<int> list;
        ListNode* temp = head;
        while(temp != NULL){
            list.push_back(temp->val);
            temp = temp->next;
        }
        int ans = INT_MIN;
        for(int i=0; i<list.size()/2; i++){
            int sum = list[i] + list[list.size()-1-i];
            ans = max(ans,sum);
        }
        return ans;
    }
};