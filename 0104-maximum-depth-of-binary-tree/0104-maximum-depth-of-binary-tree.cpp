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
    
    int helper(TreeNode* root){
        
        if(root == NULL) return 0;
        
        int left = -1e8, right = -1e8;
        
        left = 1 + helper(root->left);
        
        right = 1 + helper(root->right);
        
        return max(left,right);
        
    }
    int maxDepth(TreeNode* root) {
        return helper(root);
    }
};