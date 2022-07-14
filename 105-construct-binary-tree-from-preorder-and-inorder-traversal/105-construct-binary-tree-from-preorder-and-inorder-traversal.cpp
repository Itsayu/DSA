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
    int ayu=0;
    int search(vector<int> &inorder, int curr, int start, int end){
        while(start <= end){
            if(inorder[start]==curr)
                return start;
                start++;
        }
        return -1;
        }
    TreeNode* constructTree(vector<int> &preorder, vector<int> &inorder, int start, int end){
        if(start>end)
            return NULL;
        int curr=preorder[ayu++];
        TreeNode *node=new TreeNode(curr);
        int pos=search(inorder, curr, start, end);
        node->left=constructTree(preorder, inorder, start, pos-1);
        node->right=constructTree(preorder, inorder, pos+1, end);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode *node=constructTree(preorder, inorder, 0, inorder.size()-1);
    return node;
    }
};