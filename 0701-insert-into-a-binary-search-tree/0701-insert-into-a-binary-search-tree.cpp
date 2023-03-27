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
    
    void helper( TreeNode* root, TreeNode* prev, int val){
        if(root == NULL){
            TreeNode* node = new TreeNode(val);
           if(prev->val > val){
               
               prev->left = node;
           }else {
               prev->right = node;
           }
            return;
       } 
        
        if( root->val < val){
             helper(root->right,root ,val);
        }
        else {
             helper(root->left, root,val);
        }
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
      if(root == NULL){
          TreeNode* node = new TreeNode(val);
          root = node;
          return root;
      }
        helper(root, NULL, val);
        return root;
        
    }
};