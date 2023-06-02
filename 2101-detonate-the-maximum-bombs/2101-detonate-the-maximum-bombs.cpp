class Solution {
public:
    void dfs(int i, int &count, vector<bool> &visited, vector<vector<int>> &adj){
        visited[i] = true;
        count++;
        for(auto it : adj[i])
        {
            if(!visited[it])
            dfs(it, count, visited, adj);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
       int n = bombs.size();
       vector<vector<int>> adj(n);
       for(int i=0; i<n; i++){
           long long r1 = bombs[i][2];
           long long x1 = bombs[i][0], y1 = bombs[i][1];
           for(int j = 0; j<n; j++){
             if(j != i){
                 long long x2 = bombs[j][0], y2 = bombs[j][1];
                 long long dist = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
                 if(dist <= r1*r1)
                 adj[i].push_back(j);
             }
           }
       }
       vector<bool> visited(n, 0);
       int ans = 0;
       for(int i=0; i<n; i++)
       {
           int count = 0;
           dfs(i, count, visited, adj);
           ans = max(ans, count);
           fill(visited.begin(), visited.end(), 0);
       } 
       return ans;
    }
};