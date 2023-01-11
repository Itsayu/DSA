class Solution {
public:
    int solve(int i,int par,vector<int> adj[], vector<bool>& hasApple){
        int ans=0;
        for(auto &nxt:adj[i]){
            if(nxt!=par){
                ans+=solve(nxt,i,adj,hasApple);
            }
        }
        if(ans==0){
            return hasApple[i]*2;
        }
        return ans+2;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(auto &edge:edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=0;
        for(int nxt:adj[0]){
            ans+=solve(nxt,0,adj,hasApple);
        }
        return ans;   
    }
};