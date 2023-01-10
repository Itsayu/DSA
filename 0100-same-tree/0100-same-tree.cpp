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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> nr;
        nr.push({p, q});
        while (!nr.empty()) {
            auto [node1, node2] = nr.top();
            nr.pop();
            if (!node1 && !node2)
                continue;
            if (!node1 || !node2 || node1->val != node2->val)
                return false;
            nr.push({node1->left, node2->left});
            nr.push({node1->right, node2->right});
        }
        return true;
    }
};