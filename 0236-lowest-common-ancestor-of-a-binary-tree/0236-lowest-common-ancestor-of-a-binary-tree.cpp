/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL) return NULL;
        
        if(root == p || root == q) return root;
        
        TreeNode* ansL = lowestCommonAncestor(root->left, p, q);
        TreeNode* ansR = lowestCommonAncestor(root->right, p, q);
        // TreeNode * ans;
        if(ansL == NULL) return ansR;
        else if(ansR == NULL) return ansL;
        else 
        return root;
        
    }
};