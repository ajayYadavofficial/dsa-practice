class Solution {
public:
    unordered_map<int,int> l,r,ans;
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int le = height(root->left);
        int re = height(root->right);
        l[root->val] = le;                 // Storing maximum height in the left side of current node
        r[root->val] = re;                 // Storing maximum height in the right side of current node
        return max(le,re)+1;      
    }
    void fun(TreeNode* root,int MaxSoFar,int depth){
        if(root==NULL) return;

        ans[root->val] = MaxSoFar;
        fun(root->left,max(MaxSoFar,depth+r[root->val]),depth+1);
        fun(root->right,max(MaxSoFar,depth+l[root->val]),depth+1);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& q) {
        height(root);
        
        fun(root->left,r[root->val],1);               // Calling on left side and passing the maximum height of right side of root
        fun(root->right,l[root->val],1);              // Calling on right side and passing the maximum height of left side of root
        
        vector<int> res(q.size());
        for(int i = 0;i<q.size();i++){
            res[i] = ans[q[i]];
        }
        return res;
    }
};