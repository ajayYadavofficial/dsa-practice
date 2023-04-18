/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        // int level= 0;
        
        while(!q.empty()){
            int s = q.size();
            vector<Node*> level_nodes;
            for(int i=0; i<s;i++){
                Node* node = q.front();
                q.pop();
                level_nodes.push_back(node);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            // level ++;
            // for( auto it : level_nodes) cout<<it->val<<" ";
            // cout<<endl;
            // cout<<level<<endl;
            for(int i=0;i<level_nodes.size(); i++){
                if(i == level_nodes.size()-1 ){
                    level_nodes[i]->next = NULL;
                }
                else
                level_nodes[i]->next = level_nodes[i+1];
            }
        }
        return root;
    }
};