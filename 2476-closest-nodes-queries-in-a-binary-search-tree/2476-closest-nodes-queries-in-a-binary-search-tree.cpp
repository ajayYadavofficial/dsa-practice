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
    int lowerBound(vector<int> &arr,int num){
        int s=0,e=arr.size()-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(arr[mid]<=num){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return e;
    }
    int upperBound(vector<int> &arr,int num){
        int s=0,e=arr.size()-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(arr[mid]>=num){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return s;
    }
    void inorderedTraversal(TreeNode *root,vector<int> &arr){
        if(!root) return;
        inorderedTraversal(root->left,arr);
        arr.push_back(root->val);
        inorderedTraversal(root->right,arr);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> arr;
        // finding inordered traversal
        inorderedTraversal(root,arr);
        vector<vector<int>> ans;
        // processing queries
        for(int i=0;i<queries.size();i++){
            int x = lowerBound(arr,queries[i]);
            int y = upperBound(arr,queries[i]);
            if(x>=0 && x<arr.size() && arr[x]<=queries[i]) x = arr[x];
            else x = -1;
            if(y>=0 && y<arr.size() && arr[y]>=queries[i]) y = arr[y];
            else y = -1;
            // cout<<x<<" "<<y<<"\n";
            ans.push_back({x,y});
        }
        return ans;
    }
};