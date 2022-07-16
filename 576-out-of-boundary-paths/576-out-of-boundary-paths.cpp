class Solution {
public:
    int mod=(int)1e9+7;
    int f(int i,int j,int x,int &m,int &n,vector<vector<vector<int>>> &dp) {
        if (i<0||j<0||i==m||j==n) return 1;
        if (x==0) return 0;
        if (dp[i][j][x-1]!=-1) return dp[i][j][x-1];
        long long left=f(i,j-1,x-1,m,n,dp)%mod;
        long long right=f(i,j+1,x-1,m,n,dp)%mod;
        long long up=f(i-1,j,x-1,m,n,dp)%mod;
        long long down=f(i+1,j,x-1,m,n,dp)%mod;
        return dp[i][j][x-1]=(left+right+up+down)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove,-1)));
        return f(startRow,startColumn,maxMove,m,n,dp);
    }
};