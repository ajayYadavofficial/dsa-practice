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
    
    vector<TreeNode*> helper(int st, int end){
        
        vector<TreeNode*> list;
        if(st > end) {
            list.push_back(NULL);
            return list;
        }
        if(st == end){
            TreeNode* temp = new TreeNode(st);
            list.push_back(temp);
            return list;
        }
        
        for(int i=st; i<= end; i++){
            vector<TreeNode*> left = helper(st,i-1);
            vector<TreeNode*> right = helper(i+1, end);
            
            for(auto itL : left){
                
                for(auto itR : right){
                    TreeNode* root = new TreeNode(i);
                    root->left = itL;
                    root->right = itR;
                    list.push_back(root);
                }
                
            }
            
        }
        return list;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
};