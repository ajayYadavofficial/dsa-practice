/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    unordered_map<TreeNode*, TreeNode*> mp;
    void markParents(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i =0; i< size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    mp[node->left] = node;
                }
                if(node->right){
                    q.push(node->right);
                    mp[node->right] = node;
                }
            }
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        markParents(root);
        unordered_map<TreeNode*, bool> visited;
        vector<int>ans;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = 1;
        int curr_level = 0;
        
        while(!q.empty()){
            int s = q.size();
            if(curr_level++ == k) break;
            for(int i=0; i<s; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = 1;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = 1;
                }
                if(mp[node] && !visited[mp[node]]){
                    q.push(mp[node]);
                    visited[mp[node]] = 1;
                }
            }
        }
        while( !q.empty()){
            TreeNode* node = q.front(); q.pop();
            ans.push_back(node->val);
        }
        
        return ans;
    }
};