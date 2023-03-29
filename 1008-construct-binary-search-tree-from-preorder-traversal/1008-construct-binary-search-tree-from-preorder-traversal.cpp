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
    TreeNode* func(vector<int>&p,int max,int &i,int min){
        if(i>=p.size()){
            return NULL;
        }
        cout<<p.size()<<" "<<i<<endl;
        if(p[i]<min || p[i]>max){
            return NULL;
        }

        TreeNode* root=new TreeNode(p.at(i));
        i++;
        root->left=func(p,p.at(i-1),i,min);
        root->right=func(p,max,i,p.at(i-1));
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int max=INT_MAX;
        int min=INT_MIN;
        int index=0;
        return func(preorder,max,index,min);
    }
};