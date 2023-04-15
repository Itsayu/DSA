class Solution {
public:
    int solve(int i,vector<vector<int>>& piles,vector<vector<int>>&dp,int k){
        if(k<=0)return 0;
        if(i>=piles.size())return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        int sum=0;
        int ans=0;
        int n=piles[i].size();
        int maxi=min(k,n);
        for(int j=0;j<=maxi;j++){
            if((j-1)>=0)sum+=piles[i][j-1];
            ans=max(ans,sum+solve(i+1,piles,dp,k-j));
        }
        return dp[i][k]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return solve(0,piles,dp,k);
    }
};