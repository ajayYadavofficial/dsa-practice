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
    
      void solve(TreeNode* root,int val,int depth){
        if(!root)return ;
        if(depth==1){
            TreeNode* temp1=new TreeNode(val);
            TreeNode* temp2=new TreeNode(val);
            temp1->left=root->left;
            temp2->right=root->right;
            
            root->left=temp1;
            root->right=temp2;
            return ;
        }
        solve(root->left,val,depth-1);
        solve(root->right,val,depth-1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            
            return temp;
        }
        depth--;
        solve(root,val,depth);
        
        return root;
    }
};