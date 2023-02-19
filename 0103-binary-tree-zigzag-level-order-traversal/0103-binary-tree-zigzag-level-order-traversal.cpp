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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        //strating from even level
        int isLevelEvenOrOdd = 0;
        q.push(root);
        while (!q.empty()) {
            int nodesInLevel = q.size();
            vector<int> tempVec;
            while (nodesInLevel--) {
                TreeNode* temp = q.front();
                q.pop();
                if (isLevelEvenOrOdd % 2 == 0) 
                    tempVec.push_back(temp -> val);
                else 
                    tempVec.insert(tempVec.begin(), temp -> val);
                    
                if (temp -> left != nullptr)
                    q.push(temp -> left);
                if (temp -> right != nullptr)
                    q.push(temp -> right);
            }   
            isLevelEvenOrOdd++;
            ans.push_back(tempVec);
        }
        return ans;
    }
};
