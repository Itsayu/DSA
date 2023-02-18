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
    TreeNode* invertTree(TreeNode* root){
    if(nullptr == root) return root;
    queue<TreeNode*> myQueue; 
    myQueue.push(root); 
    while(!myQueue.empty()){ 
        TreeNode *node = myQueue.front();  
        myQueue.pop();  
        if(node->left != nullptr){
            myQueue.push(node->left);
        }
        if(node->right != nullptr){  
            myQueue.push(node->right);
        }     
        TreeNode* tmp = node->left;
        node->left = node->right;
        node->right = tmp;
    }
    return root;
    }
};