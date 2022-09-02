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
    vector<double> averageOfLevels(TreeNode *root)
    {

        vector<double> res;
        if (root == NULL)
            return res;

        res.push_back(root->val);
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        double levelSum = 0;
        double levelCount = 0;

        while (!q.empty())
        {
            TreeNode *currNode = q.front();
            q.pop();

            if (currNode != NULL)
            {
                if (currNode->left != NULL)
                {
                    q.push(currNode->left);
                    levelSum += currNode->left->val;
                    levelCount++;
                }
                if (currNode->right != NULL)
                {
                    q.push(currNode->right);
                    levelSum += currNode->right->val;
                    levelCount++;
                }
            }

            if (q.front() == NULL)
            {
                q.pop();
                if (q.empty())
                    break;

                double sum = levelSum / levelCount;
                res.push_back(sum);
                levelSum = 0;
                levelCount = 0;

                q.push(NULL);
            }
        }

        return res;
    }
};