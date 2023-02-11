class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto edge : redEdges) {
            graph[edge[0]].push_back({edge[1], -1});
        }
        for(auto edge : blueEdges) {
            graph[edge[0]].push_back({edge[1], 1});
        }
        vector<int> ans(n, -1);
        queue<pair<int, int>> Q;
        Q.push({0, 0});
        int level = 0;
        unordered_set<string> visited;
        while(!Q.empty()) {
            int c = Q.size();
            while(c--) {
                pair<int, int> curr = Q.front();
                Q.pop();
                if(ans[curr.first] == -1)
                    ans[curr.first] = level;
                for(auto child : graph[curr.first]) {
                    string key = to_string(child.first) + "_" + to_string(child.second);
                    if(curr.second != child.second && visited.find(key) == visited.end()) {
                        Q.push({child});
                        visited.insert(key);
                    }
                }
            }
            level++;
        }

        return ans;  
    }
};