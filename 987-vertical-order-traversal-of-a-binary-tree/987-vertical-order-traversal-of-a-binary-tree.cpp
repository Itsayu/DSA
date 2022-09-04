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
    struct node { int val, row;  };
    vector<vector<node>> left {{}};
    vector<vector<node>> right;
    
    static bool nodeLessThan(const node &l, const node &r) {
        if (l.row == r.row)
            return l.val < r.val;
        return l.row < r.row;
    }
    
    void order(TreeNode *root, int x, int y) {
        if (!root) return;
        if (y < 0) {
            const int dy = std::abs(y);
            assert ((dy) <= left.size());
            if (dy == left.size())
                left.resize(dy + 1);
            left[dy].push_back({root->val, x});
            sort(left[dy].begin(), left[dy].end(), nodeLessThan);
        } else {
            assert (std::abs(y) <= right.size());
            if (y == right.size())
                right.resize(y + 1);
            right[y].push_back({root->val, x});
            sort(right[y].begin(), right[y].end(), nodeLessThan);
        }
        
        order(root->left, x + 1, y - 1);
        order(root->right, x + 1, y + 1);
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        order(root, 0, 0);
        left.erase(left.begin());
        std::reverse(left.begin(), left.end());
        
        vector<vector<int>> result;
        for (const auto & nodes : left) {
            if (nodes.empty()) continue;
            
            result.push_back({});
            for (const auto &node : nodes)
                result.back().push_back(node.val);
        }
        
        for (const auto & nodes : right) {
            if (nodes.empty()) continue;
            
            result.push_back({});
            for (const auto &node : nodes)
                result.back().push_back(node.val);
        }
            
        
        return result;    
    }
};