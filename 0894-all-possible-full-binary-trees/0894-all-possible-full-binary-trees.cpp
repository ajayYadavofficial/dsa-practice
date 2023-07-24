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
    
    vector<TreeNode*> solve(int n){
        if(n%2 == 0) return {};
        
        // top root node pr toh 2 children hona zaroori hai
        
        if(n == 1){
            TreeNode* root = new TreeNode(0);
            return {root};
        }
        
        vector<TreeNode*> result;
        for(int i = 1; i<n; i += 2){
            
            vector<TreeNode*> Left = solve(i);
            vector<TreeNode*> Right = solve(n-i-1);
            
            for(auto nodeL : Left){
                
                for(auto nodeR :Right ){
                    
                    TreeNode* newRoot = new TreeNode(0);
                    
                    newRoot->left = nodeL;
                    newRoot->right = nodeR;
                    
                    result.push_back(newRoot);
                }
                
            }
            
        }
        return result;
        
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        
        if(n%2 == 0) return {};
        
        return solve(n);
        
        
    }
};