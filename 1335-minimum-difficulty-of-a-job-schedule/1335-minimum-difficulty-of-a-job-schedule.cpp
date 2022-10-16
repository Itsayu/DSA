class Solution {
public:
    int dp[302][12];

int solve(vector<int>& a, int n, int d, int i){
    
    if(i >= n && d == 0) return 0;
    
    if(i >= n || d == 0) return 1e8;
      
    if(dp[i][d] != -1) return dp[i][d];
    
    int ans = 1e8, cur = 0;
    
    for(int ind = i;ind<n;ind++){
        
        cur = max(cur,a[ind]);
        ans = min(ans, solve(a,n,d-1,ind+1)+cur);
    }
    
    return dp[i][d] = ans; 
}

int minDifficulty(vector<int>& a, int d) {
    
    int n = a.size();
    memset(dp,-1,sizeof(dp));
    if(d > n) return -1;
    return solve(a,n,d,0);    
    }
};