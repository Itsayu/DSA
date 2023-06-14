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
    int nr = INT_MAX;
    int num = -1;

int getMinimumDifference(TreeNode* root) {

    if (root->left != NULL)
        getMinimumDifference(root->left);

    if (num >= 0)
        nr = min(nr, root->val - num);

    num = root->val;

    if (root->right != NULL)
        getMinimumDifference(root->right);

      return nr;
    }
};