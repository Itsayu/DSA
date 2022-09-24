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
    void inorder(TreeNode* root,vector<int>&res,vector<vector<int>>&v,int s,int t){
        if(!root)
            return;
        s+=root->val;
        res.push_back(root->val);
        if((!root->left && !root->right) && s==t )
            v.push_back(res);
        inorder(root->left,res,v,s,t);
        inorder(root->right,res,v,s,t);
        res.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>v;
        vector<int>res;
        inorder(root,res,v,0,targetSum);
        return v;
    }
};