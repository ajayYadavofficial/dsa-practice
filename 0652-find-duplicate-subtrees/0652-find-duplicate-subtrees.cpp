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
    
    map<string, int> mp;
    
    string solve(TreeNode* root, vector<TreeNode*> &vec  ){
        if( root == NULL) return "#";
        
        string s = solve(root->left, vec) + ',' + solve(root->right, vec)+','+ to_string(root->val);
        mp[s]++;
        
        if( mp[s] == 2){
            vec.push_back(root);
        }
        return s;
        
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> vec;
        solve(root,vec);
        return vec;
    }
};