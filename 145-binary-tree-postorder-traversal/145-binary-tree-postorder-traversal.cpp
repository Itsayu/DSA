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
   void postorder(TreeNode* root, vector<int> &ayu){
        if(root==NULL) return;
        
        postorder(root->left,ayu);
        postorder(root->right,ayu);
        ayu.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ayu;
        postorder(root,ayu);
        return ayu;
    }
};