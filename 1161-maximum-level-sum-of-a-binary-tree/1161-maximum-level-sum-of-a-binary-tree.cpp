/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = INT_MIN;
        int ansL = 0;
        int level = 1;
        while(!q.empty()){
            int s = q.size();
            int level_sum = 0;
            for(int i=0; i<s;i++){
                TreeNode* node = q.front();
                q.pop();
                level_sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level_sum > ans){
                ans = level_sum;
                ansL = level;
            }
            level++;
        }
        return ansL;
    }
};