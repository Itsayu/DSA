class Solution {
public:
    int mod=1e9+7;
    int dfs(int i,int j,int prev,vector<vector<int>>&dp,vector<vector<int>>&v){
        int n=v.size(),m=v[0].size();
        if(i<0 || j<0 || i>=n || j>=m || v[i][j]<=prev)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=(1+dfs(i+1,j,v[i][j],dp,v)+dfs(i-1,j,v[i][j],dp,v)+dfs(i,j+1,v[i][j],dp,v)+dfs(i,j-1,v[i][j],dp,v))%mod;
    }
    int countPaths(vector<vector<int>>&v) {
        int i,j,n=v.size(),m=v[0].size(),ans=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                ans=(ans+dfs(i,j,-1,dp,v))%mod;
            }
        }
        return ans;
    }
};