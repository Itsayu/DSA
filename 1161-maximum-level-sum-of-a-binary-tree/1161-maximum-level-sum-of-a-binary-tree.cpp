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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans=1;
        int Sum=INT_MIN;
        int level=0;
        while(!q.empty()){
            level++;
            int size=q.size();
            int sum=0;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                sum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
            }
            if(sum>Sum){
                Sum=sum;
                ans=level;
            }
        }
        return ans;
    }
};