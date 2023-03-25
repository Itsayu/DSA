class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<long long>>& adj, long long &count)
    {
        vis[node] = 1;
        for(auto i: adj[node])
        {
            if(!vis[i])
            {
                count++;                
                dfs(i, vis, adj, count);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<long long>> adj(n);
        vector<int> vis(n, 0);
        for(int i=0; i<edges.size(); i++)
        {
            long long u = edges[i][0];
            long long v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long totalVisNode = 0;
        long long ans = 0;
        for(int i=0; i<n; i++)
        {  
            if(!vis[i])
            {  
                long long count = 1;
                dfs(i, vis, adj, count);
                totalVisNode = count + totalVisNode;
                long long leftNode = n - totalVisNode;
                ans = ans + (leftNode*count);
            }
        }
        return ans;
    }
};