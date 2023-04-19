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
public:
    int res = 0;

    int longestZigZag(TreeNode* root) {
        maxZigZag(1, 0, root);
        maxZigZag(0, 0, root);
        return res;
    }

    void maxZigZag(int isLeft, int cnt, TreeNode* root) {
        if(root == NULL) return;

        res = max(res, cnt);

        if(isLeft) {
            maxZigZag(0, cnt + 1, root->left);
            maxZigZag(1, 1, root->right);
        }
        else {
            maxZigZag(1, cnt + 1, root->right);
            maxZigZag(0, 1, root->left);
        }
    }
};