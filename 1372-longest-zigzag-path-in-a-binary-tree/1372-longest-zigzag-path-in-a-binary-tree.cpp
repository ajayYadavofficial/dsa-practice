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
// class Solution {
// public:
    
// //     bool dir if 1 then go right, if 0 go left
//     int maxZigZag(TreeNode* root, bool dir){
//         if(root == NULL) return 0;
//         int right = 0, left = 0;
//         if(!dir){
//             left = 1 + maxZigZag(root->left, 1);
//         }
//         if(dir){
//             right = 1 + maxZigZag(root->right, 0);
//         }
//         return left + right;
//     }
    
//     int longestZigZag(TreeNode* root) {
//         if(root == NULL) return 0;
        
//         int cnt_if_left = maxZigZag(root,0)-1;
//         int cnt_if_right = maxZigZag(root,1)-1;
        
//         int maxi = max(cnt_if_left,cnt_if_right);
//         int left = longestZigZag(root->left);
//         int right = longestZigZag(root->right);
//         return max({maxi,left,right});
        
//     }
// };


class Solution {
    int MAX;
    unordered_map<TreeNode*, vector<int>> dp;
public:
    int longestZigZag(TreeNode* root) {
        dp.clear();
        dfs(root);
        return MAX;
    }

    void dfs(TreeNode* root) {
        if (!root) return;

        if (!root->left && !root->right) {
            dp[root] = {0, 0};
            return;
        }

        dfs(root->left);
        dfs(root->right);

        int left = 0, right = 0;

        if (dp.find(root->left) != dp.end())
            left = 1 + dp[root->left][1];

        if (dp.find(root->right) != dp.end())
            right = 1 + dp[root->right][0];

        dp[root] = {left, right};
        MAX = max(MAX, max(left, right));
    }
};