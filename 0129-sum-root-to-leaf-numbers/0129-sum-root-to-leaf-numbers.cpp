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
    int sum  = 0;
    void helperSumNumbers(TreeNode*root, int currNum){
        if(root->left == NULL && root->right == NULL){
            // cout<<currNum<<" currNUm"<<endl;
            sum += currNum;
            currNum = 0;
            return ;
        }
        // cout<<sum<<endl;
        
        if(root->left) helperSumNumbers(root->left, currNum*10+root->left->val);
        // cout<<sum<<endl;
        if(root->right) helperSumNumbers(root->right,currNum*10+root->right->val);
        // cout<<sum<<endl;
        return;
        
    }
    
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        
        helperSumNumbers(root,root->val);
        return sum;
        
    }
};