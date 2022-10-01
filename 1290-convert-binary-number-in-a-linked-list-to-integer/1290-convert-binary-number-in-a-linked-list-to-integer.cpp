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
    int getDecimalValue(ListNode* head) {
        if(head == NULL) return 0;
        ListNode* temp = head;
        vector<int> nums;
        while(temp != NULL){
            nums.push_back(temp->val);
            temp = temp->next;
        }
        
        int ans = 0;
        int p = 0;
        for(int i = nums.size()-1; i>= 0;i--){
            // cout<<"i = "<<i;
            if(nums[i] == 1){
                int digi = int(pow(2,p));
                ans += digi;
            }
            p++;
        }
        
        return ans;
        
    }
};