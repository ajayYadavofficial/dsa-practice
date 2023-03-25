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
    TreeNode* searchBST(TreeNode* root, int val) {
        
       if(root->val==val)
       {
           return root;
       }
       TreeNode* tmp=root;

       while(tmp!=NULL)
       {
           if(tmp->val>val)
           {
               tmp=tmp->left;
           }
           else if(tmp->val<val)
           {
               tmp=tmp->right;
           }
           else
           {
               return tmp;
           }
       }
       TreeNode* nULL=NULL;
       return nULL;
    }
};