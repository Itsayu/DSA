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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL) return NULL;
        if(root->left==NULL && root->right==NULL){ 
            if(root->val==target){
                return NULL;
            }
            else return root;
        }//although this is unnecessary but writing this makes the solution look simpler.
        root->left=removeLeafNodes(root->left,target);
        root->right=removeLeafNodes(root->right,target);
        if(root->left==NULL && root->right==NULL && root->val==target){ //after working on left and right chlid if both become null then the current node becomes leaf so check for it again
            return NULL;
        }
        return root;
    }
};