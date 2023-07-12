class Solution {
public:
    int n; 
    vector<int> indeg;
    vector<vector<int>> adj;

    void adj_ini(vector<vector<int>>& graph){
        for(int i=0; i<n ; i++){
            for(int j=graph[i].size()-1; j>=0; j--){
                int v=graph[i][j];
                adj[v].push_back(i);
                indeg[i]++;
            }
        }
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        n=graph.size();
        indeg.assign(n, 0);
        adj.resize(n);
        adj_ini(graph);

        vector<bool> safe(n, 0);
        //The DFS part
        function<void(int)> dfs=[&](int i){
            safe[i]=1;
            for(int j:adj[i]){
                if (--indeg[j]==0 && !safe[j])
                    dfs(j);
            }
        };
        
        for(int i=0; i<n; i++)
            if (indeg[i]==0 && !safe[i])
                dfs(i);
        

        vector<int> ans;
        for(int i=0; i<n; i++)
            if (safe[i]) ans.push_back(i);
        return ans;
    }
};