class Solution {
public:
     int dp[1000][101];
    int rec(int i, int n, int k, vector<int> &p){
        if(i == n || k == 0)
            return 0;
        
        if(dp[i][k] != -1) 
            return dp[i][k];
        
        int ans = rec(i+1, n, k, p);
        
        for(int j=i+1; j<n; ++j){
            if(p[i] < p[j]){
                ans = max(ans, p[j] - p[i] + rec(j+1, n, k-1, p));
            }
        }
        
        return dp[i][k] = ans;
    }
    int maxProfit(int k, vector<int>& p) {
        memset(dp, -1, sizeof(dp));
        
        return rec(0, p.size(), k, p);   
    }
};