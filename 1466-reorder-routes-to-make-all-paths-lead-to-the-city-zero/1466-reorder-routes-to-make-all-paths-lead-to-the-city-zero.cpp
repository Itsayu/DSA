class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int, int>> adj[n];
        for(auto it : connections){
            adj[it[1]].push_back({it[0], 0});
            adj[it[0]].push_back({it[1], 1});
        }
        int ans=0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<int> vis(n, 0);

        while(!q.empty()){
            int node = q.front().first;
            int cost = q.front().second;
            q.pop();
            ans += cost;
            vis[node] = 1;
            for(auto it : adj[node]){
                if(vis[it.first] == 0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};