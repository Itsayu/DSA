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
    int mini = INT_MAX ;
    int minDiffInBST(TreeNode* root) {
        vector<int> ds ;
        func(root,ds) ;
        sort(ds.begin(),ds.end()) ;
        for(int i = 0 ; i < ds.size()-1 ; i++){
            mini = min(mini,ds[i+1]-ds[i]) ;
        }
        return mini ;
    }
    void func(TreeNode* root,vector<int>&ds){
        if(root == NULL)return ;
        ds.push_back(root->val) ;
        func(root->left,ds) ;
        func(root->right,ds) ;
        return ;
    }
};