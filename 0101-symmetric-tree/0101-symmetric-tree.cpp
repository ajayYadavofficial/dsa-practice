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
    
    bool helpSymmetric(TreeNode* root1, TreeNode* root2){
        
        if(root1 == NULL || root2 == NULL){
            return root1==NULL && root2==NULL;
        }
        else if(root1->val == root2->val){
            return helpSymmetric(root1->left,root2->right) && helpSymmetric(root1->right, root2->left);  
        }
        else return false;
        
    }
    
    bool isSymmetric(TreeNode* root) {
        
        if(root->left == NULL && root->right == NULL) return true;
        if(root->left != NULL && root->right == NULL) return false;
        if(root->left == NULL && root->right != NULL) return false;
        
        // if there is a right child and a left chile exists
        return helpSymmetric(root->left, root->right);
    }
};