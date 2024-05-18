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
    int func(TreeNode* root){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->val-1;
        int p=func(root->left);
        int q=func(root->right);
        ans+=(abs(p)+abs(q));
        return root->val-1+p+q;
    }
    int distributeCoins(TreeNode* root) {
        func(root);
        return ans;
    }
};