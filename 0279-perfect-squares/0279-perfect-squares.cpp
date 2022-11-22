class Solution {
public:
    int numSquares(int n) {      
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=n;j++){
                int temp=j*j;
                if(i-temp>=0)
                    dp[i]=min(dp[i],dp[i-temp]+1);
            }
        }
        
        return dp[n];   
    }
};