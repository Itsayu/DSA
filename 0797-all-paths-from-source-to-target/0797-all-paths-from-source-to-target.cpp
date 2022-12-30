class Solution {
public:
    static vector<vector<int>> allPathsSourceTarget(const vector<vector<int>>& graph) {
        const int n = size(graph);
        vector<vector<int>> ans;
        vector<int> path;
        path.reserve(n);
        path.push_back(0);
        dfs(graph, 0, n - 1, path, ans);
        return ans;
    }
    
    static void dfs(const vector<vector<int>>& graph, int start, int end, vector<int>& path,
            vector<vector<int>>& ans) {
        if (start == end) {
            ans.push_back(path);
            return;
        }
        
        for (int next : graph[start]) {
            path.push_back(next);
            dfs(graph, next, end, path, ans);
            path.pop_back();
        }
    }
};