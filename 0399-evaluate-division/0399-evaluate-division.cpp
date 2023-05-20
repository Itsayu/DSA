class Solution {
unordered_map<string, unordered_map<string, double>> edges; 
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans; ans.reserve(queries.size());
        int m = equations.size(); 
        for(int i = 0; i < m; i++){
            edges[equations[i][0]][equations[i][1]] = values[i]; 
            edges[equations[i][1]][equations[i][0]] = 1 / values[i]; 
        }
        unordered_set<string> visited;
        for(int i = 0; i < queries.size(); i++){
            if(edges.count(queries[i][0]) == 0 or edges.count(queries[i][1]) == 0){
                ans.push_back(-1);
                continue;
            }
            visited.insert(queries[i][0]); 
            ans.push_back(dfs(queries[i][0], queries[i][1], visited));
            visited.clear();
        }
        return ans;
    }

    double dfs(const string &pos, const string &target, unordered_set<string> &visited){
        if(pos == target)
            return 1;
        visited.insert(pos);
        for(const auto &[nxt, w]: edges[pos])
        {
            if(not visited.count(nxt))
            {
                double res = dfs(nxt, target, visited);
                if(res != -1.0)
                    return res * w;
            }
        }
        return -1.0;

        
    }
};