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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        int level= 0,lev=0;vector<int>temp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(q.size()){
            auto it = q.front();q.pop();
            if(it.second>lev) ans.push_back(temp),temp.clear(),lev++;
            if(it.first->left) q.push({it.first->left,it.second+1});
            if(it.first->right) q.push({it.first->right,it.second+1});
            temp.push_back(it.first->val);
        }
        ans.push_back(temp);
        return ans;
    }
};