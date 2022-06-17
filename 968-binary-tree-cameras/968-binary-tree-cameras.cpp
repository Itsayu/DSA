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
    int ans=0;
    int recur(TreeNode*root){
        if(root==NULL)
            return 0;
        int l=recur(root->left);
        int r=recur(root->right);
        if(l==-1||r==-1){ 
            ans++;
            return 1;
        }
        else if(l==0&&r==0) 
            return -1;
        return 0;
    }
    int minCameraCover(TreeNode*root) {
        if(recur(root)==-1)ans++;   
        return ans;
    }
};