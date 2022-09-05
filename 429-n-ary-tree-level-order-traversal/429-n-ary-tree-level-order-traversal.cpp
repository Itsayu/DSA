/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        int i;
        queue<Node*> q;
        q.push(root);
        if(!root)return ans;
        while(!q.empty()){
            vector<int> list;
            int size = q.size();
            i = 0;
            while(i < size){
                Node *temp = q.front();
                q.pop();
                list.push_back(temp->val);
                for(auto j : temp->children){
                    q.push(j);
                }
                i++;
            }
            ans.push_back(list);
        }
        return ans;    
    }
};