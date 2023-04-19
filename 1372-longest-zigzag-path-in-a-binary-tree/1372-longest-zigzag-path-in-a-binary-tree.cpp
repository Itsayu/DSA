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
    int longestZigZag(TreeNode* root) {
        int ans = -1;
        pair<int, int> p;
        p = calc(root,ans);
        return ans;
    }
    pair<int, int> calc(TreeNode* root, int &ans){
        if(root == NULL) return{-1,-1};
        pair<int, int> left = calc(root->left, ans);
        pair<int, int> right = calc(root->right, ans);
        int temp = 1+ max(left.second, right.first);
        ans = max(temp, ans);
        return{1+left.second, 1+right.first};
    }
};