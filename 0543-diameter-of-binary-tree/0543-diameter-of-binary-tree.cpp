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
    int height(TreeNode* node, int &maxi){
        if(node == NULL){
            return 0;
        }
        
        int leftHeight = height(node->left, maxi);
        int rightHeight = height(node->right, maxi);
        maxi = max(maxi, (leftHeight+rightHeight));
        return 1 + max(leftHeight, rightHeight);
    }
    
    int diameterOfBinaryTree(TreeNode* root){
        // base case
        if(root == NULL){
            return 0;
        }
        
//         // diameter will of either of these:- either in left only, either in right only, either combination of both
        
//         int option1 = diameterOfBinaryTree(root->left); // either in left
        
//         int option2 = diameterOfBinaryTree(root->right); // either in right
        
//         int option3 = height(root->left) + height(root->right); // either combination of both
        
//         int ans = max(option1, max(option2, option3));
        int maxi = INT_MIN;
        int ht = height(root,maxi);
        return maxi;
    }
};