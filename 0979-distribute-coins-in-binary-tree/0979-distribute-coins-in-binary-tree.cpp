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
    int distributeCoins(TreeNode* root)
    {
        if(!root)
            return 0;
        int count_moves = 0;
        if(root->left)
        {
            count_moves += distributeCoins(root->left) + abs(root->left->val - 1);
            root->val += root->left->val - 1;
            root->left->val = 1;
        }
        if(root->right)
        {
            count_moves += distributeCoins(root->right) + abs(root->right->val - 1);
            root->val += root->right->val -1;
            root->right->val = 1;
        }
        return count_moves;
    }
};