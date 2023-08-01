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
    
    int solve(TreeNode* root, int &maxi){
        if(root == NULL) return 0;
        
        
        int Lh = solve(root->left, maxi);
        int Rh = solve(root->right, maxi);
        
        maxi = max(maxi, Lh + Rh);
        
        return 1 + max(Lh, Rh);
        
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        solve(root, maxi);
        return maxi;
    }
};