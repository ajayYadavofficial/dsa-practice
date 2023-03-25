/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int countNodes(TreeNode root) {
        int LH=leftHeight(root);
        int RH=rightHeight(root);
        if(LH==RH){
            return (int)(Math.pow(2,LH))-1; //if both height are are equal then no of nodes are (2^h-1)
        }
        else{
            return 1+countNodes(root.left)+countNodes(root.right);
        }
    }
    public int leftHeight(TreeNode root){
        if(root==null){
            return 0;
        }
        else{
            return 1+leftHeight(root.left);
        }
    }
    public int rightHeight(TreeNode root){
        if(root==null){
            return 0;
        }
        else{
            return 1+rightHeight(root.right);
        }
    }
}