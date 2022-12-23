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
    vector<int> ans;
    void solve(TreeNode* node) {
        if(node != NULL) {
            ans.push_back(node->val);
            solve(node->left);
            solve(node->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        solve(root);
        return ans;
    }
};