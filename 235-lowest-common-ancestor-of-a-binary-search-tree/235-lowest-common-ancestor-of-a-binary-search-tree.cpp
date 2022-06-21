/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) 
            return NULL;
        int num=root->val;
        int n1=p->val;
        int n2=q->val;
        if(n1<num && n2<num){
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(n1>num && n2>num){
            return lowestCommonAncestor(root->right, p, q);
        }
        else{
            return root;
        }
    }   
};