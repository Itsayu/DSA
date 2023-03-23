class Solution {
public:
    void dfs(vector<vector<int>>&g,int s,vector<int>&vis){
        if(vis[s])return;
        vis[s] = 1;
        for(auto x:g[s]){
            dfs(g,x,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1>connections.size())return -1;
        vector<vector<int>> g(n);
        for(auto x:connections){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        vector<int> vis(n,0);
        int cnt = 0;
        for(int i=0;i<n;++i){
            if(!vis[i]){
                dfs(g,i,vis);
                cnt += 1;
            }
        }
        return cnt-1; 
    }
};