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
    void findgoodNodes(TreeNode * root, int max, int & res){
        if(root==NULL) return ;
        if(root->val>=max) {
            res++;
            max=root->val;
        }
        findgoodNodes(root->left,max,res);
        findgoodNodes(root->right,max,res);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int max= root->val;
        int res=0;
        findgoodNodes(root,max,res);
        return res;
    }
};