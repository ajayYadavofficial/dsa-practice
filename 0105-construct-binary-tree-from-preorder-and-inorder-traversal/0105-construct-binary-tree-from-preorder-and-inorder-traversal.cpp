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
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         if(preorder.size() == 0) return NULL;
//         int rootNode = preorder[0];
//         int rootIndx = find(inorder.begin(), inorder.end(), rootNode)-inorder.begin();
//         // cout<<rootIndx;
        
//         vector<int> leftPre, leftIn, rtPre, rtIn;
         
//         for(int i=0; i< rootIndx; i++){
//             leftIn.push_back(inorder[i]);
//         }
//         for(int i=rootIndx+1; i< inorder.size(); i++){
//             rtIn.push_back(inorder[i]);
//         }
        
//         for(int i=1; i<=rootIndx; i++){
//             leftPre.push_back(preorder[i]);
//         }
        
//         for(int i = rootIndx+1; i<preorder.size(); i++){
//             rtPre.push_back(preorder[i]);
//         }
        
//         TreeNode* leftNode = buildTree(leftPre, leftIn);
//         TreeNode* rightNode = buildTree(rtPre, rtIn);
        
//         TreeNode* root = new TreeNode(rootNode);
//         root->left = leftNode;
//         root->right = rightNode;
//         return root;
//     }
// };
class Solution {
public:
    int k = 0;
    TreeNode* solve(vector<int> &a,vector<int> &b,int s,int e){
        if(s>e){
            return NULL;
        }
        TreeNode* node = new TreeNode(a[k++]);
        int i;
        for(i = s; i<=e;i++){
            if(node->val == b[i]){
                break;
            }
        }
        node->left = solve(a,b,s,i-1);
        node->right = solve(a,b,i+1,e);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        k = 0;
        return solve(preorder,inorder,0,inorder.size()-1);
    }
};