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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        vector<vector<int>> ans;
        q.push({root,{0,0}});
        map<int , map<int, multiset<int>>> mp;
        while(!q.empty()){
            for(int i=0; i< q.size(); i++){
                auto it = q.front();
                TreeNode* curr = it.first;
                int x_pos = it.second.first;
                int y_pos = it.second.second;
                mp[x_pos][y_pos].insert(curr->val);
                q.pop();
                if(curr->left) q.push({curr->left,{x_pos-1, y_pos+1}});
                if(curr->right) q.push({curr->right,{x_pos+1, y_pos+1}});  
            } 
        }
        for(auto it : mp){
            vector<int> col;
            for(auto it2 : it.second){
                col.insert(col.end(), it2.second.begin(),it2.second.end() );
            }
            ans.push_back(col);
        }
        return ans; 
    }
};