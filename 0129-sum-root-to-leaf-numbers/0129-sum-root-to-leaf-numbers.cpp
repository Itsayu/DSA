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
    void solve(TreeNode* curr, int& totalSum, int numTillParent)
    {
        if (curr == NULL) return;
        
        int numTillCurr = (numTillParent * 10) + (curr->val);
        if (curr->left == NULL && curr->right == NULL)  //leaf node
        {
            totalSum += numTillCurr;
            return; 
        }
        solve(curr->left, totalSum, numTillCurr);
        solve(curr->right, totalSum, numTillCurr);
    }
    int sumNumbers(TreeNode* root) 
    {
        int totalSum = 0;
        solve(root, totalSum, 0);
        return (totalSum); 
    }
};