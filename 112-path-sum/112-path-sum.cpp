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
    bool hasPathSum(TreeNode* root, int targetSum) {
    
    if(root == nullptr){
          return false;
    }
//         we are at leaf node
    if(root->left == nullptr && root->right == nullptr){
        
        return (targetSum - root->val) == 0;
      
    }
      
    bool left = hasPathSum(root->left, (targetSum - root->val) );
    bool right = hasPathSum(root->right, (targetSum - root->val));
        
    return left || right;
        
    }
};